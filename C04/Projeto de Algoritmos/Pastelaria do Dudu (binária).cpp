#include <iostream>
#include <cstring>

using namespace std;

struct estoque{
    string nome;
    int quantidade;
    int codigo;
};

int binaria(estoque vetor[], int tamanho, int x){
    bool achou;                                         // Variável auxiliar para controle da busca
    int baixo, meio, alto;                              // Variáveis auxiliares para os limites e o meio do intervalo de busca

    baixo = 0;                                          // Limite inferior do intervalo de busca
    alto = tamanho - 1;                                 // Limite superior do intervalo de busca
    achou = false;                                      // Inicialmente, o elemento não foi encontrado

    // Executa a busca enquanto a posição inferior não ultrapassar a superior e o elemento não for encontrado
    while ((baixo <= alto) && (achou == false))
    {
        meio = (baixo + alto) / 2;                      // Encontra o índice do meio do intervalo de busca

        if (x < vetor[meio].codigo)
            alto = meio - 1;                            // Se x for menor que o elemento do meio, atualiza o limite superior
        else if (x > vetor[meio].codigo)
            baixo = meio + 1;                           // Se x for maior que o elemento do meio, atualiza o limite inferior
        else
            achou = true;                               // Elemento encontrado
    }

    if (achou)
        return meio;                     // Retorna o índice do elemento encontrado
    else
        return -1;                       // Retorna -1 para indicar que o elemento não foi encontrado
}

int main(){
    estoque *itens = NULL;

    int codigo_auxiliar;
    int tamanho;

    int auxiliar;

    cin >> tamanho;

    itens = new estoque[tamanho];

    for(int i = 0; i < tamanho; i++){
        cin >> itens[i].codigo;
        getline(cin >> ws, itens[i].nome);
        cin >> itens[i].quantidade;
    }

    cin >> codigo_auxiliar;

    auxiliar = binaria(itens, tamanho, codigo_auxiliar);

    if(auxiliar != -1){
        cout << itens[auxiliar].nome << " em estoque!" << endl;
    } else {
        cout << "Nao existem produtos com esse codigo em estoque!" << endl;
    }

    delete[] itens;
    return 0;
}