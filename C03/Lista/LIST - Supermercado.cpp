#include <iostream>
#include <list>

using namespace std;

int main(){
    list <int> listaEstoque;           // Cria uma lista chamada "listaEstoque" para armazenar os itens em estoque
    list <int> listaVenda;             // Cria uma lista chamada "listaVenda" para armazenar os itens vendidos
    list <int> :: iterator p;          // Cria um iterador para percorrer as listas

    int n, op, x;                      // Declaração de variáveis
    int i;                             // Variável de controle do loop

    cin >> n;                            // Lê o valor de n do usuário

    for(i = 0; i < n; i++) {             // Loop para realizar n operações
        cin >> op;                       // Lê o valor de op do usuário

        switch (op){                     // Verifica o valor de op
            case 1:                            // Caso op seja 1
                cin >> x;                      // Lê o valor de x do usuário
                listaEstoque.push_back(x);     // Adiciona o valor de x no final da listaEstoque
            break;

            case 2:                            // Caso op seja 2
                x = listaEstoque.front();      // Atribui o valor do primeiro elemento da listaEstoque para x

                listaEstoque.pop_front();      // Remove o primeiro elemento da listaEstoque

                listaVenda.push_front(x);      // Adiciona o valor de x no início da listaVenda
            break;
        
            default:                           // Caso op seja diferente de 1 e 2
            break;
        }
    }

    cout << "Estoque: ";
    for(p = listaEstoque.begin(); p != listaEstoque.end(); p++) {
        cout << *p << " ";                                             // Imprime os elementos da listaEstoque
    }
    cout << endl;

    cout << "Venda: ";
    for(p = listaVenda.begin(); p != listaVenda.end(); p++) {
        cout << *p << " ";                                             // Imprime os elementos da listaVenda
    }
    cout << endl;

    while(!listaEstoque.empty()) {
        listaEstoque.pop_front();                                      // Remove todos os elementos da listaEstoque
    }

    while(!listaVenda.empty()) {
        listaVenda.pop_front();                                        // Remove todos os elementos da listaVenda
    }

    return 0;                                                          // Retorna 0 para indicar que o programa foi executado com sucesso
}