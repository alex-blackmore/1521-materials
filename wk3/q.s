N_SIZE = 10
	
	.text
main:
	# $t0 = i


main__read_loop_init:
	li	$t0, 0
main__read_loop_cond:
	bge	$t0, N_SIZE, main__read_loop_end
main__read_loop_body:

    # read input
    li  $v0, 5
    syscall
    move    $t1, $v0

    # calculate address
    # numbers + ($t0 * 4)
    move    $t2, $t0    # i
    mul     $t2, $t2, 4 # i * 4
    add     $t2, $t2, numbers # number + i * 4

    # actually save it
    sw      $t1, ($t2)
main__read_loop_step:
	add	$t0, $t0, 1
	b	main__read_loop_cond
main__read_loop_end:


main__print_loop_init:
	li	$t0, 0
main__print_loop_cond:
	bge	$t0, N_SIZE, main__print_loop_end
main__print_loop_body:

    # calculate address
    # numbers + ($t0 * 4)
    move    $t2, $t0    # i
    mul     $t2, $t2, 4 # i * 4
    add     $t2, $t2, numbers # number + i * 4

    li      $v0, 1
    lw      $a0, ($t2)
    syscall

    li      $v0, 11
    li      $a0, '\n'
    syscall

main__print_loop_step:
	add	$t0, $t0, 1
	b	main__print_loop_cond
main__print_loop_end:

	li	$v0, 0
	jr	$ra

	.data
numbers:
    .word 0:10
	# .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    # .word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9
