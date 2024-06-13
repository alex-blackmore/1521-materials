N_SIZE = 10
	.text
main:

loop_init:
	li	$t0,	0
loop_cond:
	bge	$t0,	N_SIZE,	loop_end
loop_body:
	# q7

	mul	$t1,	$t0,	4
	lw	$t2,	array($t1)	# read from array[i] into $t2
	bgez	$t2, loop_step

	add	$t2,	$t2,	42
	sw	$t2,	array($t1)	# IMPORTANT!!! update array[i] to new value in $t2

	# q6
	mul	$t1,	$t0,	4
	lw	$a0,	array($t1)	# read from array[i] into $a0 for print_int syscall
	li	$v0,	1
	syscall

	li	$a0,	'\n'
	li	$v0,	11
	syscall

	#q5
	li	$v0,	5
	syscall

	mul	$t1,	$t0,	4
	sw	$v0,	array($t1)	# save $v0 to array[i]

loop_step:
	add	$t0,	$t0,	1
	b	loop_cond
loop_end:

	li	$v0,	0
	jr	$ra

	.data
array:
	.word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9
	