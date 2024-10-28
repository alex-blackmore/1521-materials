	.text
FLAG_ROWS = 6
FLAG_COLS = 12
main:
	# $t0 = row
	# $t1 = col

main__row_loop_init:
	li	$t0, 0
main__row_loop_cond:
	bge	$t0, FLAG_ROWS, main__row_loop_end
main__row_loop_body:

main__col_loop_init:
	li	$t1, 0
main__col_loop_cond:
	bge	$t1, FLAG_COLS, main__col_loop_end
main__col_loop_body:
	la	$t3, flag
	mul	$t4, $t0, FLAG_COLS

	add	$t3, $t3, $t4	# arr + row * 12
	add	$t3, $t3, $t1	# arr + row * 12 + col

	lb	$a0, ($t3)
	li	$v0, 11
	syscall
main__col_loop_step:
	add	$t1, $t1, 1
	b	main__col_loop_cond
main__col_loop_end:

	li	$a0, '\n'
	li	$v0, 11
	syscall

main__row_loop_step:
	add	$t0, $t0, 1
	b	main__row_loop_cond
main__row_loop_end:


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