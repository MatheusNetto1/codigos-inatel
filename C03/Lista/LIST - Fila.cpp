#include <iostream>
#include <list>

using namespace std;

int main() {
    list <int> fila;       // Cria uma lista vazia chamada fila
    int x;                 // Variável para armazenar o valor lido

    for (int i = 0; i < 4; i++) {
        cin >> x;                      // Lê um valor
        fila.push_back(x);             // Insere o valor no final da lista (simulando uma fila)
    }

    while (!fila.empty()) {                // Enquanto a fila não estiver vazia
        cout << *fila.begin() << " ";      // Imprime o valor do primeiro elemento da fila
        fila.pop_front();                  // Remove o primeiro elemento da fila
    }

    return 0;
}