#include <iostream>
#include <list>
#include <string.h>

using namespace std;

// Definição de uma estrutura chamada dados_div
struct dados_div {
    char nome_div[50];  // Definição da estrutura que armazena o nome
    int div;            // Definição da estrutura que armazena o valor numérico
};

int main() {
    int i;
    int N;
    char nome[50];

    dados_div pessoa;                     // Declaração da variável de tipo dados_div
    list <dados_div> registro;            // Criação da lista para armazenar registros
    list <dados_div> :: iterator p;       // Declaração do iterador para percorrer a lista

    cin >> N;                             // Leitura da quantidade de registros

    // Loop para ler N registros de dados
    for (i = 0; i < N; i++){
        cin.ignore();
        cin.getline(pessoa.nome_div, 50);  // Leitura do nome usando getline para considerar espaços em branco
        cin >> pessoa.div;                 // Leitura da divida

        registro.push_back(pessoa);        // Adiciona o registro à lista
    }

    cin.ignore();
    cin.getline(nome, 50);                 // Leitura de um nome para buscar e remover registros correspondentes

    // Loop para percorrer a lista de registros
    for (p = registro.begin(); p != registro.end(); ++p){
        if (!strcmp(nome, p->nome_div)) {  // Compara o nome fornecido com o nome do registro atual
            p = registro.erase(p);         // Remove o registro da lista
        }
    }

    // Loop para exibir os registros restantes
    for (p = registro.begin(); p != registro.end(); ++p) {
        cout << p->nome_div << endl;      // Exibe o nome do registro
        cout << p->div << endl;           // Exibe a dívida do registro
    }

    while (!registro.empty()) {
        registro.pop_front();             // Limpa a lista
    }

    return 0;
}