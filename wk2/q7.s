main:
	# $t0 = x
third_print_init:
	li	$t0,	24
third_print_cond:
	bge	$t0,	42,	third_print_end
third_print_body:
	li	$v0,	1
	move	$a0,	$t0
	syscall

	li	$v0,	11
	li	$a0,	'\n'
	syscall
third_print_step:
	add	$t0,	$t0,	3
	b	third_print_cond
third_print_end:

	li	$v0,	0
	jr	$ra
