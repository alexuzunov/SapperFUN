// constants won't change. They're used here to set pin numbers:
struct button {
  int buttonPin;
  int buttonState;
  int lastButtonState;
  unsigned long lastDebounceTime;
  int ledPin;
};

struct button button1;
struct button button2;
struct button button3;

// the number of the pushbutton pin 
// the number of the LED pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
//int buttonState;             // the current reading from the input pin
//int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
//unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  button1.buttonPin = A5;
  button1.lastButtonState = LOW;
  button1.lastDebounceTime = 0;
  button1.ledPin = 12;
  
  button2.buttonPin = A4;
  button2.lastButtonState = LOW;
  button2.lastDebounceTime = 0;
  button2.ledPin = A2;
  
  button3.buttonPin = A3;
  button3.lastButtonState = LOW;
  button3.lastDebounceTime = 0;
  button3.ledPin = A1;
  pinMode(button1.buttonPin, INPUT);
  pinMode(button2.buttonPin, INPUT);
  pinMode(button3.buttonPin, INPUT);
  pinMode(button1.ledPin, OUTPUT);
  pinMode(button2.ledPin, OUTPUT);
  pinMode(button3.ledPin, OUTPUT);
  // set initial LED state
  digitalWrite(button1.ledPin, ledState);
  digitalWrite(button2.ledPin, ledState);
  digitalWrite(button3.ledPin, ledState);
}

void debounce(struct button *button) {
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
        ledState = !ledState;
      }
    }
  }

  // set the LED:
  digitalWrite(button->ledPin, ledState);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  button->lastButtonState = reading;  
}

void loop() {
    debounce(&button1);
    debounce(&button2);
    debounce(&button3);
  /*// read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin3);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  // set the LED:
  digitalWrite(ledPin, ledState);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;*/
}
