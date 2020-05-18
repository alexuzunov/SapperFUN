#define dataPin 10  // blue wire to 74HC164 pin 14
#define clockPin 13 // yellow to 74HC164 pin 11
#define latchPin 4
#define digit1 9
#define digit2 8
#define digit3 7
#define digit4 6
#define digit5 5
/*LSBFIRST
0 252
1 96
2 218
3 242
4 102
5 182
6 190
7 224
8 254
9 246*/

int decimalSignatures[10] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246};

 
void displayNumber(long int n) {
  int tenThousands = (n / 10000) % 10;
  int thousands = (n / 1000) % 10;
  int hundreds = (n / 100) % 10;
  int tens = (n / 10) % 10;
  int unit = n % 10;

  digitalWrite(digit1, LOW);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, decimalSignatures[tenThousands]);
  digitalWrite(latchPin, HIGH);
  digitalWrite(digit1, HIGH);
  delay(1);

  digitalWrite(digit2, LOW);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, decimalSignatures[thousands]);
  digitalWrite(latchPin, HIGH);
  digitalWrite(digit2, HIGH);
  delay(1);

  digitalWrite(digit3, LOW);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, decimalSignatures[hundreds]);
  digitalWrite(latchPin, HIGH);
  digitalWrite(digit3, HIGH);
  delay(1);

  digitalWrite(digit4, LOW);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, decimalSignatures[tens]);
  digitalWrite(latchPin, HIGH);
  digitalWrite(digit4, HIGH);
  delay(1);

  digitalWrite(digit5, LOW);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, decimalSignatures[unit]);
  digitalWrite(latchPin, HIGH);
  digitalWrite(digit5, HIGH);
  delay(1);
}

void setup() {  
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  pinMode(digit5, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop(){
  displayNumber(99919);
}
