#include <Debounce.h>


const int shiftUp = 2;
const int shiftDown = 3;



int gear = 9;
boolean autoShift = false;

int shiftState = 0;  // LOW is manual shifting HIGH is automatic
int upState = 0;
int downState = 0;

int lastShiftState = 0;
int lastUpState = 0;
int lastDownState = 0;

Debounce upButton(shiftUp, 20); // Button1 debounced
Debounce downButton(shiftDown, 20); // Button2 debounced

void setup() {
    Serial.begin(9600);
    pinMode(shiftUp, INPUT);
    pinMode(shiftDown, INPUT); // Also works with INPUT_PULLUP

}

void loop() {
    upState = digitalRead(upButton.read());
    downState = digitalRead(downButton.read());
    shiftState = (upState && downState);

    if (shiftState != lastShiftState) {
        if (shiftState == HIGH) {
            autoShift = !autoShift;
        }
        delay(10);
    } else if (upState != lastUpState) {
        if (upState == HIGH) {
            gear ++;
        }
        delay(10);
    } else if (downState != lastDownState) {
        if (downState == HIGH) {
            gear --;
        }
        delay(10);
    }

    lastShiftState = shiftState;
    lastDownState = downState;
    lastUpState = upState;


    Serial.print("ShiftState:");
    Serial.print(autoShift);
    Serial.print("   Gear:");
    Serial.println(gear);
}
