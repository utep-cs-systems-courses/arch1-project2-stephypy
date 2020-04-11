Project 2: Blinky Buzzy Toy (aka bobeep) <br>
Author: Stephanie Galvan
====================
# Description:

Implemented on a MSP430, the blinky buzzy toy creates sound and lights with
the use of a state machine. There are a total of four states that will
accomplish the task with the addition of a default state that will serve as
both a welcome and warning. 

# How To Compile & Run It

1. Download the folder 'project' from this repository
2. Access the 'timerLib' folder
3. Run 'make install'
4. Access the 'src' folder
5. Plug in the msp430 to your machine and make sure it's connected
6. Run 'make load'
7. Press any button to begin

To clean, you can access the 'src' folder and run 'make clean'

# How To Use It

- When the msp430 is first connected and run, it will play a short series of sounds as a welcome message.
- S1 Button will play a fragment of the song "fallen down" from Undertale
- S2 Button will display a red dimmed light
- S3 Button will cycle between red light, green light, both red and green
lights, and then off
- S4 Button will cycle between green light and red light

# About the Files

### main

**bobeep_main.c** <br>

The program begins here. Inside the file, the methods called allow the set up
fo the LED lights, the speaker (buzzer), and the buttons
(switches). Interrupts will be used.

### buzzer

**buzzer.h** <br>
**buzzer.c** <br>

These files contain information about the speaker. It allows the use of them
in order to create sound. The sound itself is created inside the song files
explained below.

### led

**led.h** <br>
**led.c** <br>

These files allow the set up of the LED lights, and the turn on/off of the
lights. Lights can be turned on due to the variables 'red_on' and 'green-on'
which will indicate whether the light is on or off. 0 is used as off and 1 is
used as on.

### switches

**switches.h** <br>
**switches.c** <br>

Inside these files the switches from the expansion board of the msp430 are
used. A variable called 'state' is used to indicate what state the program
should run. Each switch (button) represents a different state:

- SW1 is state 1
- SW2 is state 2
- SW3 is state 3
- SW4 is state 4

Variable 'state' is initially defined as 0 in order to play a short
tone. State 0 or any number not within the range of 1-4 is considered the
default state. The default state will play the series of notes as a welcome
message at the beggining and as a warning message at any other point. This
allows for debugging in the case of some faulty state transitions (at the
moment states only transition from 1-2-3-4, but this is to make the program robust). 

### state machines

**stateMachines.h** <br>
**stateMachines.c** <br>

This project contains a total of 4 states each represented by a switch plus a
default state. Each state has a different function. However, states 2-4 are
called in ths file while state 1 is defined in the song files described below.

- State 2: When state 2 is selected, a dimmed red light is displayed. This is
  done by having 1 interrupt per second and toggling the red light as
  off-off-off-off-on (the interrrupts are explained further below).

- State 3: Defined as red_plus_green(), this state will go from a red light,
  to a green light, to both red and green light, and to off. The cycle is
  defined by having cases inside this method.

- State 4: The implementation is found in the method called green_to_red() in
  which the LED lights will constantly go from green to red back and forth.

The state machine transitions are found in an assembly file
explained below.

### assembly

**stateAdvance_assembly.h** <br>
**stateAdvance_assembly.s** <br>

A jump table was implmented to allow the state transitions. A total of four
states plus a default case were used. Each case call the appropiate method to
accomplish its task. Although it was already explain above, the cases
functions will be listed below:

case 1:
Will play a song (Fallen Down) found in song.c

case 2:
Will dim a red light; method found in stateMachines.c

case 3:
Will transition from red-green-both-off repeatedly; method found in stateMachines.c

case 4:
Will transition from green-red repeatedly; method found in stateMachines.c

default:
Will play a short series of notes; method found in song.c

Note that the msp430 will ALWAYS run the default state first as a welcome
message. If it plays the default case again while the msp430 is still
connected and running, then the default case serves a warning for a
bug. Currently, there has not been any other additional bugs related to state transitions.

### song

**song.h** <br>
**song.c** <br>

These files contain the notes for the song and functions that allow the music
to be played. The order of the notes are saved in an array and the machine is
able to play each note successfully. The function buzzer_set_period(#) allows
a sound to be made in which # represents a note (defined as a number).

### p2 interrupt handler

**p2_interrupt_handler.c** <br>

A simple file that checks whether a switch caused an interrupt. If so, it
would continue the program.

### wd interrupt handler

**wdInterruptHandlder.c** <br>

For state 1, I the value 68 as an interrupt for the song. This value was
chosen since it represents an eighth note. When the song is over, it would
play a normal quarter note which takes 136 interrupts per second.

For state 2, in order to make the red light appear dim, this state needed to
be called incredibly fast to create that effect. Thus, I used 1 interrupt per
second.

For the rest of the states, the default 125 interrupts per second from the
demos files was used. 
