	.text
main:
	# $t0 = x
	# $t1 = y
	
	li	$v0, 4
	la	$a0, prompt
	syscall

	li	$v0, 5
	syscall
	move	$t0, $v0

	mul	$t1, $t0, $t0

	li	$v0, 1
	move	$a0, $t1
	syscall

	li	$v0, 11
	li	$a0, 10
	syscall

	li	$v0, 0
	jr	$ra

	.data
prompt:
	.asciiz "Enter a number: "