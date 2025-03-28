#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
    int custo[100][100];

    int n;
    int planeta_inicial;

    cin >> n;
    while(n < 1 || n > 10){
        cin >> n;
    }
    
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            cin >> custo[i][j];
            custo[j][i] = custo[i][j];
        }
    }

    cin >> planeta_inicial;
    while(planeta_inicial < 0 || planeta_inicial > (n - 1)){
        cin >> planeta_inicial;
    }

    int v[100];
    int p;
    int maior_custo;
    int custo_caminho;

    p = 0;

    for(int i = 0; i < n; i++){
        if(i != planeta_inicial){
            v[p] = i;
            p++;
        }
    }

    maior_custo = INT_MIN;

    //Força Bruta
    do{
        custo_caminho = custo[planeta_inicial][v[0]];

        for(int i = 0; i < n - 2; i++){
            custo_caminho += custo[v[i]][v[i + 1]];
        }

        custo_caminho += custo[v[n - 2]][planeta_inicial];

        maior_custo = max(maior_custo, custo_caminho);
    }while(next_permutation(v, v + (n - 1)));

    cout << maior_custo << endl;

    return 0;
}