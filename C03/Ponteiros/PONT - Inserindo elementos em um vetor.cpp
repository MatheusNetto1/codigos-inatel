#include <iostream>

using namespace std;

int main() {
    int *v = NULL;         // Ponteiro para o vetor
    int tam;               // Tamanho do vetor
    int *p = NULL;         // Ponteiro auxiliar
    int i;                 // Variável de controle

    cin >> tam;                 // Lê o tamanho do vetor

    v = new int[tam];           // Aloca dinamicamente memória para o vetor de inteiros

    p = v;                            // Atribui o endereço inicial do vetor ao ponteiro auxiliar

    for (i = 0; i < tam; i++) {
        cin >> *p;                    // Lê um valor e atribui ao elemento atual do vetor
        p++;                          // Avança o ponteiro para o próximo elemento do vetor
    }

    for (i = 0; i < tam; i++) {
        cout << v[i] << " ";          // Imprime os elementos do vetor
    }

    delete[] v;                       // Libera a memória alocada para o vetor

    return 0;
}