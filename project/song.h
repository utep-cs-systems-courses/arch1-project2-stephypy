#include <msp430.h>
#include "buzzer.h"

#define D5 587.33
#define D6 1174.66
#define E6 1318.51
#define G6 1567.98

#define A6 1760
#define B6 1975.53
#define C6 1046.5

extern int curr_intro;
extern int intro_beats[];

extern int curr_verse;
extern int verse_beats[];

extern int curr_chorus;
extern int chorus_beats[];

extern int note_counter;
extern char curr_state_one;

void song_advance();
void play_bubblegum();
