#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int numero;

    do{
        cin >> numero;
    }while(numero <= 0 || numero > 50);

    for (int i = numero - 1; i > 0; i--){
        cout << "Resto da divisão de " << numero << " por " << i << ": " << numero%i << endl;
    }
    
    return 0;
}