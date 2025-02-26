main:
	# $t0 = x
	li	$v0, 4
	la	$a0, prompt
	syscall

	li	$v0, 5
	syscall
	move	$t0, $v0

medium_cond1:
    bgt	$t0, 100, medium_cond2
    b medium_else
medium_cond2:
    blt $t0, 1000, medium_body;
    b medium_else
medium_body:
    li	$v0, 4
    la	$a0, medium
    syscall

    b medium_end
medium_else:
    li	$v0, 4
    la	$a0, small_big
    syscall
medium_end:

	li	$v0, 0
	jr	$ra
	.data
prompt:
	.asciiz "Enter a number: "
medium:
	.asciiz "medium\n"
small_big:
	.asciiz "small/big\n"