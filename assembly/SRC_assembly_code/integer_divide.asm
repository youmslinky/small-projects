;r2 will be for quotient
;r3 will be for remainder

	la r31,loop	;loop jump location
	la r30,remain	;remainder jump location

	la r0,987		;dividend
	la r1,57		;divisor



loop:	sub r0,r0,r1	;subtract divisor from dividend
	brzr r30,r0	;jump if there is no remainder
	addi r2,r2,1	;increment quotient
	brpl r31,r0	;keep subtracting until number is negative

	addi r2,r2,-1
	add r0,r0,r1
remain:	