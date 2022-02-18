# Electric-Bike
Project bike

Modified unpowered bicycle that includes:

- automatic/electric shifting
- power assist pedaling/regen braking
- custom hydraulic brakes
- pneumatic shocks


Libraries:
- https://github.com/wkoch/Debounce

Links in Progress:
- https://create.arduino.cc/projecthub/alan_dewindt/bicycle-odometer-and-speedometer-with-99-lap-period-recorder-331d2b?ref=tag&ref_id=speedometer&offset=0
- https://create.arduino.cc/projecthub/139683/arduino-lcd-display-as-a-bicycle-speedometer-6a6568?ref=tag&ref_id=speedometer&offset=2
- https://maker.pro/arduino/tutorial/how-to-use-a-hall-effect-sensor-with-arduino#:~:text=The%20Arduino%20Hall%20effect%20sensor%20code%20can%20be%20used%20to,voltage%20to%20its%20Vout%20pin.


Notes:

Current Limit = Vref ÷ (8 × Rcs), set this on the pot on the stepper motor driver

The Rcs is the current sense resistance. If you bought a A4988 driver from Pololu before January 2017, the Rcs will be 0.050 Ω. Drivers sold after that have 0.068 Ω current sense resistors.

So this means that for a current limit of 1.5A for a board with 0.068 Ω current sense resistors, the Vref should be 0.816 mV.