#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
    int custo[100][100];

    int n;
    int foco_inicial;

    cin >> n;
    while(n < 2 || n > 8){
        cin >> n;
    }
    
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            cin >> custo[i][j];
            custo[j][i] = custo[i][j];
        }
    }

    cin >> foco_inicial;
    while(foco_inicial < 0 || foco_inicial > (n - 1)){
        cin >> foco_inicial;
    }

    int v[100];
    int p;
    int menor_custo;
    int custo_caminho;

    p = 0;

    for(int i = 0; i < n; i++){
        if(i != foco_inicial){
            v[p] = i;
            p++;
        }
    }

    menor_custo = INT_MAX;

    //Força Bruta
    do{
        custo_caminho = custo[foco_inicial][v[0]];

        for(int i = 0; i < n - 2; i++){
            custo_caminho += custo[v[i]][v[i + 1]];
        }

        custo_caminho += custo[v[n - 2]][foco_inicial];

        menor_custo = min(menor_custo, custo_caminho);
    }while(next_permutation(v, v + (n - 1)));

    cout << menor_custo << endl;

    return 0;
}