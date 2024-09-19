main:

	li	$t0,	0			# initialize $t0
loop_start:
	bge	$t0,	10,	loop_end	# exit the loop if $t0 >= 10
	move	$a0,	$t0
	li	$v0,	1
	syscall					# print int in $t0
	addi	$t0,	$t0,	1		# increment $t0
	b	loop_start			# loop again
loop_end:

	li	$v0,	0			# return 0
	jr	$ra