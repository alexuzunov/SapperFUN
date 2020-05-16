
/* Sender for I2C Protocol 
 * Sherwin Chiu 
 * Nov 19th, 2019
 */
 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

SoftwareSerial SerialSend(11, 12); //RX, TX
LiquidCrystal_I2C lcd(0x3f,20,4);

void randomString() {
    randomSeed(analogRead(0));
    lcd.setCursor(0, 0);
    int randomValue, selection;
    String serialNumber = "";
    for (int i = 0; i < 6; i++) {
        if (i == 0 || i == 1) {
            randomValue = random(26)  + 65;
            serialNumber += char(randomValue);
        }
        else if (i >= 2 && i < 5) {
            selection = random(2);
            if (selection) {
                randomValue = random(10) + 48;
                serialNumber += char(randomValue);
            }
            else {
                randomValue = random(26) + 65;
                serialNumber += char(randomValue);
            }
        }
        else {
            randomValue = random(10) + 48;
            serialNumber += char(randomValue);
        }
    }
    //char convert[7];
    //serialNumber.toCharArray(convert, 7);
    //SerialSend.begin(9600);
    //SerialSend.write(convert);
    lcd.print(serialNumber);
}


void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  randomString();
}

void loop() {
  int minutes = 1;
  int seconds = 25;
  int convertedTime = minutes * 60 + seconds + 1; 
  int single = 0;
  if (millis() / 1000 <= convertedTime){
    int baseTime = convertedTime - millis() / 1000;
    SerialSend.begin(115200);
    SerialSend.write(baseTime);
    lcd.setCursor(15, 0);
    lcd.print(baseTime / 60);
    lcd.setCursor(16, 0);
    lcd.print(":");
    if (baseTime % 60 < 10){
      lcd.setCursor(18, 0);
      lcd.print(baseTime % 60);
      lcd.setCursor(17, 0);
      lcd.print(single);
    }
    else{
      lcd.setCursor(17, 0);
      lcd.print(baseTime % 60);
    }
  }
}
