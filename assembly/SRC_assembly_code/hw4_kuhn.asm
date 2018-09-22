;	date:2/23/2017
;
;
;
;

	.org	1000
	ld	r1,op1
	ld	r2,op2
	ld	r3,operator
	lar	r4,result
	lar	r8,end
	lar	r10,multiplication
	lar	r12,division

	lar	r17,prep
	lar	r13,aa
	lar	r14,bb
	lar	r15,loop1
	lar	r16,store

	la	r20,0
	brpl	r13,r1
	neg	r1,r1
	addi	r20,r20,1

aa:	brpl	r14,r2	;check the sign of the second operand
	neg	r2,r2	;if the signe is negative, make it positive
	addi	r20,r20,1	

bb:	addi	r22,r1,0	



	addi	r5,r3,-42
	brzr	r10,r5
	addi	r5,r3,-47
	brzr	r12,r5
	br	r8

multiplication:

	;la	r6,0
	brzr	r8,r1
	brzr	r8,r2		;go to end if either operand is zero

loop1:	add	r6,r2,r6
	addi	r22,r22,-1	;decremnt the value of r22
	brnz	r15,r22		;if r22's value is nonzero go to loop1
	;br	r17

prep:	addi	r20,r20,-1
	brnz	r16,r20
	neg	r6,r6	;CODE HERE
store:	st	r6,0(r4)	;CODE HERE
	br	r8	;CODE HERE


division:
	neg	r22,r22
	;lar	r30,loop2
	lar	r31,valid	;valid means operand 2 is not zero
	brnz	r31,r2
	la	r6,-1		;value to store if operand 2 is zero
	br	r16
	

valid:	addi	r6,r6,1
	add	r22,r22,r2
	brzr	r17,r22
	brmi	r31,r22
	addi	r6,r6,-1
	br	r17





end:	stop
	.org	3000
op1:	.dc	-1	;any integer value
op2:	.dc	-5	;any integer value

operator:
	.dc	"*"	;either '*' or '/'


result:	.dw	1	;storage for result








