	.arch msp430g2553
	.p2align 1,0
	.text

	.global red_on
advance_red_led_state:
	 add #1, &red_on
