	.text
main:
	la	$a0,	str_prompt
	li	$v0,	4
	syscall					# print prompt

	la	$v0,	5
	syscall					# read integer

	move	$t0,	$v0			# save in $t0

	rem	$t1,	$t0,	2		# $t1 = $t0 % 2
	beq	$t1,	1,	number_odd	# if $t1 == 1 then $t0 was odd
	# otherwise we will execute even branch
number_even:
	li	$v0,	4
	la	$a0,	str_even
	syscall					# print even message
number_odd:
	li	$v0,	4
	la	$a0,	str_odd
	syscall					# print odd message


	li	$v0,	0			# return 0
	jr	$ra


	.data
str_prompt:
	.asciiz "Enter a number"
str_even:
	.asciiz "Your number is odd!\n"
str_odd:
	.asciiz "Your number is even!\n"
