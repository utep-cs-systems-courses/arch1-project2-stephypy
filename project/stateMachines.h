#ifndef stateMachine_included
#define stateMachine_included

/* Allows the selection of state */
void state_advance();

/* State 1 */
void play_song(); // Plays bubblegum song

/* State 2 */
char red_blink(); // Red goes from dim to bright and repeats

/* State 3 */
char red_plus_green(); // Series of lights as red->green->both on->both off->repeat

/* State 4 */
char green_blink(); // Green goes from dim to bright and repeats

extern char state; // Keeps record of the state selected by pressing the corresponding button
exter char led_state; // Keeps record of which LED state[states 2, 3, 4] was selected (if any)

#endif // included
