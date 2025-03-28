#include <iostream>

using namespace std;

int main() {
    int n;                    // Número de elementos no vetor
    int vet[100];             // Vetor de elementos
    int pesq;                 // Elemento a ser pesquisado
    int i;                    // Variável de controle para iteração
    int pos = -1;             // Posição do elemento encontrado (-1 indica que não foi encontrado)

    cin >> n;                     // Lê o número de elementos

    for (i = 0; i < n; i++) {
        cin >> vet[i];            // Lê cada elemento e armazena no vetor
    }

    cin >> pesq;                  // Lê o elemento a ser pesquisado

    for (i = 0; i < n; i++) {
        if (pesq == vet[i]) {     // Compara o elemento pesquisado com cada elemento do vetor
            pos = i;              // Se forem iguais, atualiza a posição com o valor atual de i
        }
    }

    if (pos == -1) {
        cout << pesq << " nao encontrado" << endl;                   // Elemento não encontrado
    } else {
        cout << pesq << " Encontrado na posicao " << pos << endl;    // Elemento encontrado, exibe a posição
    }

    return 0;
}