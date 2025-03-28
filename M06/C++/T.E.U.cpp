#include <iostream>
#include <utility>
#include <iomanip>

using namespace std;

float f(int x) {
    return -(x * x) + (2 * x) + 1;
}

float df(int x) {
    return -(2 * x) + 2;
}

void encontrar_intervalo(int a, int b) {
    int passo = 1, contador = 0;
    pair<int, int> intervalos[2];

    int x_atual = a;

    cout << setw(5) << "x" << " | " << setw(10) << "f(x)" << " | " << setw(10) << "f'(x)" << endl;
    cout << string(33, '-') << endl;

    cout << fixed << setprecision(2);

    while (x_atual <= b) {
        int x_prox = x_atual + passo;
        float fx_atual = f(x_atual);
        float fx_prox = f(x_prox);
        float dfx_atual = df(x_atual);
        float dfx_prox = df(x_prox);

        cout << setw(5) << x_atual << " | " << setw(10) << fx_atual << " | " << setw(10) << dfx_atual << endl;

        if ((fx_atual * fx_prox < 0) && (dfx_atual * dfx_prox > 0)) {
            intervalos[contador] = make_pair(x_atual, x_prox);
            contador++;
        }

        x_atual = x_prox;
    }

    cout << "\nOs intervalos que possuem raízes são: ";
    cout << "[" << intervalos[0].first << ", " << intervalos[0].second << "]";
    cout << " e [" << intervalos[1].first << ", " << intervalos[1].second << "]" << endl;
}

int main() {
    encontrar_intervalo(-3, 3);
    return 0;
}
