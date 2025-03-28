#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct dados{
    float centimetro;
    string nome;
};

void insercaoDireta(dados vetor[], int tamanho){
    int i,j;
    dados chave;

    for (j = 1; j < tamanho; j++){
        chave = vetor[j];
        i = j - 1;
        while ((i >= 0) && (vetor[i].centimetro < chave.centimetro)){
            vetor[i+1] = vetor[i];
            i = i - 1;
        }

        vetor[i+1] = chave;
    }
}

int main(){
    dados *insetos = NULL;
    int tamanho;

    cin >> tamanho;

    insetos = new dados[tamanho];

    for(int i = 0; i < tamanho; i++){
        getline(cin >> ws, insetos[i].nome);
        cin >> insetos[i].centimetro;
    }

    insercaoDireta(insetos, tamanho);
    for(int i = tamanho-1; i >= 0; i--){
        cout << insetos[i].nome << endl;
    }

    delete[] insetos;

    return 0;
}