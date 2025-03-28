#include <iostream>
#include <list>

using namespace std;

int main(){
    list <int> lista, pilha_aux;         // Cria duas listas: lista e pilha_aux
    list <int> :: iterator p;            // Cria um iterador p para percorrer a lista
    int i;                               // Variável para armazenar o valor lido
    int x, y;                            // Variáveis para armazenar os valores de x e y

    cin >> i;                            // Lê o valor de i do usuário

    while(i != -1){                      // Loop para adicionar elementos à lista até que i seja igual a -1
        lista.push_back(i);              // Adiciona o valor de i no final da lista
        cin >> i;                        // Lê o próximo valor de i
    }

    cin >> x >> y;                                        // Lê os valores de x e y do usuário

    for (p = lista.begin(); p != lista.end(); p++) {      // Loop para percorrer a lista
        if (*p == x) {                                    // Se o valor apontado por p for igual a x
            lista.insert(p, y);                           // Insere o valor de y antes do valor apontado por p na lista
        }
    }

    while (!lista.empty()) {                              // Loop para mover todos os elementos da lista para a pilha_aux
        pilha_aux.push_front(*lista.begin());             // Adiciona o valor apontado pelo início da lista no início da pilha_aux
        lista.pop_front();                                // Remove o primeiro elemento da lista
    }

    while(!pilha_aux.empty()){                            // Loop para imprimir os elementos da pilha_aux
        cout << *pilha_aux.begin() << " ";                // Imprime o valor apontado pelo início da pilha_aux seguido de um espaço
        pilha_aux.pop_front();                            // Remove o primeiro elemento da pilha_aux
    }

    return 0;                                             // Retorna 0 para indicar que o programa foi executado com sucesso
}