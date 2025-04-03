.data
f1: .asciiz "Entre com um n�mero inteiro A: "
f2: .asciiz "Entre com um n�mero inteiro B: "
f3: .asciiz "\nQual � a opera��o? 0[sair] 1[soma] 2[sub] 3[mult] 4[div] "
f4: .asciiz "O resultado �: "
.text

# ---------- declara��o das vari�veis de comparaca��o ----------
li $t0, 1	# soma
li $t1, 2	# subtra��o
li $t2, 3	# multiplica��o
li $t3, 4	# divis�o

# ---------- print da mensagem A ----------
li $v0, 4	# salva em $v0 o c�digo do syscall 4 (print de string)
la $a0, f1	# salva em $a0 o endere�o da frase 1
syscall		# chama a interruo��o com o c�digo salvo em $v0 e executa o que t� em $a0
# ---------- entrada do n�mero A ----------
li $v0, 5		# salva em $v0 o c�digo do syscall 5 (leitura de int)
syscall			# chama a interrup��o com o c�digo salvo em $v0 e salva a entrada em $v0
add $t4, $v0, $0	# guarda em $t4 a soma do valor entrado em $v0 + 0

# ---------- print da mensagem B ----------
li $v0, 4	# salva em $v0 o c�digo do syscall 4 (print de string)
la $a0, f2	# salva em $a0 o endere�o da frase 2
syscall		# chama a interruo��o com o c�digo salvo em $v0 e executa o que t� em $a0
# ---------- entrada do n�mero B ----------
li $v0, 5		# salva em $v0 o c�digo do syscall 5 (leitura de int)
syscall			# chama a interrup��o com o c�digo salvo em $v0 e salva a entrada em $v0
add $t5, $v0, $0	# guarda em $t5 a soma do valor entrado em $v0 + 0

# ---------- print da mensagem OP ----------
li $v0, 4	# salva em $v0 o c�digo do syscall 4 (print de string)
la $a0, f3	# salva em $a0 o endere�o da frase 3
syscall		# chama a interruo��o com o c�digo salvo em $v0 e executa o que t� em $a0
# ---------- entrada do n�mero OP ----------
li $v0, 5		# salva em $v0 o c�digo do syscall 5 (leitura de int)
syscall			# chama a interrup��o com o c�digo salvo em $v0 e salva a entrada em $v0
add $t6, $v0, $0	# guarda em $t6 a soma do valor entrado em $v0 + 0

repeticao:	beqz $t6, fim			# se $t6 (OP) = 0, sai da repeti��o
		beq $t6, $t0, soma		# se $t6 (OP) = 1, soma A e B
		beq $t6, $t1, subtracao		# se $t6 (OP) = 2, subtrai A e B
		beq $t6, $t2, multiplicacao	# se $t6 (OP) = 3, multiplica A e B
		beq $t6, $t3, divisao		# se $t6 (OP) = 4, divide A e B
		
soma:		add $t7, $t4, $t5		# soma A e B e salva em $t7
		j condicao			# pula para a condi��o
		
subtracao:	sub $t7, $t4, $t5		# subtrai A e B e salva em $t7
		j condicao			# pula para a condi��o
		
multiplicacao:	mul $t7, $t4, $t5		# multiplica sem overflow A e B e salva em $t7
		j condicao			# pula para a condi��o
		
divisao:	div $t7, $t4, $t5		# divide sem overflow A e B e salva em $t7
		j condicao			# pula para a condi��o
		
condicao:	li $v0, 4		# salva em $v0 o c�digo do syscall 4 (print de string)
		la $a0, f4		# salva em $a0 o endere�o da frase 4
		syscall			# chama a interruo��o com o c�digo salvo em $v0 e executa o que t� em $a0
		li $v0, 1		# salva em $v0 o c�digo do syscall 1 (print de int)
		add $a0, $t7, $0	# salva em $a0 o valor de $t7 + 0
		syscall			# chama a interruo��o com o c�digo salvo em $v0
		# ---------- print da mensagem OP ----------
		li $v0, 4
		la $a0, f3
		syscall
		# ---------- entrada do n�mero OP ----------
		li $v0, 5
		syscall
		add $t6, $v0, $0
		j repeticao
fim: