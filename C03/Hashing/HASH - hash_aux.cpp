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

int main(){
    int k, m;

    cin >> k >> m;
    while(k != 0 || m != 0){
        cout << hash_aux(k, m) << endl;
        cin >> k >> m;
    }

    return 0;
}