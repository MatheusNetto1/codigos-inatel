#include <iostream>
#include <climits>

using namespace std;

const int MAX_PAISES = 8;
int distancias[MAX_PAISES][MAX_PAISES];
bool visitado[MAX_PAISES] = {false};
int N;
int distanciaTotal = 0; // Variável para acumular a distância total percorrida

// Função recursiva para o algoritmo guloso
void algoritmoGuloso(int origem, bool imprimirOrigem = true) {
    // Marca o país de origem como visitado
    visitado[origem] = true;
    if (imprimirOrigem) {
        cout << origem << endl; // Imprime o país de origem apenas se não for o primeiro na sequência
    }

    int proximo = -1;
    int minDistancia = INT_MAX;

    // Encontra o país mais próximo não visitado
    for (int i = 0; i < N; ++i) {
        if (!visitado[i] && distancias[origem][i] < minDistancia) {
            proximo = i;
            minDistancia = distancias[origem][i];
        }
    }

    // Se um país próximo foi encontrado, continua o percurso
    if (proximo != -1) {
        distanciaTotal += minDistancia; // Adiciona a distância ao total
        algoritmoGuloso(proximo, true);
    }
}

int main() {
    cin >> N;
    // Lê as distâncias necessárias
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            cin >> distancias[i][j];
            distancias[j][i] = distancias[i][j]; // A distância é a mesma nas duas direções
        }
    }

    // Inicia o algoritmo guloso a partir do país 0, sem imprimir o 0 inicial
    algoritmoGuloso(0, false);

    // Imprime a distância total percorrida no final
    cout << "Distância total percorrida: " << distanciaTotal << endl;

    return 0;
}