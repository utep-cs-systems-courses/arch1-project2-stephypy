#ifndef stateMachine_included
#define stateMachine_included

/* Allows the selection of state */
void state_advance();

/* State 1 */
/* Found at song.c */

/* State 2 */
void dim_red(); // Shows a dim red light

/* State 3 */
void red_plus_green(); // Series of lights as red->green->both on->both off->repeat

/* State 4 */
/* Found at assembly.s */
//void dim_green(); // Shows a dim green light

extern char state; // Keeps record of the state selected by pressing the corresponding button

extern char curr_state_four;

#endif // included
