#include <msp430.h>
#include "song.h"

#define TEMPO 4000000

int intro[7] = {D5, D5, D5, D5, E5, G5, E5};

int verse[23] = {A5, B5, 0, 0, 0, C5, B5, G5, D6, E6, D6, 0, 0, 0, 0, D6, D6, E6, G5, E6, A5, 0, B5};

void play_bubblegum()
{
  int i;
  // intro
  for(i = 0; i < 7; i++) {
    buzzer_set_period(intro[i]);
    switch(i){
    case 0:
    case 1:
    case 2:
      __delay_cycles(TEMPO);
      break;
    default:
      __delay_cycles(TEMPO*0.5);
      break;
    }
  }
  //verse
  
  for(i = 0; i < 23; i++) {
    buzzer_set_period(verse[i]);
    switch(i) {
    case 1:
    case 10:
    case 11:
    case 12:
    case 13:
    case 22:
      __delay_cycles(TEMPO);
      break;
    default:
      __delay_cycles(TEMPO * 0.5);
      break;
    }
  }
  
  buzzer_set_period(0);
}
