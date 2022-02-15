#include <Debounce.h>

byte shiftUp = 2;
byte shiftDown = 3;
byte state = 9;
byte state = LOW;  // LOW is manual shifting HIGH is automatic

Debounce shiftUp(button1, 70); // Button1 debounced
Debounce shiftDown(button2, 70); // Button2 debounced

void setup() {
    Serial.begin(9600);
    pinMode(shiftUp, INPUT);
    pinMode(shiftDown, INPUT); // Also works with INPUT_PULLUP
}

void loop() {
    upState = digitalRead(shiftUp);
    downState = digitalRead(shiftDown);
    shiftState = upState && downState;
    Serial.println(shiftState);
}
