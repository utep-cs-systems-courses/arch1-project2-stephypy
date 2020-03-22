	.arch msp430g2553
	
	.text
	.global red_green_assembly
red_green_assembly:
	sub #2, R1 		;allocate memory for char
	cmp #0, &curr_state_four ;if(curr_state_four == 0)
	JEQ GREEN		 ;go to GREEN
	
	mov.b #0, 0(R1) 	;else, change the pointer of the stack to 0
	mov.b 0(R1), &curr_state_four ;curr_state_four = 0
	mov.b #1, &red_on	      ;turn red light on
	mov.b #0, &green_on	      ;turn green light off
	JMP END			      ;go to END
	
        GREEN:
	mov.b #1, 0(R1)		;change the pointer of the stack to 1
	mov.b 0(R1), &curr_state_four ;curr_state_four = 1
	mov.b #0, &red_on	      ;turn red light off
	mov.b #1, &green_on	      ;turn green light off
	ret			      ;end

        END:
	ret 			;end
