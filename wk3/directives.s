	.text
main:
	la	$a0,	one
	li	$v0,	1
	syscall

	li	$a0,	'\n'
	li	$v0,	11
	syscall

	la	$a0,	two
	li	$v0,	1
	syscall

	li	$a0,	'\n'
	li	$v0,	11
	syscall

	la	$a0,	three
	li	$v0,	1
	syscall

	li	$a0,	'\n'
	li	$v0,	11
	syscall

	li	$v0,	0
	jr	$ra

	.data
one:
	.byte 1
two:
	.byte 2

	.align 2
three:
	.byte 3