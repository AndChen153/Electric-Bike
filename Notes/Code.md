 - https://thepihut.com/blogs/raspberry-pi-tutorials/how-do-i-power-my-arduino (MOVE TO CIRCUITS FILE)
### Libraries Used
 - https://github.com/wkoch/Debounce
## VS Code for Arduino
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

## TM1637 Digit Display
- setSegments(segments[ ], length, position)
- showNumberDecEx(number, dots, leading_zeros, length, position)
- setBrightness(brightness, true/false)
 ### Guides Used
 - https://www.makerguides.com/tm1637-arduino-tutorial/
## Stepper Motor Control with A4988

    // turn the motor 5 times
    for  (int i = 0; i < 5 * stepsPerRevolution; i++)  {
	    // These four lines result in 1 step:
	    digitalWrite(stepPin, HIGH);
	    delayMicroseconds(500);
	    digitalWrite(stepPin, LOW);
	    delayMicroseconds(500);
    }

### Guides used
- https://www.makerguides.com/a4988-stepper-motor-driver-arduino-tutorial/