;r29 is for the brl return address

	la r31,mult	;multiply subroutine jump location
	la r30,div	;divide subroutine jump location
	la r28,quotient	;location where quotient will be stored
	la r27,end	


iter:	.equ 30		;number of digits to calculate out

	la r5,iter
	la r4,10		;10 factor for digit shift

	la r0,355	;dividend
	la r1,113	;divisor



div:	sub r0,r0,r1	;subtract divisor from dividend
	addi r2,r2,1	;increment quotient
	brzr r27,r0	;jump if there is no remainder
	brpl r30,r0	;keep subtracting until number is negative

	addi r2,r2,-1
	add r0,r0,r1
	
	st r2,quotient(r3)	;store current quotient result in memory
	addi r3,r3,4	;increment quotient storage location
	addi r5,r5,-1	;decrement decimal place counter
	brzr r27,r5	;if we have done all the decimal places we need to do, go to end
	
	la r2,0		;clear r2
	

	;brlnz r29,r5,r6	



;multiply r0 and r4, result goes in r0
	
	la r4,10		;load 10 for digit shift
mult:	add r2,r2,r0	;add factor 2 to r2
	addi r4,r4,-1	;decrement factor 1
	brnz r31,r4	;keep adding until factor 1 is 0
	addi r0,r2,0	;put result into r0 for next division
	la r2,0		;clear r2
	br r30

end:	stop

	.org 1008
quotient: .dw 1
