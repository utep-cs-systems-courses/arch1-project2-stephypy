	.arch msp430g2553	
	.p2align 1, 0

	;; Jump Table
	.text
jt:
	.word default 		; jt[0]
	.word case01 		; jt[1]
	.word case02 		; jt[2]
	.word case03 		; jt[3]
	.word case04 		; jt[4]

	;; State Machine Transitions
	.text
	.global state_advance
state_advance:
	cmp #5, &state 		; Range check; states - 5
	jc default 		; should be jnc (TO DO: fix msp430 default compile)

	mov &state, r12
	add r12, r12 		; Keep it even
	mov jt(r12), r0 	; Position in the jump table, program counter

	;; Switch Statements
case01:
	call #song_advance 	; State 1: Song (found in song.c)
	jmp end

case02:
	call #dim_red 		; State 2: Dim Red Light (found in stateMachines.c)
	call #led_update
	jmp end

case03:
	call #red_plus_green 	; State 3: Red, Green, Both (found in stateMachines.c)
	call #led_update
	jmp end

case04:
	call #green_to_red 	; State 4: Green to Red (found in stateMachines.c)
	call #led_update
	jmp end

default:
	call #warning 		; Default: For invalid cases, play a warning tone (found in song.c)

end:
	ret 			; pop r0
