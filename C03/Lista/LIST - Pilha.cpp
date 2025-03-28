#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> pilha;         // Cria uma lista vazia chamada pilha
    int x;                   // Variável para armazenar o valor lido

    for (int i = 0; i < 4; i++) {
        cin >> x;                       // Lê um valor
        pilha.push_front(x);            // Insere o valor no início da lista (simulando uma pilha)
    }

    while (!pilha.empty()) {                   // Enquanto a pilha não estiver vazia
        cout << *pilha.begin() << " ";         // Imprime o valor do primeiro elemento da pilha
        pilha.pop_front();                     // Remove o primeiro elemento da pilha
    }

    return 0;
}