#include <iostream>
#include <string.h>

using namespace std;

// struct para armazenar as informacoes dos alunos
struct dados{
    int mat;
    int id;
    string nome;
    string dataN;
};

// funcao para receber as informacoes e verificar pela matricula
dados BuscaMat (dados cadastro[], int n, int matB){
    int i;

    for (i = 0; i < n; i++){                         // 1 + 3(n + 1) + 3n
        if (matB == cadastro[i].mat){                // 4n
            return cadastro[i];                      // 2
        }
    }
} // complexidade total: T(n) = 10n + 6
  // complexidade Big O: O(n)

// funcao para receber as informacoes e verficar pelo nome
dados BuscaNome (dados cadastro[], int n, string nomeB){
    int i;

    for (i = 0; i < n; i++){                         // 1 + 3(n + 1) + 3n
        if (nomeB == cadastro[i].nome){              // 4n
            return cadastro[i];                      // 2
        }
    }
} // complexidade total: T(n) = 10n + 6
  // complexidade Big O: O(n)

// funcao para receber as informacoes e contar as idades
int BuscaIdades (dados cadastro[], int n, int idadeB){
    int i;
    int contador = 0;                                // 1

    for (i = 0; i < n; i++){                         // 1 + 3(n + 1) + 3n
        if (cadastro[i].id <= idadeB){               // 4n
            contador++;                              // 3n (no pior dos casos)
        }
    }

    return contador;                                 // 1
} // complexidade total: T(n) = 13n + 6
  // complexidade Big O: O(n)

int main(){
    int n;                                                             // numero de alunos a serem cadastrados
    dados *cadastro = NULL;                                            // ponteiro para a struct de dados
    dados busca;                                                       // estrutura auxiliar de busca
    int i;                                                             // controle de iteracao

    int matB;                                                          // variavel auxiliar para busca da matricula
    string nomeB;                                                      // variavel auxiliar para busca do nome
    int idadeB;                                                        // variavel auxiliar para verificacao das idades

    cout << "CADASTRO\nQuantos alunos serao cadastrados? ";
    cin >> n;                                                          // entrada do numero de alunos
    
    cadastro = new dados[n];                                           // alocacao dinamica do vetor de struct

    // loop para entrada de todas as informacoes de cada aluno
    for (i = 0; i < n; i++){
        cout << "\nInsira a matricula: ";
        cin >> cadastro[i].mat;

        cout << "Insira o nome: ";
        cin.ignore();
        getline(cin, cadastro[i].nome);

        cout << "Insira a data de nascimento: ";
        getline(cin, cadastro[i].dataN);

        cout << "Insira a idade: ";
        cin >> cadastro[i].id;
    }

    cout << "\nBuscar por matricula: ";
    cin >> matB;                                                        // entrada da matricula para a busca

    busca = BuscaMat(cadastro, n, matB);                                // chamada da funcao de busca por matricula

    // imprime as informacoes de acordo com a busca da matricula
    cout << "\nMatricula: " << busca.mat << endl;
    cout << "Nome: " << busca.nome << endl;
    cout << "Data de Nascimento: " << busca.dataN << endl;
    cout << "Idade: " << busca.id << endl;

    cout << "\nBuscar por nome: ";
    cin.ignore();
    getline(cin, nomeB);                                                // entrada do nome para busca

    busca = BuscaNome(cadastro, n, nomeB);                              // chamada da funcao de busca pelo nome

    // imprime as informacoes de acordo com a busca do nome
    cout << "\nMatricula: " << busca.mat << endl;
    cout << "Nome: " << busca.nome << endl;
    cout << "Data de Nascimento: " << busca.dataN << endl;
    cout << "Idade: " << busca.id << endl;

    cout << "\nDigite uma idade: ";
    cin >> idadeB;                                                      // entrada da idade para verificacao

    // verifica se tem alunos com a idade ou menos e imprime o total de quantos
    if (BuscaIdades(cadastro, n, idadeB) > 0){
        cout << "\nFoi encontrado " << BuscaIdades(cadastro, n, idadeB) << " aluno(s) com essa idade ou menos.\n" << endl;
    }

    // caso nao tenham alunos com a idade ou menos
    else {
        cout << "\nNao foi encontrado nenhum aluno com essa idade ou menos.\n" << endl;
    }

    delete[] cadastro;                      // Libera a memória alocada para o vetor de struct

    return 0;
}