def f(x):
    return -x**2 + 2*x + 1          # f(x) = -x² + 2x + 1

def metodo_bisseccao(a, b, criterio=0.05):
    tabela_resultados = []
    iteracoes = 0
    c = (a + b) / 2
    
    # Primeira iteração
    tabela_resultados.append([iteracoes, a, b, c, f(c)])
    
    while (b - a) / 2 > criterio:   # Critério de parada: intervalo pequeno o suficiente
        if f(c) == 0:               # Se a função for zero no ponto médio, encontramos a raiz
            break
        elif f(a) * f(c) < 0:       # Se a raiz está no subintervalo [a, c]
            b = c
        else:                       # Se a raiz está no subintervalo [c, b]
            a = c
        c = (a + b) / 2             # Ponto médio
        
        iteracoes += 1
        tabela_resultados.append([iteracoes, a, b, c, f(c)])
    
    # Exibindo os resultados
    print(f"{'n':<10}{'a':<10}{'b':<10}{"x'":<10}{"f(x')":<10}")
    print("-" * 50)
    for linha in tabela_resultados:
        print(f"{linha[0]:<10}{linha[1]:<10.4f}{linha[2]:<10.4f}{linha[3]:<10.4f}{linha[4]:<10.4f}")
    
    # Raiz aproximada
    raiz_aproximada = (a + b) / 2
    return raiz_aproximada

# Teste no intervalo [-1, 0]
raiz = metodo_bisseccao(-1, 0)
print(f"\nRaiz aproximada encontrada: {raiz:.4f}")
