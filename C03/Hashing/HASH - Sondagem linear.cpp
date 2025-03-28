#include <iostream>

using namespace std;

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

int main(){
    int k, m;

    cin >> k >> m;
    for(int i = 0; i < m; i++){
        cout << hash1(k, i, m) << " ";
    }

    return 0;
}