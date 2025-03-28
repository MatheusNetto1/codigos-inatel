#include <iostream>

using namespace std;

// Procura pela melhor posição e insere o elemento J
// Complexidade Modelo RAM: 7n² + 18n - 12
// Complexidade Modelo Assintótico: O(n²)
void insertionSort (int vetor[], int tamanhoVetor) {
    int i, j, insertion;

    for (j = 1; j < tamanhoVetor; j++) {                // 1 + 3n + 3(n - 1) + 6n - 2
        insertion = vetor[j];                           // 3(n - 1) = 3n - 3

        for (i = j-1; i >= 0; i--) {                    // 3(n - 1) + 2(n - 1)(n/2) + 3(n - 1)(n/2) = 2,5n² + 0,5n - 3
            if (vetor[i] > insertion) {                 // 4(n - 1)(n/2) = 2n² - 2n
                vetor[i+1] = vetor[i];                  // 5(n - 1)(n/2) = 2,5n² - 2,5n
            } else {
                break;
            }
        }
        vetor[i+1] = insertion;                         // 4(n - 1) = 4n - 4
    }

    for (int k = 0; k < tamanhoVetor; k++){
        cout << vetor[k] << " ";
    }
}

int main () {
    int vetor[] = {7, 3, 2, 1, 4, 6, 5};
    int tamanhoVetor = 7;

    for (int i = 0; i < tamanhoVetor; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;

    insertionSort(vetor, tamanhoVetor);

    return 0;
}