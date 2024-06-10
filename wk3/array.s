	.text
main:
	# write to array[0]
	li	$t0,	1
	sw	$t0,	array

	# write to array[4]
	li	$t1,	4
	li	$t0,	1
	sw	$t0,	array($t1) 
	# array($t1) = array + 4 = 5th element = array[4]

	# read from array[0]
	lw	$t1,	array

	# use a loop to set array to 42
set_array_loop_init:
	li	$t0,	0	# i = 0
set_array_loop_cond:
	bge	$t0,	16,	set_array_loop_end	# exit loop if i >= array len
set_array_loop_body:
	li	$t1,	42
	sw	$t1,	array($t0)	# save to memory address (array + i)
set_array_loop_step:
	add	$t0,	$t0,	1	# increment i
	b	set_array_loop_cond
set_array_loop_end:

	# read array[11]
	li	$t1,	11
	lw	$t0,	array($t1)	# read from address (array + 11)

	li	$v0,	0
	jr	$ra

	.data
array:
	.byte 0:16