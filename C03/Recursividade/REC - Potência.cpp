#include <iostream>
#include <cmath>

using namespace std;

int Potencia(int a, int n);

int main(){
    int a, n;

    cin >> a >> n;

    cout << Potencia(a, n);

    return 0;
}

int Potencia(int a, int n){
    int resultado;

    if(n == 0){
        resultado = 1;
    }
    else if(n > 0){
        resultado = a * Potencia(a, n - 1);
    }

    return resultado;
}
