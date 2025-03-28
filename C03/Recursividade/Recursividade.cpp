#include <iostream>

using namespace std;

int fatorial(int numeroFatorial){
    if(numeroFatorial == 1){
        return 1;
    }
    
    return numeroFatorial * fatorial(numeroFatorial-1);
}

int fibonacci(int numeroFibonacci){
    if(numeroFibonacci == 0 || numeroFibonacci == 1){
        return 1;
    }

    return fibonacci(numeroFibonacci-1) + fibonacci(numeroFibonacci-2);
}

int fibonacciIterativo(int numeroFibonacci){
    int fibonacciVetor[numeroFibonacci];
    fibonacciVetor[0] = 1;
    fibonacciVetor[1] = 1;

    for (int i = 2; i < numeroFibonacci; i++){
        fibonacciVetor[i] = fibonacciVetor[i-1] + fibonacciVetor[i-2];
    }
    
    return fibonacciVetor[numeroFibonacci];
}

int buscaBinaria(int vetor[], int inicio, int fim, int elementoBuscado){
    int meio = (inicio + fim)/2;

    if(inicio > fim){
        return -1;
    }

    if (vetor[meio] == elementoBuscado){
        return meio;
    } else if (vetor[meio] > elementoBuscado){
        return buscaBinaria(vetor, inicio, meio-1, elementoBuscado);
    } else {
        return buscaBinaria(vetor, meio+1, fim, elementoBuscado);
    }
}

int main(){

    return 0;
}