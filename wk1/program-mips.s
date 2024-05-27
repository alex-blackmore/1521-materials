.text

main:
	la	$a0,	s1
	li	$v0,	4
	syscall
	li	$v0,	0
	jr	$ra

.data

s1:
	.asciiz "I love COMP1521\n"