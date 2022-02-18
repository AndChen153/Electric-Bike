 - https://thepihut.com/blogs/raspberry-pi-tutorials/how-do-i-power-my-arduino (MOVE TO CIRCUITS FILE)
### Libraries Used
 - https://github.com/wkoch/Debounce
# VS Code for Arduino
 -   install arduino extension
 -   to access library manager
		 - f1, then type library manager
 -   to install custom libraries
		 - install through arduino ide
 -   setup for arduino type and serial port is on the bottom right of the window
		 - click the plug to change the port
 -   you can only have one file in a folder at a time to be able to send and run it
### Guides Used
 - https://maker.pro/arduino/tutorial/how-to-use-visual-studio-code-for-arduino

# TM1637 Digit Display
### Code
- setSegments(segments[ ], length, position)
- showNumberDecEx(number, dots, leading_zeros, length, position)
- setBrightness(brightness, true/false)

### Wiring
![7-segment-display-annotated](https://www.makerguides.com/wp-content/uploads/2019/08/7-segment-display-annotated.jpg)
![TM1637-4-digit-7-segment-display-with-Arduino-UNO-tutorial-wiring-diagram-schematic-pinout](https://www.makerguides.com/wp-content/uploads/2019/08/TM1637-4-digit-7-segment-display-with-Arduino-UNO-tutorial-wiring-diagram-schematic-pinout-1.jpg)
-


 ### Guides Used
 - https://www.makerguides.com/tm1637-arduino-tutorial/
# Stepper Motor Control with A4988
### Code
    // turn the motor 5 times
    for  (int i = 0; i < 5 * stepsPerRevolution; i++)  {
	    // These four lines result in 1 step:
	    digitalWrite(stepPin, HIGH);
	    delayMicroseconds(500);
	    digitalWrite(stepPin, LOW);
	    delayMicroseconds(500);
    }
### Wiring
![A4988 Arduino stepper motor wiring schematic diagram pinout](https://www.makerguides.com/wp-content/uploads/2019/02/A4988-Arduino-stepper-motor-wiring-schematic-diagram-pinout-1-1024x551.jpg)
**- Make sure to always connect sleep to reset pin**
- Current Limit = V<sub>ref</sub> ÷ (8 × Rcs), set this on the pot on the stepper motor driver
- The Rcs is the current sense resistance. Drivers sold after Jan 2017 have 0.068 Ω current sense resistors.
- So this means that for a current limit of 1.5A for a board with 0.068 Ω current sense resistors, the V<sub>ref</sub> should be 0.816 mV.
### Guides used
- https://www.makerguides.com/a4988-stepper-motor-driver-arduino-tutorial/
