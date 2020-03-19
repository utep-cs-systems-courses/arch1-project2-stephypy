	.arch msp430g2553
	.p2align 1,0
	.text

	.global red_on
	.global green_on
	.globl dim_green_assembly
dim_green_assembly:
	sub #2, R1
	mov.b #0, 0(R1)
	mov.b 0(R1), R12
	cmp #0, R12
	JEQ #.ZERO 		; case 0
	cmp #1, R12
	JEQ #.ONE 		;case 1
	cmp #2, R12
	JEQ #.TWO 		;case 2
	cmp #3, R12
	JEQ #.THREE 		;case 3
	cmp #4, R12
	JEQ #.FOUR 		;case 4
        .ZERO:
	mov.b #0, &red_on
	mov.b #0, &green_on
	mov.b #1, R12
	BR #.END
        .ONE:
	mov.b #0, &red_on
	mov.b #0, &green_on
	mov.b #2, R12
	BR #.END
        .TWO:
	mov.b #0, &red_on
	mov.b #0, &green_on
	mov.b #3, R12
	BR #.END
        .THREE:
	mov.b #0, &red_on
	mov.b #0, &green_on
	mov.b #4, R12
	BR #.END
        .FOUR:	
	mov.b #0, &red_on
	mov.b #1, &green_on
	mov.b #0, R12
	BR #.END
        .END:
	ret
