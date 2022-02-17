// defines pins numbers
const int stepPin = 8;
const int dirPin = 7;
const int sleepPin = 9;

void setup()
{
    // Sets the two pins as Outputs
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    pinMode(sleepPin, OUTPUT);
}
void loop()
{
    digitalWrite(sleepPin,HIGH);
    digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction
    // Makes 200 pulses for making one full cycle rotation
    for (int x = 0; x < 400; x++)
    {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(500);
    }
    digitalWrite(sleepPin, LOW);
    delay(2000); // One second delay

    digitalWrite(sleepPin,HIGH);
    digitalWrite(dirPin, LOW); // Changes the rotations direction
    // Makes 400 pulses for making two full cycle rotation
    for (int x = 0; x < 400; x++)
    {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(500);
    }
    digitalWrite(sleepPin, LOW);
    delay(2000);
}
