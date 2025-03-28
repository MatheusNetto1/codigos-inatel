li $v0, 5
syscall
move $t0, $v0

li $t1, 30
bne $t0, 0, else_if
	if_true:
	add $t1, $t1, 12
	b after

	else_if:
	bgt $t0, 10, else
	
	else_if_true:
	add $t1, $t1, 39
	b after
	
	else:
	sub $t1, $t1, 10
after:
li $v0, 1
move $a0, $t1
syscall