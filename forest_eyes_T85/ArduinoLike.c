/*
 * write some Arduino-like functions to make conversion easier
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
 */

#include "ArduinoLike.h"

void pinMode (uint8_t pin, uint8_t value) {
    if (value) {
        DDRB |=  (1 << pin);
    } else {
        DDRB &= ~(1 << pin);
    }
}

void digitalWrite (uint8_t pin, uint8_t value) {
    if (value) {
        PORTB |=  (1 << pin);
    } else {
        PORTB &= ~(1 << pin);
    }
}

/*
  Part of the Wiring project - http://wiring.org.co
  Copyright (c) 2004-06 Hernando Barragan
  Modified 13 August 2006, David A. Mellis for Arduino - http://www.arduino.cc/

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id$
*/

void seed_random (void) {
    analogInit();
    srandom(analogRead());
}

uint16_t randomWMax (uint16_t howbig) {
  if (howbig == 0) {
    return 0;
  }
  return random() % howbig;
}

uint16_t randomWMinMax (uint16_t howsmall, uint16_t howbig) {
  if (howsmall >= howbig) {
      return howsmall;
  }
  uint16_t diff = howbig - howsmall;
  return randomWMax(diff) + howsmall;
}

uint16_t max (uint16_t a, uint16_t b) {
    return (a > b) ? a : b;
}