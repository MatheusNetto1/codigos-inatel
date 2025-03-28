#include <iostream>

using namespace std;

int main() {
    int c;          // casos de teste
    int n;          // numero de projeteis
    int k;          // capacidade do canhao
    int r;          // resistencia do castelo

    cin >> c;
    for (int a = 0; a < c; a++) {
        cin >> n;

        int x[n];       // armazena os danos
        int y[n];       // armazena os pesos

        // contadores auxiliares
        int dano_total = 0, peso_total = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];                // entrada do dano e peso
        }

        cin >> k;
        while (peso_total < k) {
            peso_total += y[j];                 // somador pro peso
            j++;                                // avança pra proxima posicao
        }

        for (int i = 0; i < j - 1; i++) {
            dano_total += x[i];                 // somador pro dano
        }
        
        cin >> r;

        if (r <= dano_total) {
            cout << "Missao completada com sucesso" << endl;
        } else {
            cout << "Falha na missao" << endl;
        }
    }

    return 0;
}