#include <iostream>
#include <cmath>

using namespace std;

void quickSort(int vetor[], int inicioVetor, int fimVetor) {
    int quick;
    
    int esq = inicioVetor;
    int dir = fimVetor;

    int pivo = vetor[(int)round((esq + dir)/2.0)];

    do {
        while (vetor[esq] < pivo){
            esq++;
        }
        while (vetor[dir] > pivo){
            dir--;
        }

        if (esq <= dir){
            quick = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = quick;
            esq++;
            dir--;
        }
    } while (esq <= dir);
    
    if (dir-inicioVetor >= 0){
        quickSort(vetor, inicioVetor, dir);
    }
    if (fimVetor-esq >=0){
        quickSort(vetor, esq, fimVetor);
    }
}

int main () {
    int vetor[] = {5, 2, 7, 1, 4, 9, 3, 6, 8};
    int tamanhoVetor = 9;

    for (int i = 0; i < tamanhoVetor; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;

    quickSort(vetor, 0, tamanhoVetor-1);
    
    for (int i = 0; i < tamanhoVetor; i++) {
        cout << vetor[i] << " ";
    }

    return 0;
}
