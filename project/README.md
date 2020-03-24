Project 2: Blinky Buzzy Toy (aka bobeep) <br>
Author: Stephanie Galvan
====================
# Description:

Implemented on a MSP430, the blinky buzzy toy creates sound and lights with
the use of a state machine. 

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

- S1 Button will play a fragment of the song "fallen down" from Undertale
- S2 Button will display a red dimmed light
- S3 Button will cycle between red light, green light, both red and green
lights, and then off
- S4 Button will cycle between red light and green light

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

Variable 'state' is initially defined as 0 because in state 0 nothing is happening.

### state machines

**stateMachines.h** <br>
**stateMachines.c** <br>

This project contains a total of 4 states each represent by switch. Each state
has a different function. However, states 2-4 are called in ths file while
state 1 is defined in the song files described below.

- State 2: When state 2 is selected, a dimmed red light is displayed. This is
  done by having 1 interrupt per second and toggling the red light as
  off-off-off-off-on (the interrrupts are explained further below).

- State 3: Defined as red_plus_green(), this state will go from a red light,
  to a green light, to both red and green light, and to off. The cycle is
  defined by having cases inside this method.

- State 4: The implementation of state 4 is found in the assembly files;
  however, in this stateMachines.c file the assembly function is being
  called. Afterwards, the LEDs are updated.

Additionally, all the states mentioned above also reset the values for state 1
(the song)

### song

**song.h** <br>
**song.c** <br>

These files contain the notes for the song and functions that allow the music
to be played. The order of the notes are saved in an array and the machine is
able to play each note successfully. The function buzzer_set_period(#) allows
a sound to be made in which # represents a note (defined as a number).

### assembly

**assembly.h** <br>
**assembly.s** <br>

This project required at least one function to be implemented in assembly, so
the code for state 4 is included here. The code checks whether the red light
is on, and if the red light is on, then it will turn on the green light and
turn off the red light. Otherwise, it will turn on the red light and turn off
the green light.

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
