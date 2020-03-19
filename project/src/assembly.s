	.arch msp430g2553
	
	.global red_on
	.global green_on
dim_green_assembly:	
	mov.b &curr_state_four, R12
	cmp #0, R12
	JEQ FIRST
        FIRST:
	mov.b #4, R12
