#include <iostream>
#include <list>

using namespace std;

int soma(list<int> lista);          // Declaração da função soma

int main() {
    list<int> lista;                // Declaração de uma lista vazia
    list<int>::iterator p;          // Declaração de um iterador para percorrer a lista
    int x;

    cin >> x;                       // Leitura do valor da entrada
    while (x != 0) {
        lista.push_front(x);        // Insere o valor no início da lista
        cin >> x;                   // Lê o próximo valor
    }

    cout << soma(lista) << endl;    // Chama a função soma e imprime o resultado

    while (!lista.empty())          // Remove todos os elementos da lista
        lista.pop_front();

    return 0;
}

int soma(list<int> lista) {        // Definição da função soma
    list<int>::iterator p;         // Declaração de um iterador para percorrer a lista
    int aux = 0;

    for (p = lista.begin(); p != lista.end(); p++)
        aux += *p;                                     // Acumula os elementos na variável auxiliar

    return aux;
}