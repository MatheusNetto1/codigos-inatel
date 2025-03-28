#include <iostream>

using namespace std;

// Compara dois a dois e coloca o maior na posição J
void bubbleSort(int vetor[], int tamanhoVetor) {
    int i, j, limite = tamanhoVetor - 1;
    int bubble;
    bool troca = true;
    
    while (troca) {
        troca = false;
        for (i = 0; i < limite; i++) {
            if (vetor[i] > vetor[i+1]) {
                bubble = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = bubble;
                j = i;
                troca = true;
            }
        }
        limite = j;
    }
}

int main () {
    int vetor[] = {7, 3, 2, 1, 4, 6, 5};
    int tamanhoVetor = 7;

    for (int i = 0; i < tamanhoVetor; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;

    bubbleSort(vetor, tamanhoVetor);

    for (int i = 0; i < tamanhoVetor; i++) {
        cout << vetor[i] << " ";
    }

    return 0;
}
