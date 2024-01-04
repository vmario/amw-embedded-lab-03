#include "gpio.hpp"
#include "pwm.hpp"

#include <avr/io.h>

/**
 * Co robi ta funkcja?
 */
void holdYourHorses()
{
	CLKPR = _BV(CLKPCE);
	CLKPR = _BV(CLKPS1) | _BV(CLKPS0);
}

/**
 * Funkcja główna.
 */
int main()
{
	holdYourHorses();
	gpioInitialize();
	pwmInitialize();

	while (true) {
	}
}
