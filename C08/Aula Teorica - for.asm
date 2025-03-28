li $t0, 5	# x
li $t1, 0	# y
li $t2, 1	# j

volta:
ble $t2, $t0, repete
j fim
repete: addi $t1, $t1, 1
	addi $t2, $t2, 1
	j volta
fim: