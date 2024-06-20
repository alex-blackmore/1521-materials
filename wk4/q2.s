	.text
FLAG_ROWS = 6
FLAG_COLS = 12
main:
	# $t0 = row
	# $t1 = col
flag_row_init:
	li	$t0,	0
    flag_row_cond:
	bge	$t0,	FLAG_ROWS, flag_row_end
    flag_row_body:

    flag_col_init:
	li	$t1,	0
    flag_col_cond:
	bge	$t1,	FLAG_COLS, flag_col_end
    flag_col_body:
	# offset to correct inner array
	mul	$t2,	$t0,	FLAG_COLS 
	# offset to element inside inner array
	add	$t2,	$t2,	$t1
	# load from flag + row * FLAG_COLS + col
	lb	$a0,	flag($t2)
	li	$v0,	11
	syscall
    flag_col_step:
	add	$t1,	$t1,	1
	b	flag_col_cond
    flag_col_end:
	li	$a0,	'\n'
	li	$v0,	11
	syscall
    flag_row_step:
	add	$t0,	$t0,	1
	b	flag_row_cond
    flag_row_end:

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