#include "pwm.hpp"

#include <avr/interrupt.h>

/**
 * Konfiguracja Timer/Counter2 w trybie Fast PWM.
 */
constexpr uint8_t TIMER2_FAST_PWM = _BV(WGM21) | _BV(WGM20);

/**
 * Taktowanie Timer/Counter2 zegarem podzielonym przez 1024.
 */
constexpr uint8_t TIMER2_PRESCALER = _BV(CS22) | _BV(CS21) | _BV(CS20);

/**
 * Konfiguracja OC2A w trybie odwróconym.
 * 
 * Używamy zanegowanego wyjścia ze względu na sterowanie LED-em za pomocą 0.
 */
constexpr uint8_t TIMER2_INVERTING_MODE = _BV(COM2A1) | _BV(COM2A0);

/**
 * Obsługa przerwania przepełnienia Timer/Counter2.
 */
ISR(TIMER2_OVF_vect)
{
}

void pwmInitialize()
{
	TCCR2A = TIMER2_FAST_PWM | TIMER2_INVERTING_MODE;
	TCCR2B = TIMER2_PRESCALER;
}
