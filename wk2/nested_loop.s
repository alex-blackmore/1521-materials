	.text
main:

	# $t0 = i, $t1 = j
outer_init:
	li	$t0, 0
outer_cond:
	bge	$t0, 10, outer_end
outer_body:

inner_init:
	li	$t1, 0
inner_cond:
	bge	$t1, 10, inner_end
inner_body:
	# ... some code
inner_step:
	add	$t1, $t1, 1
	b	inner_cond
inner_end:

outer_step:
	add	$t0, $t0, 1
	b	outer_cond
outer_end:


