#include <msp430.h>
#include "buzzer.h"

#define F 1351.37 //2702.74 // F#5
#define CS 1911.13 //3607.7  // C#5

#define A 2146.16 // A#5
#define A5 2272.72
#define B5 2024.76
#define D 3214.14 // D#5
#define D5 3405.24
#define E5 3033.75
#define G5 2551.05

#define BEAT 68

extern int curr_verse;

extern int note_counter;
extern char curr_state_one;

void song_advance();
void play_fallen_down();
