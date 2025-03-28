#include <iostream>

using namespace std;

// Procura o menor e troca pela posição J
void selectionSort(int vetor[], int tamanhoVetor) {
    int i, j, selection;

    for (j = 0; j < tamanhoVetor - 1; j++) {
        selection = j;

        for (i = j+1; i < tamanhoVetor; i++) {
            if (vetor[i] < vetor[selection]) {
                selection = i;
            }
        }
        
        int temp = vetor[j];
        vetor[j] = vetor[selection];
        vetor[selection] = temp;
    }
}   

int main () {
    int vetor[] = {7, 3, 2, 1, 4, 6, 5};
    int tamanhoVetor = 7;

    for (int i = 0; i < tamanhoVetor; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;

    selectionSort(vetor, tamanhoVetor);

    for (int k = 0; k < tamanhoVetor; k++){
        cout << vetor[k] << " ";
    }

    return 0;
}