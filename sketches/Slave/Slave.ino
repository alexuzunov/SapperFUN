#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 12); //RX, TX
String output;
int pause = 1000;
unsigned long currentTime = 0;

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);
}

void loop() {
  if (millis() >= currentTime + pause){
    currentTime += pause;
    output = mySerial.read();
    Serial.println(output);  
  }
}
