/*
 *          ATtiny85
 * ADC0 PB5 -+----+- VCC
 * ADC3 PB3 -+ O  +- PB2  ADC1
 * ADC2 PB4 -+    +- PB1
 *      GND -+----+- PB0
 *
 * PB5 : floating voltage
 * PB0 : LED 1
 * PB1 : LED 2
 *
 * Useful registers
 * ----------------
 * 
 * DDRB  - Port B Data Direction Register
 * 0 = INPUT, 1 = OUTPUT
 *
 * PORTB - Port B Data Register
 * INPUT: 1 = PULL-UP
 * 1 = HIGH, 0 = LOW
 *
 * PINB  - Port B Input Pins Address
 * 1 = HIGH, 0 = LOW
 *
 * https://embeddedcomputing.com/technology/processing/chips-and-socs/tinysnore-turns-your-attiny-into-a-low-power-prodigy
 */

#include "eyes.h"

/****************************************************************
 * MAIN
 ****************************************************************/

void wait_rand (uint16_t min_sec, uint16_t max_sec) {
    wait_seconds(randomWMinMax(min_sec, max_sec));
}

void blink_random_byte (void) {
    // test randomness by outputting random numbers
    // turn off and on a few times, observe different numbers
    uint8_t byte = randomWMinMax(0x00, 0xFF);
    for (uint8_t i = 0x80; i > 0; i>>=1) {
        delay(1000);
        digitalWrite(LED_1_PIN, byte & i ? HIGH : LOW);
        digitalWrite(LED_2_PIN, HIGH);
        delay(500);
        digitalWrite(LED_1_PIN, LOW);
        digitalWrite(LED_2_PIN, LOW);
    }
}

void closed_phase (void) {
    // there are about 6 sets of these
    // in 10s, the observer could close the gap
    // turn off before they get too close
    // I want them on about 5% (1/20th) of the time
    // 10*6*20 = 20 min
    // 15 ~ 45 min
    close_eyes();
    wait_rand(900, 2700);
}

void open_phase (void) {
    // at most 10s, but usually about half
    uint8_t r = randomWMax(STARE_TYPES*7); // about 1/7 of seeing a blink
    uint16_t start_delay_ms = randomWMinMax(250, 2500) + randomWMinMax(250, 2500);
    uint16_t end_delay_ms = randomWMinMax(250, 2500) + randomWMinMax(250, 2500);
    uint16_t blink_delay_ms = randomWMinMax(10, 100);
    stare(r, start_delay_ms, blink_delay_ms, end_delay_ms);
}

int main (void) {
    seed_random();
    init_eyes();
    flash_each_eye();

    //wait_hours(6);

    while (1) {
        closed_phase();
        open_phase();
    }
}
