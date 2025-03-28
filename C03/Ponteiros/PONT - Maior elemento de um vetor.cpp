#include <iostream>

using namespace std;

int main() {
    int *v = NULL;            // Ponteiro para o vetor
    int tam;                  // Tamanho do vetor
    int *p = NULL;            // Ponteiro auxiliar
    int i;                    // Variável de controle
    int maior = -9999;        // Variável para armazenar o maior valor

    cin >> tam;               // Lê o tamanho do vetor

    v = new int[tam];         // Aloca dinamicamente memória para o vetor de inteiros

    p = v;                    // Atribui o endereço inicial do vetor ao ponteiro auxiliar

    for (i = 0; i < tam; i++) {
        cin >> *p;                      // Lê um valor e atribui ao elemento atual do vetor
        p++;                            // Avança o ponteiro para o próximo elemento do vetor
    }

    for (i = 0; i < tam; i++) {
        if (v[i] > maior)               // Verifica se o elemento atual é maior que o maior valor atual
            maior = v[i];               // Atualiza o maior valor
    }

    cout << maior << endl;              // Imprime o maior valor

    delete[] v;                         // Libera a memória alocada para o vetor

    return 0;
}