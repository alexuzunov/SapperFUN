
/* Reader for I2C Protocol 
 * Sherwin Chiu 
 * Nov 19th, 2019
 */
 
#include <Wire.h> // built in Arduino library

void setup(){
  Serial.begin(9600);
  Wire.begin(5);
  Wire.onReceive(receiveEvent);
}

void loop(){
}

void receiveEvent(int howMany){
  while(Wire.available())    // slave may send less than requested
  { 
    char c = Wire.read();    // receive a byte as character
    Serial.print(c);         // print the character
  }
} 
