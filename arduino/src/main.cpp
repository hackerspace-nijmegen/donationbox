#include <Arduino.h>
#include "LowPower.h"

#define pin_switch_1	2
#define pin_switch_2	3
#define pin_leds 		4


void setup()
{
	// Disable some peripherals to save more power
	ADCSRA = ADCSRA & B01111111;
	ACSR = B10000000;
	DIDR0 = DIDR0 | B00111111;

	// even more power could be saved by flashing firmware without a bootloader (because it saves a lot of on-time)
	// and while uploading through usbasp ,maybe also decrease F_CPU and disable things like BOD in the fuses.

	pinMode(pin_switch_1, INPUT_PULLUP);
	pinMode(pin_switch_2, INPUT_PULLUP);
	pinMode(pin_leds, OUTPUT);

	// pinMode(13, OUTPUT);
	// Serial.begin(9600);
}



void loop()
{
	// Serial.println("loop");
	// TODO: is a delay needed to stabilise arduino/leds/optotransistors?
	// digitalWrite(13, LOW);
	if ( digitalRead(pin_switch_1)==HIGH || digitalRead(pin_switch_2)==HIGH ) // remember that the inputs are pulled high but drawn low when light hits the base. I.e. when interrupted no more light hits the base and the pin goes HIGH.
	{
		for (int i=0;i<5;i++)
		{
			digitalWrite(pin_leds, HIGH);
			delay(1000);
			digitalWrite(pin_leds, LOW);
			delay(500);
		}
	}
	// delay(100);
	// digitalWrite(13,HIGH);
	LowPower.powerDown(SLEEP_250MS, ADC_OFF, BOD_OFF);
}
