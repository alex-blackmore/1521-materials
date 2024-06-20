	.text
sum4:
sum4__prologue:
	push	$ra
	push	$s0
	push	$s2
	push	$s3
sum4_body:
	# save $a2 and $a3
	move	$s2,	$a2
	move	$s3,	$a3
# $a0 and $a1 already contain a and b
	jal	sum2 
	move	$s0,	$v0

	move	$a0,	$s2
	move	$a1,	$s3
	jal	sum2
	move	$t1,	$v0

	move	$a0,	$s0
	move	$a1,	$t1
	jal	sum2	
sum4_epilogue:
	pop	$s3
	pop	$s2
	pop	$s0
	pop	$ra
	jr	$ra

sum2:
sum2__prologue:
sum2_body:
	add	$v0,	$a0,	$a1
sum2_epilogue:
	jr	$ra

main:
main__prologue:
	push	$ra
main__body:
	li	$a0,	11
	li	$a1,	13
	li	$a2,	17
	li	$a3,	19

	jal	sum4

	move	$a0,	$v0
	li	$v0,	1
	syscall

	li	$a0,	'\n'
	li	$v0,	11
	syscall

	li	$v0,	0
main__epilogue:
	pop	$ra
	jr	$ra