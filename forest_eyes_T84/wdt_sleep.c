/*
 * https://www.marcelpost.com/wiki/index.php/ATtiny84_WDT_sleep
 */

#include "wdt_sleep.h"

void setup_watchdog(int ii) 
{
  // 0=16ms, 1=32ms,2=64ms,3=128ms,4=250ms,5=500ms
  // 6=1 sec,7=2 sec, 8=4 sec, 9= 8sec

  uint8_t bb;
  if (ii > 9 ) ii=9;
  bb=ii & 7;
  if (ii > 7) bb|= (1<<5);
  bb|= (1<<WDCE);

  MCUSR &= ~(1<<WDRF);
  // start timed sequence
  WDTCSR |= (1<<WDCE) | (1<<WDE);
  // set new watchdog timeout value
  WDTCSR = bb;
  WDTCSR |= _BV(WDIE);
}

// system wakes up when watchdog is timed out
void system_sleep(uint8_t ii) 
{
  cbi(ADCSRA,ADEN);                    // switch Analog to Digitalconverter OFF
  setup_watchdog(ii);                   // 9 = approximately 8 seconds sleep
 
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); // sleep mode is set here
  sleep_enable();
  sei();                               // Enable the Interrupts so the wdt can wake us up

  sleep_mode();                        // System sleeps here

  sleep_disable();                     // System continues execution here when watchdog timed out 
  //sbi(ADCSRA,ADEN);                    // switch Analog to Digitalconverter ON
}

void watchdog_sleep(uint16_t seconds) {
    uint8_t dur = 8;
    uint8_t ii = 9;
    while (seconds && dur) {
        while (seconds >= dur) {
            system_sleep(ii);
            seconds -= dur;
        }
        dur >>= 1;
        ii -= 1;
    }
}

void watchdog_sleep_ms(uint16_t approx_ms) {
    uint16_t dur = 8192;
    uint8_t ii = 9;
    while (approx_ms) {
        while (approx_ms >= dur) {
            system_sleep(ii);
            approx_ms -= dur;
        }
        dur >>= 1;
        if (ii == 0) return;
        ii -= 1;
    }
}

// rename
void delay (uint16_t approx_ms) {
    watchdog_sleep_ms(approx_ms); // +/- 16ms
}

void wait_seconds(uint16_t seconds) {
    watchdog_sleep(seconds);
}

void wait_minutes(uint8_t minutes) {
    while (minutes--) {
        wait_seconds(SEC_PER_MIN);
    }
}

void wait_hours(uint8_t hours) {
    while (hours--) {
        wait_minutes(MIN_PER_HOUR);
    }
}

// Watchdog Interrupt Service / is executed when watchdog timed out
ISR(WDT_vect)
{
 // nothing here
}
