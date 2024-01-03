#include "gpio.hpp"
#include "pwm.hpp"

/**
 * Funkcja główna.
 */
int main()
{
	gpioInitialize();
	pwmInitialize();

	while (true) {
	}
}
