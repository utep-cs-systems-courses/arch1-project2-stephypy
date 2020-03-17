#ifndef stateMachine_included
#define stateMachine_included

// Current state of the MSP430
extern char curr_state;

// Will represent the initial LED color depending on the state
extern char color_state;

extern char changed;

void state_advance();

#endif // included
