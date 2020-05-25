const long dotLen = 1000;
const long dashLen = 3000;
const long elemPause = 1000;
const long letterPause = 3000;
const long spaces = 300;
const long wordPause = 7000;

const int LED = A1;
String car = "-.-. .- .-.";

int getArrayLength(String ex);
void convertMorse(String morse);

int getArrayLength(String ex){
  int counter = 0;
  for (int i = 0; i < ex.length(); i++){
    if (ex[i] == '.' || ex[i] == '-') {
      counter += 2;
    }
  }
  return counter;
}

void convertMorse(String morse){
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
  Serial.begin(9600);
  for(int k = 0; k < getArrayLength(morse); ++k){
    Serial.println(numberCodes[k]);
  }
  for (pos = 0; pos < getArrayLength(morse); pos++){
    if (pos % 2 == 0) {
      digitalWrite(LED, HIGH);
    }
    else {
      digitalWrite(LED, LOW);
    }
    delay(numberCodes[pos]);
  }

}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);

}

void loop() {
  convertMorse(car);
}
