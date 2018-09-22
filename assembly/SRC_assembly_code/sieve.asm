
	la	r30,end
	la	r29,primes
	la	r28,enum
	la	r27,elim
	la	r26,new
	la	r25,loop
	la	r24,fac

number:	.equ	10	;max number put into sieve

	
	la	r0,number
	la	r1,1		;starting at 2
enum:	addi	r1,r1,1
	st	r1,2000(r2)
	addi	r2,r2,4
	sub	r3,r0,r1
	brnz	r28,r3
	


	
	la	r8,-4
	la	r1,1

new:	la	r9,0
	la	r11,0
	la	r1,0
	addi	r8,r8,4
	ld	r4,2000(r8)
	brzr	r26,r4		;if the number in memory is 0, we can skip it, load another memory address over
	
	la	r5,4		;multiplier for memory location
	
elim:	add	r9,r9,r4
	addi	r5,r5,-1
	brnz	r27,r5
	
fac:	addi	r10,r1,0		;copy current multiple (r2)
loop:	add	r11,r11,r9
	addi	r10,r10,-1
	brnz	r25,r10

	ld	r12,2000(r11)	;read value to check if it is higher than number
	st	r22,2000(r11)	;write a zero to this number, it is a multiple of current number
	sub	r13,r12,r0
	brpl	r26,r13		;if the value is bigger than max number, pick next number
	addi	r1,r1,1		;increment multiple to remove
	la	r11,0		;clear current address
	br	r24





end:	stop



	.org 2000
primes:	.dw number
