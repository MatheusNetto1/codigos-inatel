from sympy import Limit, Symbol, S

C = 299 % 10


def funcao(x):
    return (2*x**2 - 7)/(7*x**5 - 2)


print('\n' * 100)

x = Symbol('x')

resultado = Limit(funcao(x), x, 1).doit()
print(resultado * (C + 1))

resultado = Limit(funcao(x), x, S.Infinity).doit()
print(resultado * (C + 1))

resultado = Limit(funcao(x), x, -S.Infinity).doit()
print(resultado * (C + 1))