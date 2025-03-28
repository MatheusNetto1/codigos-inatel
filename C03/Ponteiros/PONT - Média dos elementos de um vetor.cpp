#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int *v = NULL;             // Ponteiro para o vetor
    int tam;                   // Tamanho do vetor
    int *p = NULL;             // Ponteiro auxiliar
    int i;                     // Variável de controle
    double soma = 0, media;    // Variáveis para soma e média

    cin >> tam;                // Lê o tamanho do vetor

    v = new int[tam];          // Aloca dinamicamente memória para o vetor de inteiros

    p = v;                     // Atribui o endereço inicial do vetor ao ponteiro auxiliar

    for (i = 0; i < tam; i++) {
        cin >> *p;                    // Lê um valor e atribui ao elemento atual do vetor
        p++;                          // Avança o ponteiro para o próximo elemento do vetor
    }

    for (i = 0; i < tam; i++) {
        soma += v[i];                 // Soma os elementos do vetor
    }

    media = soma / tam;               // Calcula a média

    cout << fixed << setprecision(2) << media << endl;          // Imprime a média com precisão de duas casas decimais

    delete[] v;                                                 // Libera a memória alocada para o vetor

    return 0;
}