	.org	2000000
	lar	r31,loop
	lar	r30,even
	lar	r29,end



	la	r0,10
	lar	r1,89



loop:	andi	r3,r0,1		;is odd?
	brzr	r30,r3
	add	r2,r2,r1		;it is odd, add to sum
even:	shr	r0,r0,1		;interger half number
	brzr	r29,r0
	shl	r1,r1,1		;double number
	br	r31
	
end:	stop

	.org	2000
inter:	.dw	1