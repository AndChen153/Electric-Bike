#include <Debounce.h>
#include <TM1637Display.h>

#define CLK 4 // pins for 7 segment display
#define DIO 5
// #define shiftUp = 2;
// #define shiftDown = 3;

const int shiftUp = 2; // pins for shifter buttons
const int shiftDown = 3;

const int stepPin = 8; // pins for stepper motors
const int dirPin = 7;
const int sleepPin = 9;

const int stepPerShift = 300; // number of steps for each shift

TM1637Display display(CLK, DIO); // create display object for tm1637 display

// value for OFF on seven segment display
const uint8_t OFF[] = {
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F, // O
    SEG_A | SEG_E | SEG_F | SEG_G,                 // F
    SEG_A | SEG_E | SEG_F | SEG_G                  // F
};

// value for ON- on seven segment display
const uint8_t ON[] = {
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F, // O
    SEG_A | SEG_B | SEG_C | SEG_E | SEG_F,         // N
    SEG_G};

int gear = 9; // current gear, set at 9 because untensioned position of derailleur is the highest gear
int tempGear = gear;
int maxGear = 9;           // maximum gear on derailleur
boolean autoShift = false; // false is manual shifting true is automatic

int shiftState = 0; // button state variables
int upState = 0;
int downState = 0;

int lastShiftState = 0; // previous button state variables for running action on button press
int lastUpState = 0;
int lastDownState = 0;

Debounce upButton(shiftUp, 40);     // upButton debounced
Debounce downButton(shiftDown, 40); // downButton debounced

void setup()
{
    Serial.begin(9600); // intialize serial to see prints
    Serial.print(autoShift ? "ON" : "OFF");
    pinMode(shiftUp, INPUT); // set button pins to accept input
    pinMode(shiftDown, INPUT);

    display.clear(); // clear display incase anything was on it previously
    delay(10);
    display.setBrightness(7); // set display brightness
    displayUpdate();          // send default values to the display

    pinMode(stepPin, OUTPUT); // set pinmode for steppers to output
    pinMode(dirPin, OUTPUT);
    pinMode(sleepPin, OUTPUT);
    digitalWrite(sleepPin, HIGH); // turns off sleep mode on motor controller

}

void loop()
{
    tempGear = gear;
    switchModes();
    if (autoShift)
    { // example automatic shifting until stepper motors are working
        // // INPUT STEPPER CODE HERE
        // if (gear < maxGear) {
        //     gear ++;
        //     displayUpdate();
        // } else {
        //     gear = 1;
        //     displayUpdate();
        // }
        delay(20);
    }
    else
    {
        shifterInput();
        shifterOutput();
    }

    Serial.print("Auto Shift State: ");
    Serial.print((autoShift ? "ON" : "OFF"));
    Serial.print("   Gear: ");
    Serial.println(gear);
    Serial.println(millis());
}

// controls what segements show up on the display
void displayUpdate()
{
    if (autoShift)
    {
        display.setSegments(ON, 3, 0); // setSegments(segments[ ], length, position)
    }
    else
    {
        display.setSegments(OFF, 3, 0);
    }
    display.showNumberDec(gear, false, 1, 3); // showNumberDec(number, leading_zeros, length, position)

    Serial.print(upState);
    Serial.print(downState);
    Serial.print(shiftState);
}

// switch between automatic and manual shifting
void switchModes()
{
    upState = digitalRead(upButton.read()); // takes in debounced button inputs
    downState = digitalRead(downButton.read());
    shiftState = (upState && downState);

    // checks if time since program start is above 1 second because of weird behavior with buttons where it would switch modes as soon as program started
    if (millis() > 1000 && upState && downState != lastShiftState)
    {
        if (shiftState == HIGH)
        {
            autoShift = !autoShift;
            displayUpdate();
            delay(500);
        }
    }
    lastShiftState = shiftState;
}

// take in input from the two shifting buttons
void shifterInput()
{
    upState = digitalRead(upButton.read()); // takes in debounced button inputs
    downState = digitalRead(downButton.read());
    shiftState = (upState && downState);

    if (!shiftState && upState != lastUpState)
    { // performs gear ++ or -- ONCE each press of the button
        if (upState == HIGH && gear < maxGear)
        {
            gear++;
            displayUpdate();
        }
    }
    else if (!shiftState && downState != lastDownState)
    {
        if (downState == HIGH && gear > 1)
        {
            gear--;
            displayUpdate();
        }
    }
    lastShiftState = shiftState; // set previous button states
    lastDownState = downState;
    lastUpState = upState;
}

// runs the stepper motors to shift the gears
void shifterOutput()
{
    int gearsToShift = gear - tempGear;
    digitalWrite(sleepPin, HIGH); // turns off sleep mode on motor controller
    if (gearsToShift < 0)
    {
        digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction
        for (int x = 0; x < stepPerShift; x++)
        {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(500);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(500);
        }
    }
    else if (gearsToShift > 0)
    {
        digitalWrite(dirPin, LOW); // Enables the motor to move in a particular direction
        for (int x = 0; x < stepPerShift; x++)
        {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(500);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(500);
        }
    }

    digitalWrite(sleepPin, LOW); // turns on sleep mode to conserve battery
}
