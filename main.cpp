#include <avr/io.h>

/**
 * Numery pinów, do których podłączone są LED-y.
 */
enum LED {
	LED_D2 = 4, ///< Dioda D2.
};

/**
 * Numery pinów, do których podłączone są przyciski.
 */
enum SWITCH {
	SWITCH_A1 = 1, ///< Przycisk A1.
};

/**
 * Zaświeca diodę na wskazanym pinie.
 * 
 * @param pinLed Wskazany pin.
 */
void ledOn(uint8_t pinLed)
{
	PORTB &= ~_BV(pinLed);
}

/**
 * Gasi diodę na wskazanym pinie.
 * 
 * @param pinLed Wskazany pin.
 */
void ledOff(uint8_t pinLed)
{
	PORTB |= _BV(pinLed);
}

/**
 * Inicjalizuje GPIO.
 */
void gpioInitialize()
{
	DDRB = _BV(LED_D2);
	ledOn(LED_D2);
}

/**
 * Pętla główna.
 */
void mainLoop()
{
}

/**
 * Funkcja główna.
 */
int main()
{
	gpioInitialize();

	while (true) {
		mainLoop();
	}
}
