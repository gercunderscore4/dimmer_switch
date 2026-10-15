/*
 * ATtiny84 Watchdog Timer Sleep
 * Section 16
 */

#ifndef __WDT_SLEEP_H__
#define __WDT_SLEEP_H__

#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>

// these define cbi and sbi, for as far they are not known yet
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))

#define SEC_PER_MIN 60
#define MIN_PER_HOUR 60

void setup_watchdog(int ii);
void system_sleep(uint8_t ii);
void watchdog_sleep(uint16_t seconds);
void watchdog_sleep_ms(uint16_t approx_ms);
void delay (uint16_t approx_ms);
void wait_seconds(uint8_t seconds);
void wait_minutes(uint8_t minutes);
void wait_hours(uint8_t hours);


#endif // __WDT_SLEEP_H__
