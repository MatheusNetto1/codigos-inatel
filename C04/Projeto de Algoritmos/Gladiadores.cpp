#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Gladiador {
    string nome;
    int forca;
    int habilidade;
    int idade;
};

// Protótipos das funções
void cadastrarGladiadores(Gladiador gladiadores[], int tamanho);
bool combate(Gladiador& g1, Gladiador& g2);
int calcularDano(const Gladiador& gladiador);

int main() {
    const int tamanho = 5;
    Gladiador gladiadores[tamanho];
    cadastrarGladiadores(gladiadores, tamanho);
    
    while(true) {
        int g1, g2;
        cout << "Escolha dois gladiadores para a batalha (digite -1 para sair): ";
        cin >> g1;
        if(g1 == -1) break;
        cin >> g2;

        // Ajuste para o índice do array
        g1--; g2--;

        if(combate(gladiadores[g1], gladiadores[g2])) {
            cout << gladiadores[g2].nome << " ganhou a batalha contra " << gladiadores[g1].nome << ".\n";
        } else {
            cout << gladiadores[g1].nome << " ganhou a batalha contra " << gladiadores[g2].nome << ".\n";
        }
    }

    return 0;
}

void cadastrarGladiadores(Gladiador gladiadores[], int tamanho) {
    for(int i = 0; i < tamanho; ++i) {
        cout << "Digite o nome, força, habilidade e idade do gladiador " << i+1 << ": ";
        cin >> gladiadores[i].nome >> gladiadores[i].forca >> gladiadores[i].habilidade >> gladiadores[i].idade;
    }
}

bool combate(Gladiador& g1, Gladiador& g2) {
    int vidaG1 = 100, vidaG2 = 100;
    while(vidaG1 > 0 && vidaG2 > 0) {
        vidaG2 -= calcularDano(g1);
        if(vidaG2 <= 0) return false;
        vidaG1 -= calcularDano(g2);
    }
    return vidaG1 <= 0;
}

int calcularDano(const Gladiador& gladiador) {
    return gladiador.forca + pow(2, gladiador.habilidade);
}
