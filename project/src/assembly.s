	.arch msp430g2553
	
	.text
	.global dim_green_assembly
dim_green_assembly:
	sub #2, R1
	cmp #0, &curr_state_four
	JEQ ON
	
	mov.b #0, 0(R1)
	mov.b 0(R1), &curr_state_four
	mov.b #1, &red_on
	mov.b #0, &green_on
	JMP END
	
        ON:
	mov.b #1, 0(R1)
	mov.b 0(R1), &curr_state_four
	mov.b #0, &red_on
	mov.b #1, &green_on
	ret

        END:
	ret
