#ifndef stateMachine_included
#define stateMachine_included

// Current state of the MSP430
extern char curr_state;

extern char changed;

// Allows the changing of states
void state_advance();

#endif // included
