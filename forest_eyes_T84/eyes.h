/*
 */

#ifndef __EYES_H__
#define __EYES_H__

#include <avr/io.h>
#include "ArduinoLike.h"
#include "wdt_sleep.h"

//      ANALOG_PIN  // PA0
#define LED_1_PIN 1 // PA1
#define LED_2_PIN 5 // PA5

#define STARE_TYPES 6

void init_eyes (void);
void flash_each_eye (void);
void open_eyes (void);
void close_eyes (void);
void flash_eyes (uint16_t delay_ms);
void blink_eyes (uint16_t delay_ms);
void pass_stick_in_front (uint8_t pin1, uint8_t pin2, uint16_t delay_ms);
void pass_stick_left (uint16_t delay_ms);
void pass_stick_right (uint16_t delay_ms);
void pass_board_in_front (uint8_t pin1, uint8_t pin2, uint16_t delay_ms);
void pass_board_left (uint16_t delay_ms);
void pass_board_right (uint16_t delay_ms);
void stare (uint8_t r, uint16_t start_delay_ms, uint16_t delay_ms, uint16_t end_delay_ms);
void closed_phase (void);
void open_phase (void);
void stare_test (void);

#endif // __EYES_H__
