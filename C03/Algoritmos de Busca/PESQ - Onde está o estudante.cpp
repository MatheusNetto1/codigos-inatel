#include <iostream>

using namespace std;

// Função de busca binária
int binaria(int vetor[], int tamanho, int x)
{
    bool achou;                 // Variável auxiliar para controle da busca
    int baixo, meio, alto;      // Variáveis auxiliares para os limites e o meio do intervalo de busca

    baixo = 0;                  // Limite inferior do intervalo de busca
    alto = tamanho - 1;         // Limite superior do intervalo de busca
    achou = false;              // Inicialmente, o elemento não foi encontrado

    // Executa a busca enquanto a posição inferior não ultrapassar a superior e o elemento não for encontrado
    while ((baixo <= alto) && (achou == false))
    {
        meio = (baixo + alto) / 2;       // Encontra o índice do meio do intervalo de busca

        if (x < vetor[meio])
            alto = meio - 1;             // Se x for menor que o elemento do meio, atualiza o limite superior
        else if (x > vetor[meio])
            baixo = meio + 1;            // Se x for maior que o elemento do meio, atualiza o limite inferior
        else
            achou = true;                // Elemento encontrado
    }

    if (achou)
        return meio;                     // Retorna o índice do elemento encontrado
    else
        return -1;                       // Retorna -1 para indicar que o elemento não foi encontrado
}

int main()
{
    int i;                                      // Contador para iterar sobre o vetor durante o preenchimento
    int n;                                      // Armazena o tamanho do vetor informado pelo usuário
    int vetor[10000];                           // Vetor declarado com o tamanho fixo de 10000 elementos
    int x;                                      // Armazena o valor a ser buscado no vetor
    int ver;                                    // Armazena o resultado da busca binária, índice onde foi encontrado ou -1 se não foi

    cin >> n;                                   // Lê o tamanho do vetor a ser preenchido

    // Preenche o vetor com os elementos informados pelo usuário
    for (i = 0; i < n; i++)
    {
        cin >> vetor[i];                        // Lê cada elemento e armazena no vetor
    }

    cin >> x;                                   // Lê o valor a ser buscado

    ver = binaria(vetor, n, x);                 // Chama a função de busca binária para encontrar o valor no vetor

    if (ver == -1)
    {
        cout << "Nao localizado" << endl;       // Imprime mensagem indicando que o valor não foi encontrado no vetor
    }
    else
    {
        cout << "Corredor: " << ver << endl;    // Imprime o índice do valor encontrado no vetor (corredor)
    }

    return 0;
}