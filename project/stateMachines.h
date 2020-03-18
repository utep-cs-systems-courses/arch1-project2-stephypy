#ifndef stateMachine_included
#define stateMachine_included

/* Allows the selection of state */
void state_advance();

/* State 1 */
void play_song(); // Plays bubblegum song

/* State 2 */
char red_blink(); // Red goes from dim to bright and repeats

void bright_red(); 
void dim_red();

/* State 3 */
char red_plus_green(); // Series of lights as red->green->both on->both off->repeat

/* State 4 */
char green_blink(); // Green goes from dim to bright and repeats

extern char state; // Keeps record of the state selected by pressing the corresponding button

#endif // included
