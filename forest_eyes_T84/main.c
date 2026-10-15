/*
 *     ATtiny84
 * VCC -+-\/-+- GND
 * PB0 -+    +- PA0
 * PB1 -+    +- PA1
 * PB3 -+    +- PA2
 * PB2 -+    +- PA3
 * PA7 -+    +- PA4
 * PA6 -+----+- PA5
 *
 * PA0 : floating voltage
 * PA1 : LED 1
 * PA2 : LED 2
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

#include <avr/io.h>
#include "ArduinoLike.h"
#include "wdt_sleep.h"

/****************************************************************
 * MAIN
 ****************************************************************/

//      ANALOG_PIN  // PA0
#define LED_1_PIN 1 // PA1
#define LED_2_PIN 2 // PA2

#define STARE_TYPES 6


void wait_rand (uint16_t min_sec, uint16_t max_sec) {
    uint16_t rand_sec = randomWMinMax(min_sec, max_sec);

    uint8_t delay_min = rand_sec / SEC_PER_MIN;
    uint8_t delay_sec = rand_sec % SEC_PER_MIN;

    wait_minutes(delay_min);
    wait_seconds(delay_sec);
}

void init_eyes (void) {
    pinMode(LED_1_PIN, OUTPUT);
    pinMode(LED_2_PIN, OUTPUT);
}

void flash_each_eye (void) {
    digitalWrite(LED_1_PIN, LOW);
    digitalWrite(LED_2_PIN, LOW);
    delay(300);
    digitalWrite(LED_1_PIN, HIGH);
    delay(300);
    digitalWrite(LED_2_PIN, LOW);
    delay(300);
    digitalWrite(LED_2_PIN, HIGH);
    delay(300);
    digitalWrite(LED_1_PIN, LOW);
    digitalWrite(LED_2_PIN, LOW);
    delay(300);
}

void open_eyes (void) {
    digitalWrite(LED_1_PIN, HIGH);
    digitalWrite(LED_2_PIN, HIGH);
}

void close_eyes (void) {
    digitalWrite(LED_1_PIN, LOW);
    digitalWrite(LED_2_PIN, LOW);
}

void blink_eyes (uint16_t delay_ms) {
    close_eyes();
    delay(delay_ms);
    open_eyes();
}

void pass_stick_in_front (uint8_t pin1, uint8_t pin2, uint16_t delay_ms) {
    digitalWrite(pin1, LOW);
    delay(delay_ms);
    digitalWrite(pin1, HIGH);
    delay(delay_ms*2);
    digitalWrite(pin2, LOW);
    delay(delay_ms);
    digitalWrite(pin2, HIGH);
}

void pass_stick_left (uint16_t delay_ms) {
    pass_stick_in_front(LED_1_PIN, LED_2_PIN, delay_ms);
}

void pass_stick_right (uint16_t delay_ms) {
    pass_stick_in_front(LED_2_PIN, LED_1_PIN, delay_ms);
}

void pass_board_in_front (uint8_t pin1, uint8_t pin2, uint16_t delay_ms) {
    digitalWrite(pin1, LOW);
    delay(delay_ms);
    digitalWrite(pin2, LOW);
    delay(delay_ms*2);
    digitalWrite(pin1, HIGH);
    delay(delay_ms);
    digitalWrite(pin2, HIGH);
}

void pass_board_left (uint16_t delay_ms) {
    pass_board_in_front(LED_1_PIN, LED_2_PIN, delay_ms);
}

void pass_board_right (uint16_t delay_ms) {
    pass_board_in_front(LED_2_PIN, LED_1_PIN, delay_ms);
}

void stare (uint8_t r, uint16_t start_delay_ms, uint16_t delay_ms, uint16_t end_delay_ms) {
    open_eyes();
    delay(start_delay_ms);
    if (r == 0) {
        blink_eyes(delay_ms);
    } else if (r == 1) {
        pass_stick_left(delay_ms);
    } else if (r == 2) {
        pass_stick_right(delay_ms);
    } else if (r == 3) {
        pass_board_left(delay_ms);
    } else if (r == 4) {
        pass_board_right(delay_ms);
    }
    open_eyes();
    delay(end_delay_ms);
}

void closed_phase (void) {
    close_eyes();
    wait_rand(5, 10);
}

void open_phase (void) {
    uint8_t r = randomWMax(STARE_TYPES);
    uint16_t start_delay_ms = randomWMinMax(250, 2500) + randomWMinMax(250, 2500);
    uint16_t end_delay_ms = randomWMinMax(250, 2500) + randomWMinMax(250, 2500);
    uint16_t blink_delay_ms = randomWMinMax(10, 100);
    stare(r, start_delay_ms, blink_delay_ms, end_delay_ms);
}

void stare_test (void) {
    for (uint8_t r = 0; r < STARE_TYPES; r++) {
        stare(r, 1000, 300, 1000);
        close_eyes();
        delay(1000);
    }
}

void setup (void) {
    seed_random();
    init_eyes();
    flash_each_eye();
    //stare_test();
}

void loop (void) {
    //closed_phase();
    //open_phase();
    open_eyes();
    delay(100);
    close_eyes();
    delay(900);
}

int main (void) {
    setup();

    while (1) {
        loop();
    }
}
