def f(x):
    return -x**2 + 2*x + 1          # Função: -x² + 2x + 1

def df(x):
    return -2*x + 2                 # Derivada: -2x + 2

def encontrar_intervalos(a, b, passo=1):
    intervalos = []
    print(f"{'x':^5} | {'f(x)':^8} | {'f\'(x)':^8}")
    print("-" * 28)
    
    x_atual = a
    
    while x_atual <= b:
        x_prox = x_atual + passo
        fx_atual = f(x_atual)
        fx_prox = f(x_prox)
        dfx_atual = df(x_atual)
        dfx_prox = df(x_prox)

        # Exibir linha da tabela
        print(f"{x_atual:^5} | {fx_atual:^8.2f} | {dfx_atual:^8.2f}")

        # Se houver mudança de sinal e a derivada não mudar de sinal, armazenamos o intervalo
        if fx_atual * fx_prox < 0 and dfx_atual * dfx_prox > 0:
            intervalos.append((x_atual, x_prox))
        
        x_atual = x_prox

    return intervalos

# Teste no intervalo [-3, 3]
intervalos_raizes = encontrar_intervalos(-3, 3, 1)
print("\nOs intervalos que possuem raízes são:", intervalos_raizes)