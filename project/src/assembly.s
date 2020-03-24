	.arch msp430g2553
	
	.text
	.global red_green_assembly
red_green_assembly:
	cmp.b #1, &red_on
	jeq green

	mov.b #1, &red_on
	mov.b #0, &green_on
	jmp end

green:	mov.b #0, &red_on
	mov.b #1, &green_on
	jmp end

end:	ret
