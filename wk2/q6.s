main:
	# $t0 = x
	li	$v0,	4
	la	$a0,	prompt
	syscall

	li	$v0,	5
	syscall
	move	$t0,	$v0

size_x_gt_100:
	bgt	$t0, 100, size_x_lt_1000
	b	size_else
size_x_lt_1000:
	blt	$t0, 1000, size_body
	b	size_else
size_body:
	li	$v0, 4
	la	$a0, medium
	syscall
	b	size_end
size_else:
	li	$v0,	4
	la	$a0, small_big
	syscall
size_end:

	li	$v0,	0
	jr	$ra

	.data
prompt:
	.asciiz "Enter a number: "
medium:
	.asciiz "medium\n"
small_big:
	.asciiz "small/big\n"