#include <msp430.h>
#include "song.h"
#include "stateMachines.h"
#include "switches.h"

int curr_intro = 0;
int intro_beats[] = {400, 400, 100, 100, 100};
int intro[] = {D5, D6, E6, G6, E6};

int curr_verse = 0;
int verse_beats[] = {100, 200, 400, 400, 100, 100, 100, 100, 100, 200};
int verse[] = {A6, B6, 0, 0, C6, B6, G6, D6, E6, D6};

int curr_chorus = 0;

char curr_state_one = 0;
int note_counter = 0;

void song_advance() {
 play_bubblegum();
 switch_state_changed = 0;
}

void play_bubblegum() {

if(note_counter == 15) {
   buzzer_set_period(0);
/* bug: can only play the song again after pressing another button */
}
else {
 switch(curr_state_one) {
// Intro
 case 0:
  buzzer_set_period(intro[curr_intro]);
  curr_intro++;
  note_counter++;

  if(curr_intro == 5) curr_state_one = 2;
  else curr_state_one = 2;
  curr_state_one = 1;
  break;

  case 1:
   buzzer_set_period(intro[curr_intro]);
   curr_intro++;
   note_counter++;
   curr_state_one = 0;
   break;

// Verse
  case 2:
  buzzer_set_period(verse[curr_verse]);
  curr_verse++;
  note_counter++;
  curr_state_one = 3;
  break;

  case 3:
  buzzer_set_period(verse[curr_verse]);
  curr_verse++;
  note_counter++;
  if(curr_verse == 10) curr_state_one = 0;
  else curr_state_one = 2;
  break;
  }
 }
}
