;r29 is for the brl return address

	la r31,mult	;multiply subroutine jump location
	la r30,div	;divide subroutine jump location
	la r28,quotient	;location where quotient will be stored
	la r27,end	
	la r26,evenDivide		;if remainder is zero, division was even, store number and stop
	la r25,round	;rounding branch location


iter:	.equ 50		;number of digits to calculate out

	la r5,iter
	;la r4,10		;10 factor for digit shift


			;355/113 gives an approximation of pi
	la r0,355		;dividend
	la r1,113		;divisor


	la r3,-4

div:	sub r0,r0,r1	;subtract divisor from dividend
	addi r2,r2,1	;increment quotient

	brpl r30,r0	;keep subtracting until number is negative


	addi r2,r2,-1	;we went past the right quotient, backup 1
	add r0,r0,r1	;backup 1


	addi r3,r3,4	;increment quotient storage location
	addi r5,r5,-1	;decrement decimal place counter
	brmi r25,r5	;if we have done all the decimal places we need to do, go to rounding

	brzr r26,r0	;jump if there is no remainder



	
	st r2,quotient(r3)	;store current quotient result in memory

	
	
	la r2,0		;clear r2




;multiply r0 and r4, result goes in r0
	
	la r4,10		;load 10 for digit shift
mult:	add r2,r2,r0	;add factor 2 to r2
	addi r4,r4,-1	;decrement factor 1
	brnz r31,r4	;keep adding until factor 1 is 0
	addi r0,r2,0	;put result into r0 for next division
	la r2,0		;clear r2
	br r30

evenDivide:
	st r2,quotient(r3)	;store current quotient result in memory
	br r27			;we are done, go to end

round:	addi r3,r3,-4		;go back one memory address, this is where we want to store rounded value
	addi r2,r2,-5		;check if number is less than five
	brmi r27,r2		;branch to end if number is less than five
	ld r6,quotient(r3)	;number is greater than 5, so round up
	addi r6,r6,1		;add 1 to number
	st r6,quotient(r3)	;store rounded number

end:	stop



	.org 1008
quotient: .dw 1
