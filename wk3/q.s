N_SIZE = 10
	
	.text
main:
	# $t0 = i


main__add_loop_init:
	li	$t0, 0
main__add_loop_cond:
	bge	$t0, N_SIZE, main__add_loop_end
main__add_loop_body:
	mul	$t1, $t0, 4
	lw	$t2, numbers($t1)

	bgez	$t2, main__add_loop_step

	add	$t2, $t2, 42
	sw	$t2, numbers($t1)

main__add_loop_step:
	add	$t0, $t0, 1
	b	main__add_loop_cond
main__add_loop_end:


main__read_loop_init:
	li	$t0, 0
main__read_loop_cond:
	bge	$t0, N_SIZE, main__read_loop_end
main__read_loop_body:
	# # q5
	# li	$v0, 5
	# syscall
	# # numbers + $t0 * 4
	# mul	$t1, $t0, 4 # $t1 = $t0 * 4
	# la	$t2, numbers
	# add	$t1, $t1, $t2
	# sw	$v0, ($t1)
	mul	$t1, $t0, 4
	lw	$a0, numbers($t1)

	li	$v0, 1
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

main__read_loop_step:
	add	$t0, $t0, 1
	b	main__read_loop_cond
main__read_loop_end:

	li	$v0, 0
	jr	$ra

	.data
numbers:
	.word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9
