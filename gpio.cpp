#include "gpio.hpp"

void gpioInitialize()
{
	DDR_LED = _BV(PIN_LED_FULL_BRIGHT) | _BV(PIN_LED_PWM);
}
