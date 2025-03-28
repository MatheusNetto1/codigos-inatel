#include <iostream>
#include <iomanip>

using namespace std;

// Declaração da estrutura que vai armazenar os dados dos alunos
struct dados {
    int n1, n2, n3, n4;      // Notas dos alunos
    float M;                 // Média
};

int main() {
    dados *p = NULL;         // Ponteiro para estrutura de dados

    p = new dados;           // Alocação dinâmica da estrutura

    cin >> p->n1 >> p->n2 >> p->n3 >> p->n4;               // Lê as notas dos alunos

    p->M = (p->n1 + p->n2 + p->n3 + p->n4) / 4.0;          // Calcula a média das notas

    cout << fixed << setprecision(2) << p->M << endl;      // Imprime a média com 2 casas decimais

    delete p;                                              // Libera a memória alocada para a estrutura

    return 0;
}