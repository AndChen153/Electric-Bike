# Electric-Bike
Project bike

Modified unpowered bicycle that includes:

- automatic/electric shifting
- power assist pedaling/regen braking
- custom hydraulic brakes
- pneumatic shocks


Libraries:
- https://github.com/wkoch/Debounce


Notes:

Current Limit = Vref ÷ (8 × Rcs), set this on the pot on the stepper motor driver

The Rcs is the current sense resistance. If you bought a A4988 driver from Pololu before January 2017, the Rcs will be 0.050 Ω. Drivers sold after that have 0.068 Ω current sense resistors.

So this means that for a current limit of 1.5A for a board with 0.068 Ω current sense resistors, the Vref should be 0.816 mV.