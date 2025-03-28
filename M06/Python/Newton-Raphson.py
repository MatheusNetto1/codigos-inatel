def f(x):
    return -x**2 + 2*x + 1              # f(x) = -x² + 2x + 1

def df(x):
    return -2*x + 2                     # Derivada: f'(x) = -2x + 2

def metodo_newton_raphson(a, b, criterio=0.05):
    iteracoes = 0
    x0 = (a + b) / 2
    x = x0
    tabela_resultados = []

    # Primeira iteração
    tabela_resultados.append([iteracoes, x, f(x), df(x)])

    while abs(f(x)) > criterio:         # Critério de parada: |f(x)| < 0.05
        x = x - f(x) / df(x)            # Fórmula de Newton-Raphson
        iteracoes += 1
        tabela_resultados.append([iteracoes, x, f(x), df(x)])
    
    # Exibindo os resultados
    print(f"{'n':<10}{'x\'':<10}{'f(x\')':<10}{'f\'(x\')':<10}")
    print("-" * 50)
    for linha in tabela_resultados:
        print(f"{linha[0]:<10}{linha[1]:<10.4f}{linha[2]:<10.4f}{linha[3]:<10.4f}")
    
    # Raiz aproximada
    return x

# Teste no intervalo [2, 3]
raiz = metodo_newton_raphson(2, 3)
print(f"\nRaiz aproximada encontrada: {raiz:.4f}")