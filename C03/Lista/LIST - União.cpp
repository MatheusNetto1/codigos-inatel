#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> lista1, lista2, lista3;         // Cria três listas: lista1, lista2 e lista3
    list<int>::iterator p, q;                 // Cria dois iteradores: p e q para percorrer as listas
    int x;                                    // Variável para armazenar o valor lido

    cin >> x;                                 // Lê o valor de x do usuário
    while (x != 0) {                          // Loop para adicionar elementos à lista1 até que x seja igual a 0
        lista1.push_back(x);                  // Adiciona o valor de x no final da lista1
        cin >> x;                             // Lê o próximo valor de x
    }

    cin >> x;                                 // Lê o valor de x do usuário
    while (x != 0) {                          // Loop para adicionar elementos à lista2 até que x seja igual a 0
        lista2.push_back(x);                  // Adiciona o valor de x no final da lista2
        cin >> x;                             // Lê o próximo valor de x
    }

    p = lista1.begin();                       // Inicializa o iterador p com o primeiro elemento da lista1
    q = lista2.begin();                       // Inicializa o iterador q com o primeiro elemento da lista2

    do {
        if (*p == *q) {                       // Se os valores apontados por p e q forem iguais
            lista3.push_back(*p);             // Adiciona o valor apontado por p no final da lista3
            p++;                              // Move o iterador p para o próximo elemento
            q++;                              // Move o iterador q para o próximo elemento
        }
        else if (*p < *q || q == lista2.end()) {              // Se o valor apontado por p for menor que o valor apontado por q ou se q alcançar o final da lista2
            lista3.push_back(*p);                             // Adiciona o valor apontado por p no final da lista3
            p++;                                              // Move o iterador p para o próximo elemento
        }
        else if (*q < *p || p == lista1.end()) {              // Se o valor apontado por q for menor que o valor apontado por p ou se p alcançar o final da lista1
            lista3.push_back(*q);                             // Adiciona o valor apontado por q no final da lista3
            q++;                                              // Move o iterador q para o próximo elemento
        }
    } while (p != lista1.end() || q != lista2.end());         // Continua o loop enquanto p não chegar ao final da lista1 ou q não chegar ao final da lista2

    for (p = lista3.begin(); p != lista3.end(); p++) {        // Loop para imprimir os elementos da lista3
        cout << *p << " ";                                    // Imprime o valor apontado por p seguido de um espaço
    }

    while (!lista1.empty()) {           // Loop para remover todos os elementos da lista1
        lista1.pop_front();             // Remove o primeiro elemento da lista1
    }

    while (!lista2.empty()) {           // Loop para remover todos os elementos da lista2
        lista2.pop_front();             // Remove o primeiro elemento da lista2
    }

    while (!lista3.empty()) {           // Loop para remover todos os elementos da lista3
        lista3.pop_front();             // Remove o primeiro elemento da lista3
    }

    return 0;                           // Retorna 0 para indicar que o programa foi executado com sucesso
}