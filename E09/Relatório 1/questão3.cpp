#include <iostream>
#include <iomanip>

using namespace std;

void verificaValores(int valores[], int tamanho){
    int contadorPositivo = 0, contadorNegativo = 0, contadorPar = 0, contadorImpar = 0;
    for(int i = 0; i < tamanho; i++){
        if(valores[i] >= 0){
            if(valores[i] % 2 == 0){
                contadorPar++;
            } else {
                contadorImpar++;
            }
            contadorPositivo++; // assim como no caso de teste, 0 foi considerado como positivo
        } else {
            if(valores[i] % 2 == 0){
                contadorPar++;
            } else {
                contadorImpar++;
            }
            contadorNegativo++;
        }
    }

    cout << "Quantidade de numeros pares: " << contadorPar << endl;
    cout << "Quantidade de numeros impares: " << contadorImpar << endl;
    cout << "Quantidade de numeros positivos: " << contadorPositivo << endl;
    cout << "Quantidade de numeros negativos: " << contadorNegativo << endl;
}

int main(){
    int tamanho = 5;
    int valores[tamanho];
    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < tamanho; j++){
            cin >> valores[j];
        }

        verificaValores(valores, tamanho);
    }

    return 0;
}