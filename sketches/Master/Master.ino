
/* Sender for I2C Protocol 
 * Sherwin Chiu 
 * Nov 19th, 2019
 */

#include <Wire.h> // built in Arduino library
#include <LiquidCrystal_I2C.h>

using namespace std;

LiquidCrystal_I2C lcd(0x3f,20,4);

String randomString() {
    int randomValue, selection;
    String serialNumber = "";
    for (int i = 0; i < 6; i++) {
        if (i == 0 || i == 1) {
            randomValue = rand() % 26 + 65;
            serialNumber += char(randomValue);
        }
        else if (i >= 2 && i < 5) {
            selection = rand() % 2;
            if (selection) {
                randomValue = rand() % 10 + 48;
                serialNumber += char(randomValue);
            }
            else {
                randomValue = rand() % 26 + 65;
                serialNumber += char(randomValue);
            }
        }
        else {
            randomValue = rand() % 10 + 48;
            serialNumber += char(randomValue);
        }
    }
    return serialNumber;
}


void setup()
{
  Serial.begin(9600);
  Wire.begin();
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0, 0); 
  String generated = randomString();
  lcd.print(generated);
  Wire.beginTransmission(5);
  char convert[7];
  generated.toCharArray(convert, 7);
  Wire.write(convert);
  Wire.endTransmission();
}

void loop() {
  int minutes = 1;
  int seconds = 0;
  unsigned int convertedTime = minutes * 60 + seconds; 
  int single = 0;
  static int counter = 0;
  if (millis() / 1000 <= convertedTime){
    int baseTime = convertedTime - millis() / 1000;
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
