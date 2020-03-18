#ifndef stateMachine_included
#define stateMachine_included

/* State 1 */
void play_song(); // Plays bubblegum song

/* State 2 */
void red_blink(); // Red goes from dim to bright and repeats

/* State 3 */
void red_plus_green(); // Every button press leads to red->green->(red and green) then repeat

/* State 4 */
void green_blink(); // Green goes from dim to bright and repeats

#endif // included
