	.text
main:
	li	$v0,	5
	syscall

	move	$t0,	$v0

	sw	$t0,	var	# save user input into memory

	lw	$t1,	var	# load value from memory into a different register

	move	$a0,	$t1
	li	$v0,	1
	syscall

	li	$a0,	'\n'
	li	$v0,	11
	syscall

	li	$v0,	0
	jr	$ra

	.data
var:
	.word 0