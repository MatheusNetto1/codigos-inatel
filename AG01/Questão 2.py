from sympy import Integral, Derivative, Symbol

C = 299 % 10


def v(t, c):
    return 5 * c + 7 * t ** 4 + t ** (1 / 3) - 3 * c * t ** 3


print('\n' * 100)

t = Symbol('t')

resultado = Integral(v(t, C), t).doit()
print(resultado)

resultado = Integral(v(t, C), (t, 1, 7)).doit()
print(resultado)

resultado = Derivative(v(t, C), t).doit()
print(resultado)

