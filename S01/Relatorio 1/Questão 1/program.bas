REM Exercicio 1:
10 INPUT "Digite o valor de a: "; a
20 INPUT "Digite o valor de b: "; b
30 INPUT "Digite o valor de c: "; c

40 DELTA = b * b - 4 * a * c

50 IF DELTA < 0 OR a = 0 THEN PRINT "A equação não possui raízes reais." ELSE GOTO 70
60 IF DELTA < 0 OR a = 0 THEN GOTO 120

70 LET x1 = (-b + SQR(DELTA)) / (2 * a) 
80 LET x2 = (-b - SQR(DELTA)) / (2 * a)

90 PRINT "As raízes da equação são:"
100 PRINT "x1 = " + x1
110 PRINT "x2 = " + x2
120 PRINT "Fim do programa!"