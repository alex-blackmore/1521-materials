	.text
FLAG_ROWS = 6
FLAG_COLS = 12

SIZEOF_FLAG_ELEMENT = 1
main:
	# $t0 = row
	# $t1 = col


outer_loop_init:
	li	$t0, 0
outer_loop_cond:
	bge	$t0, FLAG_ROWS, outer_loop_end
outer_loop_body:

inner_loop_init:
	li	$t1, 0
inner_loop_cond:
	bge	$t1, FLAG_COLS, inner_loop_end
inner_loop_body:

	# flag + row * FLAG_COLS + col
	la	$t2, flag
	mul	$t3, $t0, FLAG_COLS # $t3 = row * flag_cols
	add	$t2, $t2, $t3 # $t2 = flag + row * FLAG_COLS
	add	$t2, $t2, $t1 # $t2 = flag + row * FLAG_COLS + col

	lb	$a0, ($t2)
	li	$v0, 11
	syscall

inner_loop_step:
	add	$t1, $t1, 1
	b	inner_loop_cond
inner_loop_end:
	li	$v0, 11
	li	$a0, '\n'
	syscall

outer_loop_step:
	add	$t0, $t0, 1
	b	outer_loop_cond
outer_loop_end:


	li	$v0,	0
	jr	$ra

	.data
flag:
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'