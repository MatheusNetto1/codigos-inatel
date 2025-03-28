#include <iostream>
using namespace std;
int main (){

    int *v = NULL; // ponteiro para o vetor
    int tam; // tamanho do vetor
    int *p = NULL; // ponteiro aux
    int i;

    //Lendo o tamanho do vetor
    cin >> tam;

    //Alocando memória para o vetor
    v = new int[tam];

    //Lendo o vetor
    p = v;
    for(i=0; i<tam; i++){
        cin >> *p;
        p++;
    }

    //Mostrando o vetor
    for(i=0; i<tam; i++){
        cout << v[i] << endl;
    }

    //Liberando a memoria alocada
    delete []v;

    return 0;
}