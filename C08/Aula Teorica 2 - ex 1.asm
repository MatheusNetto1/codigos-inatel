.data
f1: .asciiz "Entre com um número inteiro: "
f2: .asciiz "\nO número é PAR!"
f3: .asciiz "\nO número é ÍMPAR"
.text

# ---------- print da mensagem inicial ----------
li $v0, 4
la $a0, f1
syscall
# ---------- entrada do número ----------
li $v0, 5
syscall
add $t1, $v0, $0
# ---------- processamento ----------
li $t2, 2
div $t1, $t2
mfhi $t3

# ---------- verificação do resto da divisão ----------
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