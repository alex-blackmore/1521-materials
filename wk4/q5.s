	.text
sum4:
sum4__prologue:
    push    $ra
    push    $s0
    push    $s1
    push    $s2
sum4_body:

    move    $s1, $a2
    move    $s2, $a3

    jal sum2
    move    $s0, $v0

    move    $a0, $s1
    move    $a1, $s2
    jal sum2

    move    $a0, $s0
    move    $a1, $v0
    jal sum2

sum4_epilogue:
    pop $s2
    pop $s1
    pop $s0
    pop $ra
	jr	$ra

sum2:
sum2__prologue:
sum2_body:
    add $v0, $a0, $a1
sum2_epilogue:
	jr	$ra

main:
main__prologue:
    push $ra
main__body:

    li  $a0, 11
    li  $a1, 13
    li  $a2, 17
    li  $a3, 19
    jal sum4

    move    $a0, $v0
    li  $v0, 1
    syscall

    li  $v0, 11
    li  $a0, '\n'
    syscall


main__epilogue:
    pop $ra
	li	$v0, 0
	jr	$ra