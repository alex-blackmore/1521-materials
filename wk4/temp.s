main:
main_prologue:
	push	$ra		# save original $ra
main_body:
	# call functions
	# pass arguments
	# return a value

	# clobbering
	# saving registers 
	# saving $ra


	li	$a0, 1
	li	$a1, 'x' 	# pass arguments

	li	$s0,	42

	jal	function 	# set $ra to next instr

	move	$a0,	$s0
	li	$v0,	1
	syscall

	move	$t0,	$v0	# return value in $v0


	li	$a0,	1
	li	$v0,	1
	syscall


	li	$v0, 0


main_epilogue:
	pop	$ra	# restore original $ra
	jr	$ra


# function
# arguments:
# - int x in $a0
# - char y in $a1
#
function:
function_prologue:
	push	$s0	# save original value of $s0 onto the stack
	push	$s1	# 
function_body:
	li	$s0,	3
	li	$s1, 2
	# ...
	# ...
	li	$v0,	3 	# return something
function_epilogue:
	pop	$s1	# 
	pop	$s0	# take original value on stack, save into $s0
	jr	$ra