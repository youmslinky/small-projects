define	op1	$40
define	op2	$50
define	result	$60


	lda	#$09	;this operand will be left shi
	sta	op1
	lda	#$09	;this operand will be right shi
	sta	op2


mult:	and	#$01	;is odd?
	beq	even	;it is even, don't add it
	lda	result	;load current sum
	adc	op1	;add 1st operand
	sta	result	;store the new sum
	
even:	lsr	op2
	beq	done
	asl	op1
	lda	op2	;load operand to test for odd
	bvc	mult
	
	
done:	nop
	nop
	nop
	bcc	done