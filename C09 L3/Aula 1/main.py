import numpy as np

# 1. Crie dois arrays 8x8x3, com valores aleatórios do tipo np.uint8
#  no intervalo de 0 a 10 (inclusive).
# Chame as variáveis de `a` e `b`.

a = np.random.randint(11, size=(3, 8, 8), dtype=np.uint8) # Criando as matrizes a e b
b = np.random.randint(11, size=(3, 8, 8), dtype=np.uint8)

# 2. Crie uma nova matriz `c`, cujos valores são as médias aritméticas
#  dos valores (ponto-a-ponto) das matrizes criadas no exercício 1.

c = ((a.astype(np.float32) + b.astype(np.float32)) / 2) # Calculando a média ponto a ponto e armazenando em c

# 3. Concatene as matrizes a, b e c horizontalmente, 
# e depois guarde a subarray composta pelas linhas 1 a 7 (inclusive), 
# colunas 0 a 3 (inclusive) e página 1.

concat_matrix = np.concatenate((a, b, c), axis=2) # Concatenando as matrizes ao longo do eixo das colunas (axis=2)
subarray = concat_matrix[1, 1:8, 0:4] # Extraindo a submatriz (página 1, linhas 1 a 7, colunas 0 a 3)