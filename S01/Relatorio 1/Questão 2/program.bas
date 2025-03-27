REM Exercício 2:
10 LET x = RND(10)
20 LET FATORIAL = 1

30 FOR i = x TO 1 STEP -1
40  FATORIAL = FATORIAL * i
50 NEXT i

60 PRINT "Fatorial de " + x + ": " + FATORIAL