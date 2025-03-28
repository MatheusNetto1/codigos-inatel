#include <iostream>
#include <list>

using namespace std;

int contar(list<int> lista);             // Declaração da função contar

int main() {
    list <int> lista;                    // Declaração de uma lista vazia
    list <int> :: iterator p;            // Declaração de um iterador para percorrer a lista
    int x;

    cin >> x;                            // Leitura do valor da entrada
    while (x != 0) {
        lista.push_front(x);             // Insere o valor no início da lista
        cin >> x;                        // Lê o próximo valor
    }

    cout << contar(lista) << endl;       // Chama a função contar e imprime o resultado

    while (!lista.empty())               // Remove todos os elementos da lista
        lista.pop_front();

    return 0;
}

int contar(list<int> lista) {           // Definição da função contar
    list <int> :: iterator p;           // Declaração de um iterador para percorrer a lista
    int cont = 0;

    for (p = lista.begin(); p != lista.end(); p++)
        cont++;                                       // Incrementa o contador para cada elemento da lista

    return cont;
}