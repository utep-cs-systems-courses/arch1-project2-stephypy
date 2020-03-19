#include <msp430.h>
#include "buzzer.h"

#define F  2702.74 // F#4
#define CS 3607.7  // C#4

#define A 4290.37  // A#4
#define A4 4545.45 
#define B4 4049.56 
#define D 6428.18  // D#4
#define D4 6810.6
#define E5 6067.4 //3033.75
#define G5 5102.04 //2551.05

#define BEAT 68

extern int curr_verse;

extern int note_counter;
extern char curr_state_one;

void song_advance();
void play_fallen_down();
