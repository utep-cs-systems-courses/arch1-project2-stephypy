#include <msp430.h>
#include "song.h"
#include "stateMachines.h"
#include "switches.h"

int curr_verse = 0;
int verse[] = {F, CS, F, CS, F, CS, F, CS, F, CS, F, CS, B5, A5, CS, 0, A5, CS, E5, D, E5, F, D5, B5, F, B5, F, B5, F, B5, F, A, F, A5, G5, 0};

char curr_state_one = 0;
int note_counter = 0;

void song_advance() {
 play_fallen_down();
 switch_state_changed = 0;
}

void play_fallen_down() {

if(note_counter == 36) {
   buzzer_set_period(0);
/* bug: can only play the song again after pressing another button */
}
else {
 switch(curr_state_one) {
 case 0:
  buzzer_set_period(verse[curr_verse]);
  curr_verse++;
  note_counter++;
  curr_state_one = 1;
  break;

  case 1:
   buzzer_set_period(verse[curr_verse]);
   curr_verse++;
   note_counter++;
   curr_state_one = 0;
   break;
  }
 }
}
