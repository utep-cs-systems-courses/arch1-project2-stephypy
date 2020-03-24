	.arch msp430g2553
	
	.text
	.global red_green_assembly
red_green_assembly:
	cmp.b #1, &red_on 	; Check whether red light is on
	jeq green		; If red is on, go to green

	mov.b #1, &red_on	; Turn on red light
	mov.b #0, &green_on	; Turn off green light
	jmp end 		; Go to end

green:	mov.b #0, &red_on 	; Turn off red light
	mov.b #1, &green_on 	; Turn on green light
	jmp end 		; Go to end

end:	ret 			; End program
