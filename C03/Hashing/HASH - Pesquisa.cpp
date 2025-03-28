#include <iostream>

using namespace std;

struct dados{
    int k;
    int status;
};

int h(int k, int m){
    return k % m;
}

int hash_aux(int k, int m){
    int posicao = h(k, m);

    if(posicao < 0){
        posicao += m;
    }

    return posicao;
}

int hash1(int k, int i, int m){
    return (hash_aux(k, m) + i) % m;
}

int hash_insert(dados T[], int k, int m){
    int i = 0;
    do{
        int j = hash1(k, i, m);
        if(T[j].status != 1){
            T[j].k = k;
            T[j].status = 1;
            return j;
        } else {
            i++;
        }
    }while(i != m);
    return -1;
}

int hash_search(dados T[], int k, int m){
    int j, i = 0;
    do{
        j = hash1(k, i, m);
        if(T[j].k == k){
            return j;
        }
        i++;
    }while(T[j].status != 0 && i < m);
    return -1;
}

int main(){
    int k, m;
    int element_search, position_search;
    
    cin >> m;
    
    dados T[m];

    for(int i = 0; i < m; i++){
        T[i].k = -1;
        T[i].status = 0;
    }

    cin >> k;
    while(k != 0){
        hash_insert(T, k, m);
        cin >> k;
    }

    cin >> element_search;
    position_search = hash_search(T, element_search, m);
    if(position_search != -1){
        cout << "Chave " << element_search << " encontrada na posicao " << position_search << endl;
    } else {
        cout << "Chave " << element_search << " nao encontrada" << endl;
    }

    return 0;
}