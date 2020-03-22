#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void main(void) 
{
  /* Voila my project bobeep!! */

  configureClocks();

  // Switch Setup
  switch_init();

  // LED Setup
  led_init();

  // Buzzer Setup
  buzzer_init(); 

  enableWDTInterrupts(); // handling interruptions

  or_sr(0x18);  // CPU off, GIE on
} 
