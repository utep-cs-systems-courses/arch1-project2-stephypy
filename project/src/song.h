#include <msp430.h>
#include "buzzer.h"


/* notes for the song */
#define F  2702.74 // F#4
#define CS 3607.7  // C#4

#define A 4290.37  // A#4
#define A4 4545.45 
#define B4 4049.56 
#define D 6428.18  // D#4
#define D4 6810.6
#define E5 6067.4 
#define G5 5102.04 


extern int curr_verse; // Index of the current note
extern char curr_state_one; // Allows the change of cases

/* State 4 */
void song_advance();

/* Plays Song */
void play_fallen_down();

/* Warning Tone */
void warning();
