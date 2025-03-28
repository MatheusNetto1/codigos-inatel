#include <iostream>

using namespace std;

struct dados{
    int k;
    int status;     // 0 - vazia, 1 - ocupada, 2 - removida
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

int hash_remove(dados T[], int k, int m){
    int j = hash_search(T, k, m);
    if(j != -1){
        T[j].k = -1;
        T[j].status = 2;
        return 0;
    } else {
        return -1;
    }
}

int main(){
    int k, m;
    int element_remove;
    
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

    cin >> element_remove;
    hash_remove(T, element_remove, m);
    for(int i = 0; i < m; i++){
        cout << T[i].k << " ";
    }
    
    return 0;
}