#include <iostream>
#include <list>

using namespace std;

// Função para encontrar um valor na lista
bool encontrar(list<int> lista, int x) {
    list<int>::iterator p;                                 // Declaração de um iterador para percorrer a lista

    // Loop for para percorrer a lista
    for (p = lista.begin(); p != lista.end(); p++) {
        if (x == *p)                                       // Verifica se o valor atual é igual a x
            return true;                                   // Se for igual, retorna true (valor encontrado)
    }

    return false;                                          // Se o valor não for encontrado, retorna false
}

int main() {
    list<int> lista;                      // Cria uma lista vazia chamada lista
    list<int>::iterator p;                // Iterator para percorrer a lista
    int x, N;                             // Variáveis para armazenar os valores lidos

    cin >> x;
    while (x != 0) {
        lista.push_front(x);              // Insere o valor no início da lista
        cin >> x;                         // Lê o próximo valor
    }

    cin >> N;

    // Verifica se N está presente na lista
    if (encontrar(lista, N))
        cout << "Encontrado" << endl;           // Imprime "Encontrado" se N estiver na lista
    else
        cout << "Nao encontrado" << endl;       // Imprime "Nao encontrado" se N não estiver na lista

    while (!lista.empty())                      // Remove todos os elementos da lista
        lista.pop_front();

    return 0;
}