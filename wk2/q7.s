main:
	# $t0 = x
third_init:
	li	$t0, 24
third_cond:
	bge	$t0, 42, third_end
third_body:
	li	$v0, 1
	move	$a0, $t0
	syscall

	li	$v0, 11
	li	$a0, 10
	syscall
third_step:
	add	$t0, $t0, 3
	b	third_cond
third_end:

	li	$v0, 0
	jr	$ra