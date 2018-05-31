# donationbox

Arduino code was developed using plastformio. If you don't know it, I strongly recommend you to give it a try. If you just was to get this running quickly you can copy and paste the contents of main.cpp into the arduino ide. It is completely compatible. 

## Dependencies:
Arduino code depends on the [LowPower](https://github.com/rocketscream/Low-Power) library

## Circuit boards:
There is a double sided (arduinoshield) and a single sided version (arduinoshield-ss) of the same schematic. KiCad did not allow me to share the schematic between two boards so there is some duplication.
Neither is actually a shield. It's just a breakout board for a transistor switched led strip and two ir endstops. 


## Todo's:
* make a fancy animation (using pwm?) on the led instead of the current dump on/off sequence.
