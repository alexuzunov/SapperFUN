#define dataPin 10  // blue wire to 74HC164 pin 14
#define clockPin 13 // yellow to 74HC164 pin 11
#define latchPin 4
#define digit1 9
#define digit2 8
#define digit3 7
#define digit4 6
#define digit5 5
#define dotLen 1000
#define dashLen 3000
#define elemPause 1000
#define letterPause 3000
#define spaces 300
#define wordPause 7000
#define LED A1

struct button {
  int buttonPin;
  int buttonState;
  int lastButtonState;
  unsigned long lastDebounceTime;
};
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
//int t0 = millis();
String car = "-.-. .- .-.";
//String full = "- . - .  . -  . - .";
//String currentWord = full;
struct button buttons[3];
int decimalSignatures[10] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246};
long int numbers[4] = {10000, 10001, 10002, 10003};
unsigned long debounceDelay = 50; 
unsigned long previousTimeSEVSEG = 0;
unsigned long previousTimeMorse = 0;
 
void displayNumber(long int n) {
  int tenThousands = (n / 10000) % 10;
  int thousands = (n / 1000) % 10;
  int hundreds = (n / 100) % 10;
  int tens = (n / 10) % 10;
  int unit = n % 10;

  unsigned long time1 = millis();
  digitalWrite(digit1, LOW);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, decimalSignatures[tenThousands]);
  digitalWrite(latchPin, HIGH);
  digitalWrite(digit1, HIGH);
  while (millis() < time1 + 1){
  }

  unsigned long time2 = millis();
  digitalWrite(digit2, LOW);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, decimalSignatures[thousands]);
  digitalWrite(latchPin, HIGH);
  digitalWrite(digit2, HIGH);
  while (millis() < time2 + 1){
  }

  unsigned long time3 = millis();
  digitalWrite(digit3, LOW);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, decimalSignatures[hundreds]);
  digitalWrite(latchPin, HIGH);
  digitalWrite(digit3, HIGH);
  while (millis() < time3 + 1){
  }

  unsigned long time4 = millis();
  digitalWrite(digit4, LOW);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, decimalSignatures[tens]);
  digitalWrite(latchPin, HIGH);
  digitalWrite(digit4, HIGH);
  while (millis() < time4 + 1){
  }

  unsigned long time5 = millis();
  digitalWrite(digit5, LOW);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, decimalSignatures[unit]);
  digitalWrite(latchPin, HIGH);
  digitalWrite(digit5, HIGH);
  while (millis() < time5 + 1){
  }
}

void setHigh() {
    unsigned long timeHigh = millis();
    digitalWrite(digit1, HIGH);
    digitalWrite(digit2, HIGH);
    digitalWrite(digit3, HIGH);
    digitalWrite(digit4, HIGH);
    digitalWrite(digit5, HIGH);
    while (millis() < timeHigh + 10){
    }
}

void debounce(struct button *button) {
  static int counter = 0;
  displayNumber(numbers[counter % 4]);
  if (button->buttonPin == A5){
    // read the state of the switch into a local variable:
    int reading = digitalRead(button->buttonPin);
  
    // check to see if you just pressed the button
    // (i.e. the input went from LOW to HIGH), and you've waited long enough
    // since the last press to ignore any noise:
  
    // If the switch changed, due to noise or pressing:
    if (reading != button->lastButtonState) {
      // reset the debouncing timer
      button->lastDebounceTime = millis();
    }
  
    if ((millis() - button->lastDebounceTime) > debounceDelay) {
      // whatever the reading is at, it's been there for longer than the debounce
      // delay, so take it as the actual current state:
  
      // if the button state has changed:
      if (reading != button->buttonState) {
        button->buttonState = reading;
  
        // only toggle the LED if the new button state is HIGH
        if (button->buttonState == HIGH) {
          counter++;
          setHigh();
        }
      }
    }
  
    // set the LED:
    //digitalWrite(button->ledPin, button->ledState);
  
    // save the reading. Next time through the loop, it'll be the lastButtonState:
    button->lastButtonState = reading;
  }
  else if (button->buttonPin == A4){
     int reading = digitalRead(button->buttonPin);
  
    // check to see if you just pressed the button
    // (i.e. the input went from LOW to HIGH), and you've waited long enough
    // since the last press to ignore any noise:
  
    // If the switch changed, due to noise or pressing:
    if (reading != button->lastButtonState) {
      // reset the debouncing timer
      button->lastDebounceTime = millis();
    }
  
    if ((millis() - button->lastDebounceTime) > debounceDelay) {
      // whatever the reading is at, it's been there for longer than the debounce
      // delay, so take it as the actual current state:
  
      // if the button state has changed:
      if (reading != button->buttonState) {
        button->buttonState = reading;
  
        // only toggle the LED if the new button state is HIGH
        if (button->buttonState == HIGH) {
          if (counter == 0) counter = 3;
          else counter--;
          setHigh();
        }
      }
    }
  
    // set the LED:
    //digitalWrite(button->ledPin, button->ledState);
  
    // save the reading. Next time through the loop, it'll be the lastButtonState:
    button->lastButtonState = reading;
  }
}

int getArrayLength(String ex){
  int counter = 0;
  for (int i = 0; i < ex.length(); i++){
    if (ex[i] == '.' || ex[i] == '-') {
      counter += 2;
    }
  }
  return counter;
}

long delaySum(String morse){
  long sum = 0;
  int pos;
  int i = 0, j = 0;
  long int numberCodes[getArrayLength(morse)];
  while (i < morse.length()){
    if (i == morse.length() - 1){
      if (morse[i] == '.'){
        numberCodes[j] = dotLen;
      }
      else if (morse[i] == '-'){
        numberCodes[j] = dashLen;
      }
      numberCodes[j + 1] = wordPause; 
      i++; 
      j += 2;
    }
    else if (morse[i] == '.') {
      numberCodes[j] = dotLen;
      if (morse[i + 1] == ' '){
        numberCodes[j + 1] = letterPause;
      }
      else {
        numberCodes[j + 1] = elemPause;
      }
      i++;
      j += 2;  
    }
    else if (morse[i] == '-'){
      numberCodes[j] = dashLen;
      if (morse[i + 1] == ' '){
        numberCodes[j + 1] = letterPause;
      }
      else {
        numberCodes[j + 1] = elemPause;
      }
      i++;
      j += 2;
    }
    else i++;
  }
  for (pos = 0; pos < getArrayLength(morse); pos++){
    sum += numberCodes[pos];
  }
  return sum;
}

void convertMorse(String morse){
  int i = 0, j = 0;
  long int numberCodes[getArrayLength(morse)];
  while (i < morse.length()){
    if (i == morse.length() - 1){
      if (morse[i] == '.'){
        numberCodes[j] = dotLen;
      }
      else if (morse[i] == '-'){
        numberCodes[j] = dashLen;
      }
      numberCodes[j + 1] = wordPause; 
      i++; 
      j += 2;
    }
    else if (morse[i] == '.') {
      numberCodes[j] = dotLen;
      if (morse[i + 1] == ' '){
        numberCodes[j + 1] = letterPause;
      }
      else {
        numberCodes[j + 1] = elemPause;
      }
      i++;
      j += 2;  
    }
    else if (morse[i] == '-'){
      numberCodes[j] = dashLen;
      if (morse[i + 1] == ' '){
        numberCodes[j + 1] = letterPause;
      }
      else {
        numberCodes[j + 1] = elemPause;
      }
      i++;
      j += 2;
    }
    else i++;
  }
  int pos;
  long sum = 0;
  unsigned long elapsed = millis();
  long lastSequenceStartTime = 0;
  for (pos = 0; sum < elapsed - lastSequenceStartTime; pos++){
    sum += numberCodes[pos];
    Serial.begin(9600);
    Serial.println(sum);
  }
 
  if (pos % 2 == 0) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
  if (sum < elapsed - lastSequenceStartTime){
    lastSequenceStartTime = elapsed;
  }
}

void setup() {
  buttons[0].buttonPin = A5;
  buttons[0].lastButtonState = LOW;
  buttons[0].lastDebounceTime = 0;
  buttons[1].buttonPin = A4;
  buttons[1].lastButtonState = LOW;
  buttons[1].lastDebounceTime = 0;
  pinMode(buttons[0].buttonPin, INPUT);
  pinMode(buttons[1].buttonPin, INPUT); 
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  pinMode(digit5, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop(){
  const unsigned long sevsegTime = 3;
  unsigned long morseTime = 0;
  unsigned long currentTime = millis();
  if (currentTime - previousTimeSEVSEG >= sevsegTime){
    for (int i = 0; i < 2; i++){
      debounce(&buttons[i]);
    }
    previousTimeSEVSEG = currentTime;
  }
  convertMorse(car);
  /*if (currentTime - previousTimeMorse >= morseTime){
    convertMorse(car);
    previousTimeMorse = currentTime;
    morseTime = delaySum(car);    
  }*/
  /*long delta = currentTime - t0;
  for (int i = 0; i < currentWord.length(); i++){
      switch(currentWord[i]){
        case '.':
           delta -= 1000;
           break; 
        case '-':
           delta -= 3000;
           break;
        case ' ':
           delta -= 1000;
           break;   
      }
      if (delta <= 0){
        switch(currentWord[i]){
        case '.':
        case '-':
           digitalWrite(LED, HIGH);
           break;
        case ' ':
           digitalWrite(LED, LOW);
           break;   
        }  
        break;
      }
      if (i == currentWord.length() - 1){
        t0 = millis();
        if (currentWord == "       "){
          currentWord = full;
        } 
        else {
          currentWord = "       ";
        }
      }
  }*/ 
}
