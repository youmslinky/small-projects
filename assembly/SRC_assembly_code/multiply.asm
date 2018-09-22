;r2 will be for quotient
;r3 will be for remainder

	la r31,loop	;loop jump location


	la r0,20		;factor 1
	la r1,5		;factor 2



loop:	add r2,r2,r1	;add factor 2 to r2
	addi r0,r0,-1	;decrement factor 1
	brnz r31,r0	;keep adding until factor 1 is 0
