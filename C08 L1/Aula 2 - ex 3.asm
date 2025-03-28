.data
print_1: .asciiz "You shall not pass!\n"
print_2: .asciiz "Even with "
print_3: .asciiz " years, you shall NOT pass!\n"
print_4: .asciiz "Welcome sir\n"
.text

#read age
li $v0, 5
syscall
move $t0, $v0

#read cool
li $v0, 5
syscall
move $t1, $v0

bge $t0, 18, after_1
if_1:
	li $v0, 4
	la $a0, print_1
	syscall
	
	b after_1
after_1:
bne $t1, 0, after_2
if_2:
	li $v0, 4
	la $a0, print_2
	syscall
	
	li $v0, 1
	move $a0, $t0
	syscall
	
	li $v0, 4
	la $a0, print_3
	syscall
	
	li $v0, 17
	li $a0, 1
	syscall
	
	b after_2
after_2:
li $v0, 4
la $a0, print_4
syscall

li $v0, 17
li $a0, 1
syscall