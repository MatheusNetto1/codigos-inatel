#include <iostream>
#include <cstring>

using namespace std;

struct estoque{
    string nome;
    int quantidade;
};

int main(){
    estoque *itens = NULL;
    string busca_nome;

    int tamanho;
    bool encontrou = false;

    cin >> tamanho;

    itens = new estoque[tamanho];

    for(int i = 0; i < tamanho; i++){
        getline(cin >> ws, itens[i].nome);
        cin >> itens[i].quantidade;
    }

    getline(cin >> ws, busca_nome);

    for(int i = 0; i < tamanho; i++){
        if(busca_nome == itens[i].nome){
            encontrou = true;
            cout << itens[i].nome << " em estoque!" << endl;
        }
    }

    if(!encontrou){
        cout << "Nao existe " << busca_nome << " em estoque!" << endl;
    }

    delete[] itens;
    return 0;
}