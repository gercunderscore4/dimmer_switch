/*
 * There's too much of this code to be in main.
 */

#include "eyes.h"

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
    digitalWrite(LED_1_PIN, LOW);
    delay(300);
    digitalWrite(LED_2_PIN, HIGH);
    delay(300);
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

void flash_eyes (uint16_t delay_ms) {
    open_eyes();
    delay(delay_ms);
    close_eyes();
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

void stare_test (void) {
    for (uint8_t r = 0; r < STARE_TYPES; r++) {
        stare(r, 1000, 300, 1000);
        close_eyes();
        delay(1000);
    }
}
