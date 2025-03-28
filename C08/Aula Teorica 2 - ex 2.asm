.data
var_1: .asciiz "A: "
var_2: .asciiz "B: "
contr_bar_n: .asciiz "\n"
.text
# ------- ENTRADA DA VAR A -------
li $v0, 4
la $a0, var_1
syscall
li $v0, 5
syscall
add $t1, $v0, $0
# ------- ENTRADA DA VAR B -------
li $v0, 4
la $a0, var_2
syscall
li $v0, 5
syscall
add $t2, $v0, $0
# ------- PROCESSAMENTO -------
add $t0, $t1, $0
add $t1, $t2, $0
add $t2, $t0, $0
# ------- SAÍDA A -------
li $v0, 4
la $a0, var_1
syscall
li $v0, 1
add $a0, $t1, $0
syscall
# ------- QUEBRA DE LINHA -------
li $v0, 4
la $a0, contr_bar_n
syscall
# ------- SAÍDA B -------
li $v0, 4
la $a0, var_2
syscall
li $v0, 1
add $a0, $t2, $0
syscall