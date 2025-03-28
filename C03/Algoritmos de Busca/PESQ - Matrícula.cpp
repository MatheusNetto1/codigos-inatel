#include <iostream>
#include <cstring>

using namespace std;

// Definição da estrutura "dado" que armazena informações de um aluno
struct dado {
    char nome[100];         // Nome do aluno
    char curso[100];        // Curso do aluno
    int matricula;          // Matrícula do aluno
};

int main()
{
    dado aluno[100];                   // Vetor de estruturas "dado" para armazenar informações dos alunos
    int n;                             // Número de alunos
    int i;                             // Variável de controle para iteração
    int pos = -1;                      // Variável para armazenar a posição do aluno encontrado (-1 indica que não foi encontrado)
    char nomep[100];                   // Nome do aluno a ser procurado

    cin >> n;                          // Lê o número de alunos

    for (i = 0; i < n; i++) {
        cin.ignore();                           // Ignora o caractere de nova linha deixado pelo cin anterior
        cin.getline(aluno[i].nome, 100);        // Lê o nome do aluno e armazena na estrutura correspondente do vetor
        cin.getline(aluno[i].curso, 100);       // Lê o curso do aluno e armazena na estrutura correspondente do vetor
        cin >> aluno[i].matricula;              // Lê a matrícula do aluno e armazena na estrutura correspondente do vetor
    }

    cin.ignore();
    cin.getline(nomep, 100);                    // Lê o nome do aluno a ser procurado

    for (i = 0; i < n; i++) {
        if (strcmp(nomep, aluno[i].nome) == 0) {      // Compara o nome informado com o nome do aluno atual usando a função strcmp
            pos = i;                                  // Se os nomes forem iguais, atualiza a posição com o valor atual de i
        }
    }

    if (pos != -1) {                             // Se pos for diferente de -1, ou seja, o aluno foi encontrado, imprime as informações dele
        cout << aluno[pos].nome << endl;              // Imprime o nome do aluno encontrado
        cout << aluno[pos].curso << endl;             // Imprime o curso do aluno encontrado
        cout << aluno[pos].matricula << endl;         // Imprime a matrícula do aluno encontrado

    } else {                                     // Caso contrário, imprime uma mensagem informando que o aluno não foi encontrado
        cout << "Aluno nao localizado" << endl;       // Imprime mensagem informando que o aluno não foi encontrado
    }

    return 0;
}