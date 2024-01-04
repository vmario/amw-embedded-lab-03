#pragma once

#include <avr/io.h>

/**
 * Numery pinów powiązane z LED-ami.
 */
enum PIN {
	PIN_LED_FULL_BRIGHT = 5,
	PIN_LED_PWM = 3,
};

/**
 * Port LED-ów.
 */
#define DDR_LED DDRB

/**
 * Inicjalizuje porty GPIO.
 */
void gpioInitialize();
