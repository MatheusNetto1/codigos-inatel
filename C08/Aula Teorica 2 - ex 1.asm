.data
f1: .asciiz "Entre com um n�mero inteiro: "
f2: .asciiz "\nO n�mero � PAR!"
f3: .asciiz "\nO n�mero � �MPAR"
.text

# ---------- print da mensagem inicial ----------
li $v0, 4
la $a0, f1
syscall
# ---------- entrada do n�mero ----------
li $v0, 5
syscall
add $t1, $v0, $0
# ---------- processamento ----------
li $t2, 2
div $t1, $t2
mfhi $t3

# ---------- verifica��o do resto da divis�o ----------
beqz $t3, par
	li $v0, 4
	la $a0, f3
	syscall
	j fim
par:
	li $v0, 4
	la $a0, f2
	syscall
fim:
li $v0, 10
syscall