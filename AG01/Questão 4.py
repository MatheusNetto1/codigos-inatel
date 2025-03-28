from sympy import Symbol, solve

C = 299 % 10

V1 = 7 + (5 * C)
V2 = 4 + (2 * C)
V3 = 3 + (4 * C)


def esquerda(i1, i2, v1, v2):
    return -v1 + 15000 * i1 + v2 + 5000 * (i1 - i2)


def direita(i1, i2, v2, v3):
    return 5000 * (i2 - i1) - v2 + 10000 * i2 + v3

print('\n' * 100)

i1 = Symbol('i1')
i2 = Symbol('i2')

A = esquerda(i1, i2, V1, V2)
B = direita(i1, i2, V2, V3)

resultado = solve((A, B))
print(resultado)