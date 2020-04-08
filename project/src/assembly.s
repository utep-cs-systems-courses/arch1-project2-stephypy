	.arch msp430g2553
	.p2align 1, 0

	;; Represents the state
	.data
light:
	.word 1

	;; Jump table
	.text
jt:
	.word default 		; jt[0]
	.word red 		; jt[1]
	.word green 		; jt[2]
	
	
	.text
	.global red_green_assembly
red_green_assembly:
	;; Range check does not work
	cmp #3, &light
	jnc default
	
	mov &light, r12
	add r12, r12 		
	mov jt(r12), r0

	;; switch statements
green:
	mov.b #0, &red_on
	mov.b #1, &green_on 	; Turn on Green Light
	mov #0, &light 		; Move to default 
	jmp end
	
red:
	mov.b #1, &red_on 	; Turn on Red Light
	mov.b #0, &green_on
	add #1, &light 		; Move to Green State
	jmp end

default:
	mov #1, &light 		; Restart light to be 1

end:
	ret 			; pop r0
