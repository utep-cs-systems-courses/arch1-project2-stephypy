#ifndef switches_included
#define switches_included

#define SW1 BIT0 /* switch1 is p1.3 */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4)  /* only 1 switch on this board */

// Four possible states determined by pressing the corresponding switch
extern char sw1_state_down, sw2_state_down, sw3_state_down, sw4_state_down;

// Has the state changed? 
extern char switch_state_changed; /* effectively boolean */

// Switch Setup
void switch_init();

// Handles interrupts
void switch_interrupt_handler();

#endif // included
