
init:
	li	$t0,	-5
loop_condition:
	beq	$t0,	0,	exit_loop
loop_body:
	# ...
loop_step:
	add	$t0,	$t0,	1
	b	loop_condition
exit_loop:

