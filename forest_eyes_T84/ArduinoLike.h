/*
 * write some Arduino-like functions to make conversion easier
 */

#ifndef __ARDUINOLIKE_H__
#define __ARDUINOLIKE_H__

#include <avr/io.h>
#include "stdlib.h"
#include "AnalogInput.h"

#define INPUT  0
#define OUTPUT 1

#define LOW  0
#define HIGH 1

void pinMode (uint8_t pin, uint8_t value);
void digitalWrite (uint8_t pin, uint8_t value);
void seed_random (void);
uint16_t randomWMax (uint16_t howbig);
uint16_t randomWMinMax (uint16_t howsmall, uint16_t howbig);
uint16_t max (uint16_t a, uint16_t b);

#endif // __ARDUINOLIKE_H__
