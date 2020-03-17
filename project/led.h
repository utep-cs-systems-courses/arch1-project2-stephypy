#ifndef led_included
#define  led_included

#include <msp430.h>

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

extern unsigned char red_on, green_on;

// Initialize LEDs
void led_init();

// Update LEDs
void led_update();

// these are boolean flags
extern unsigned char led_changed, green_led_state, red_led_state;

// For states 2, 3, 4 respectively
extern char red_status, toggle_status, green_status;

#endif
