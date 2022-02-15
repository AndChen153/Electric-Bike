#include <Debounce.h>

// constants won't change. They're used here to set pin numbers:
const int shiftUp = 2;    // the number of the pushbutton pin
const int shiftDown = 4;

// Variables will change:
int UpButtonState;             // the current reading from the input pin
int lastUpButtonState = LOW;   // the previous reading from the input pin
int DownButtonState;
int lastDownButtonState = LOW;
int gear = 9;
int state = LOW;              // LOW is manual shifting HIGH is automatic

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastUpDebounceTime = 0;  // the last time the output pin was toggled
unsigned long lastDownDebounceTime = 0;
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(shiftUp, INPUT);
  pinMode(shiftDown, INPUT);
  Serial.begin(9600); // open the serial port at 9600 bps:

}

void loop() {
  // read the state of the switch into a local variable:
  int readingUp = digitalRead(shiftUp);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:
  // If the switch changed, due to noise or pressing:
  if (readingUp != lastUpButtonState) {
    // reset the debouncing timer
    lastUpDebounceTime = millis();
  }

  if ((millis() - lastUpDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (readingUp != UpButtonState) {
      UpButtonState = readingUp;

      // only toggle the LED if the new button state is HIGH
      if (UpButtonState == HIGH) {
        gear++;
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastUpButtonState:
  lastUpButtonState = readingUp;



  // read the state of the switch into a local variable:
  int readingDown = digitalRead(shiftDown);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:
  // If the switch changed, due to noise or pressing:
  if (readingDown != lastDownButtonState) {
    // reset the debouncing timer
    lastDownDebounceTime = millis();
  }

  if ((millis() - lastDownDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (readingDown != DownButtonState) {
      DownButtonState = readingDown;

      // only toggle the LED if the new button state is HIGH
      if (DownButtonState == HIGH) {
        gear--;
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastUpButtonState:
  lastDownButtonState = readingDown;

  // increment gear count
  Serial.println("");
  Serial.println(state);
  Serial.println(gear);



}


