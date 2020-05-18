/*
  Morse Code Project
  
  This code will loop through a string of characters and convert these to morse code.  
  It will blink two LED lights and play audio on a speaker.  
 */
 
 
//**************************************************//
//   Type the String to Convert to Morse Code Here  //
//**************************************************//
String stringToMorseCode = "Car";

#define LED 6        // blink an led on output 6
#define dotLen 1000
#define dashLen 3000
#define elemPause 1000
#define letterPause 3000
#define spaces 300
#define wordPause 7000

/*
  Set the speed of your morse code
  Adjust the 'dotlen' length to speed up or slow down your morse code
    (all of the other lengths are based on the dotlen)

  Here are the ratios code elements:
    Dash length = Dot length x 3
    Pause between elements = Dot length
      (pause between dots and dashes within the character)
    Pause between characters = Dot length x 3
    Pause between words = Dot length x 7
  
        http://www.nu-ware.com/NuCode%20Help/index.html?m...
*/
/*int dotLen = 100;     // length of the morse code 'dot'
int dashLen = dotLen * 3;    // length of the morse code 'dash'
int elemPause = dotLen;  // length of the pause between elements of a character
int Spaces = dotLen * 3;     // length of the spaces between characters
int wordPause = dotLen * 7;  // length of the pause between words*/

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output for LED lights.
  pinMode(LED, OUTPUT); 
}

// Create a loop of the letters/words you want to output in morse code (defined in string at top of code)
void loop()
{ 
  // Loop through the string and get each character one at a time until the end is reached
  int isLast = 0;
  for (int i = 0; i < stringToMorseCode.length(); i++)
  {
    if (i == stringToMorseCode.length() - 1) {
      isLast = 1;  
    }
    // Get the character in the current position
    char tmpChar = stringToMorseCode[i];
    // Set the case to lower case
    tmpChar = toLowerCase(tmpChar);
    // Call the subroutine to get the morse code equivalent for this character
    GetChar(tmpChar, isLast);
  }
  
  // At the end of the string long pause before looping and starting again
  LightsOff(wordPause);      
}

// DOT
void MorseDot()
{
  digitalWrite(LED, HIGH);    // turn the LED on 
  delay(dotLen);              // hold in this position
}

// DASH
void MorseDash()
{
  digitalWrite(LED, HIGH);    // turn the LED on 
  delay(dashLen);               // hold in this position
}

// Turn Off
void LightsOff(int delayTime)
{
  digitalWrite(LED, LOW);     // turn the LED off   
  delay(delayTime);             // hold in this position
}

// *** Characters to Morse Code Conversion *** //
void GetChar(char tmpChar, int isLast)
{
  // Take the passed character and use a switch case to find the morse code for that character
  switch (tmpChar) {
    case 'a': 
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'b':
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'c':
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'd':
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
       break;
    case 'e':
      MorseDot();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'f':
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'g':
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'h':
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'i':
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'j':
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'k':
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'l':
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'm':
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'n':
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'o':
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'p':
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'q':
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'r':
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 's':
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 't':
      MorseDash();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'u':
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'v':
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'w':
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'x':
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'y':
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    case 'z':
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      if (isLast == 0) {
        LightsOff(letterPause);
      }
      break;
    default: 
    // If a matching character was not found it will default to a blank space
      LightsOff(spaces);      
  }
}
