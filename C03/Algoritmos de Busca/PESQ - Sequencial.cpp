#include <iostream>

using namespace std;

int main()
{
    int vetor[100]; // Vetor para armazenar os números digitados
    int numero;
    int x; // Número a ser pesquisado no vetor
    int i = 0; // Índice para controlar a inserção dos números no vetor
    int k; // Índice onde o número foi encontrado no vetor
    bool posicao = false; // Flag para indicar se o número foi encontrado no vetor ou não

    do {
        cin >> numero; // Lê o número digitado

        if(numero != -1) {
            vetor[i] = numero; // Armazena o número no vetor
            i++; // Incrementa o índice para a próxima posição vazia no vetor
        }
    } while(numero != -1); // Continua a ler os números até que -1 seja digitado

    cin >> x; // Lê o número a ser pesquisado

    for(int j = 0; j < i; j++) { // Itera sobre os elementos do vetor
        if(vetor[j] == x) { // Verifica se o número atual é igual a x
            posicao = true; // Define a flag como true
            k = j; // Armazena o índice onde o número foi encontrado
        }
    }

    if(posicao) { // Verifica se o número foi encontrado
        cout << x << " encontrado na posicao " << k;
    }
    else {
        cout << x << " nao encontrado";
    }

    return 0;
}