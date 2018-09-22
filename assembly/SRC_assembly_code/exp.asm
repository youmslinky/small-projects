	la	r30,mult
	la	r29,exp
	la	r28,end

	la	r12,5	;base
	la	r13,3	;exponent

	la	r14,1	;start with the thing equal to 1
	la	r1,1

exp:	brzr	r28,r13
	la	r2,0
	addi	r13,r13,-1
	addi	r0,r12,0
	br	r30

mult:	add	r2,r2,r1	;multiplies r0 and r1 into r2
	addi	r0,r0,-1
	brnz	r30,r0
	addi	r1,r2,0
	br	r29



end:	stop



	.org 2000
primes:	.dc 0,1,2,3,4,5,6,7
