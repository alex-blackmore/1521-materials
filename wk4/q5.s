	.text
sum4:
sum4__prologue:
	push	$s0
sum4_body:
	move	$s0, $a0
	move	$s1, $a1
	move	$s2, $a2
	move	$s3, $a3


	jal	sum2
	move	$s0, $v0


	move	$a0, $s2
	move	$a1, $s3
	jal	sum2
	move	$s1, $v1

	move	$a0, $s0
	move	$a1, $s1
	jal 	sum2

	move	$t0, $v0

	move	$v0, $t0
sum4_epilogue:
	jr	$ra

sum2:
sum2__prologue:
sum2_body:
sum2_epilogue:
	jr	$ra

main:
main__prologue:
main__body:
main__epilogue:
	jr	$ra