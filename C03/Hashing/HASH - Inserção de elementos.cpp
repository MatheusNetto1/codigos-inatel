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

int main(){
    int k, m;
    
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

    for(int i = 0; i < m; i++){
        cout << T[i].k << " ";
    }

    return 0;
}