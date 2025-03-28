#include <iostream>

using namespace std;

// Função de busca binária
int binaria(int vetor[], int tamanho, int x)
{
    bool achou;                      // Variável auxiliar para controle de busca
    int baixo, meio, alto;           // Variáveis auxiliares para os limites e o meio do intervalo de busca

    baixo = 0;                       // Limite inferior do intervalo de busca
    alto = tamanho - 1;              // Limite superior do intervalo de busca
    achou = false;                   // Inicialmente, o elemneto não foi encontrado

    // Executa a busca enquanto a posição inferior não ultrapassar a superior e o elemento não for encontrado
    while ((baixo <= alto) && (achou == false))
    {
        meio = (baixo + alto) / 2;   // Encontra o índice do meio do vetor

        // Verifica se o elemento está à esquerda ou à direita do meio e atualiza os limites
        if (x < vetor[meio])
            alto = meio - 1;         // Se x for menor que o valor do meio, atualiza o limite superior para o índice do meio - 1
        else if (x > vetor[meio])
            baixo = meio + 1;        // Se x for menor que o valor do meio, atualiza o limite inferior para o índice do meio + 1
        else
            achou = true;            // Elemento encontrado
    }

    if (achou)
        return meio;                 // Retorna o índice do elemento encontrado
    else
        return -1;                   // Retorna -1 para indicar que o elemento não foi encontrado
}

int main()
{
    int vetor[100];                  // Declara um vetor de tamanho 100
    int i = 0;
    int x;
    int ver;

    cin >> vetor[i];                 // Lê o primeiro elemento do vetor

    // Preenche o vetor com valores até que seja digitado -1
    while (vetor[i] != -1)
    {
        i++;
        cin >> vetor[i];             // Lê os elementos restantes do vetor
    }

    cin >> x;                        // Lê o valor x a ser procurado no vetor

    // Chama a função de busca binária para verificar se o valor x está presente no vetor
    ver = binaria(vetor, i, x);

    if (ver == -1)
    {
        cout << "Não possui acesso" << endl;    // Valor não encontrado no vetor
    }
    else
    {
        cout << "Possui acesso" << endl;        // Valor encontrado no vetor
    }

    return 0;
}