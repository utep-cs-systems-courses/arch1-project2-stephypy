	.arch msp430g2553

	.text
	.global dim_green_assembly
dim_green_assembly:
	sub #2, R1
	mov.b #0, 0(R1)
	mov.b 0(R1), R12
	cmp #0, R12
	JEQ ZERO
        ZERO:
	mov.b #1, &red_on
	mov.b #1, &green_on
	mov.b #1, R12
	BR #.END
        .END:
	ret
