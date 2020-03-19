	.arch msp430g2553
	.p2align 1,0
	.text

dim_green_assembly:	
	sub.w   #2, R1
	mov.b   #0, 1(R1)
	nop
	add.w   #2, R1
	ret
