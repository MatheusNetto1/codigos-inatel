#include <iostream>
#include <iomanip>

using namespace std;

struct dados {
    float n1, n2, n3, n4;   // Notas dos alunos
    float M;                // Média
};

int main() {
    dados *p = NULL;              // Ponteiro para estrutura de dados
    int tam, i;                   // Variáveis para tamanho do vetor e controle de iteração
    float soma = 0;               // Variável para armazenar a soma das médias

    cin >> tam;                   // Lê o tamanho do vetor

    p = new dados[tam];           // Alocação dinâmica do vetor de estruturas

    for (i = 0; i < tam; i++) {
        cin >> p[i].n1 >> p[i].n2 >> p[i].n3 >> p[i].n4;          // Lê as notas dos alunos
        p[i].M = (p[i].n1 + p[i].n2 + p[i].n3 + p[i].n4) / 4;     // Calcula a média das notas
        soma += p[i].M;                                           // Soma as médias
    }

    cout << fixed << setprecision(2) << soma / tam << endl;       // Calcula e imprime a média das médias

    delete[] p;                   // Libera a memória alocada para o vetor de estruturas
    

    
    return 0;
}