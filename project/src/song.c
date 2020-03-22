#include <msp430.h>
#include "song.h"
#include "stateMachines.h"
#include "switches.h"

// Current index of the note
int curr_verse = 0;

// Fallen Down piano notes
int verse[] = {F, CS, F, CS, F, CS, F, CS, F, CS, F, CS, B4, A4, CS, 0, A4, CS, E5, D, E5, F, D4, B4, F, B4, F, B4, F, B4, F, A, F, A4, G5, 0, F, D4, F, D4, E5, F, E5, F, E5, 0, D4, 0, CS, 0};

// Allows to change between cases
char curr_state_one = 0;

/* State 4 */
void song_advance() {
 play_fallen_down();
 switch_state_changed = 0;
}

/* Play a fragment of Fallen Down from Undertale */
void play_fallen_down() {

// Reached end of the song
if(curr_verse == 48) {
  buzzer_set_period(0); // Terminate
/* bug: can only play the song again after pressing another button */
}
// Song Logic:
else {
 switch(curr_state_one) {
 case 0:
   buzzer_set_period(verse[curr_verse]); // Play note
   curr_verse++; // Move to the next note
   curr_state_one = 1; // Change case
   break;

  case 1:
    buzzer_set_period(verse[curr_verse]); // Play note
    curr_verse++; // Move to the next note
    curr_state_one = 0; // Change case
    break;
  }
 }
}
