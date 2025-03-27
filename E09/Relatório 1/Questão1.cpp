#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int quantidadeDeLaranja;

    cin >> quantidadeDeLaranja;

    cout << fixed << setprecision(2);

    if(quantidadeDeLaranja >= 12){
        cout << "Preco da unidade: R$0.65" << endl;
        cout << "Preco total: R$" << quantidadeDeLaranja * 0.65 << endl;
    } else {
        cout << "Preco da unidade: R$0.80" << endl;
        cout << "Preco total: R$" << quantidadeDeLaranja * 0.80 << endl;
    }

    return 0;
}