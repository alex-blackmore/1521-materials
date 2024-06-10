main:
	# $t0 = x
third_num_init:
	li	$t0,	24
third_num_cond:
	bge	$t0,	42,	third_num_end
third_num_body:
	li	$v0,	1
	move	$a0,	$t0
	syscall

	li	$v0,	11
	li	$a0,	'\n'
	syscall
third_num_step:
	add	$t0,	$t0,	3
	b	third_num_cond
third_num_end:

	li	$v0,	0
	jr	$ra