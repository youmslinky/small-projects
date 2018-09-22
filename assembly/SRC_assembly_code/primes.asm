

	la r31,div	;divide subroutine jump location
	la r30,store	;subroutine to store found prime
	la r29,primes	;location where primes will be stored
	la r28,check	;check if divisor is equal to number
	la r27,new	;pick new number and reset

	la r8,2		;start checking primes at 2
	la r1,2		;starting multiple is 1
	la r0,2
	br r28
	

	
div:	sub r0,r0,r1	;subtract divisor from dividend
	brzr r27,r0	;start new number, this number divided evenly
	brpl r31,r0	;keep subtracting until number is negative
	addi r1,r1,1	;increment divisor
	addi r0,r8,0	;load number back into r0 to be divided

check:	sub r2,r0,r1	;check if divisor is equal to number
	brzr r30,r2	;if they are equal, number is prime
	br r31
	


store:	st r1,primes(r3)	;store current quotient result in memory
	addi r3,r3,4	;increment prime storage location pointer
new:	addi r8,r8,1	;increment number to check by 1
	addi r0,r8,0
	la r1,2		;start the divisor at 2 again
	br r31		;go back and try the new number
	
	;brlnz r29,r5,r6	




	.org 992
primes: .dw 1
