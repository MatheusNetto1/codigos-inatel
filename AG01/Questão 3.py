from sympy import Integral, Symbol

C = 299 % 10


def F(x, c):
    return 5 * x ** 3 + ((x / 3) ** 3) ** (1 / 5) + (3 / 4) * x - 3 * c


print('\n' * 100)

x = Symbol('x')

resultado = Integral(F(x, C), (x, 3, 8)).doit()
print(resultado)