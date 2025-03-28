#include <iostream>

using namespace std;

int h1(int k, int m){
    int h = k % m;

    if(h < 00){
        h += m;
    }

    return h;
}

int h2(int k, int m){
    int h = 1 + (k % (m - 1));

    if(h < 00){
        h += m;
    }

    return h;
}

int dhash(int k, int i, int m){
    return (h1(k, m) + i*h2(k, m)) % m;
}

int main(){
    int k, m;

    cin >> k >> m;
    for(int i = 0; i < m; i++){
        cout << dhash(k, i, m) << " ";
    }

    return 0;
}