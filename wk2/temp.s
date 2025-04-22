main:
	li	$v0, 5
	syscall
	move	$t0, $v0

	li	$v0, 5
	syscall
	move	$t1, $v0

# only run if $t0 == 1 && $t1 == 2
# otherwise, run something esle
	



	beq	$t0, 1, second_cond
	b	else
second_cond:
	beq	$t1, 2, body
	b	else
body:
	li	$v0, 4
	la	$a0, str_body
	syscall

	b	end
else:
	li	$v0, 4
	la	$a0, str_else
	syscall
end:

	li	$v0, 0
	jr	$ra
	.data
string:
	.asciiz "Hello World!\n"
str_else:
	.asciiz "Else\n"
str_body:
	.asciiz "Body\n"