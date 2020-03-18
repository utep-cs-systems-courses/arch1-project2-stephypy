#ifndef stateMachine_included
#define stateMachine_included

void state_advance();

/* State 1 */
void play_song(); // Plays bubblegum song

/* State 2 */
char red_blink(); // Red goes from dim to bright and repeats

/* State 3 */
char red_plus_green(); // Every button press leads to red->green->(red and green) then repeat

/* State 4 */
char green_blink(); // Green goes from dim to bright and repeats

extern char state, led_state;

#endif // included
