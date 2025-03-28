from sympy import Symbol, solve, sin, exp

C = 299 % 10


def F1(x, c):
    return exp(x - 3) + exp(x - 1) + exp(x) - c - 1


def F2(x, c):
    return x ** 4 - 4 * x ** 3 + 3 * x - c


def F3(x, c):
    return 4 * sin(x * (c + 1)) + 2

print('\n' * 100)

x = Symbol('x')

P = F1(x, C)
resultado = solve(P)
print(resultado)

Q = F2(x, C)
resultado = solve(Q)
print(resultado)

R = F3(x, C)
resultado = solve(R)
print(resultado)