#include <iostream>

using namespace std;

int solucaoPeso[5][400];
int solucaoVolume[5][1000];

int n = 5;

int peso[5] = {263,127,254,134,111};
int volume[5]= {455,521,857,65,12};
int valor[5]= {500,410,320,315,280};

int mochila(int item, int capacidadePeso, int capacidadeVolume) {
    if(item >= n)
        return 0;

    if(solucaoPeso[item][capacidadePeso] != -1)
        return solucaoPeso[item][capacidadePeso];
    
    if(solucaoVolume[item][capacidadeVolume] != -1)
        return solucaoPeso[item][capacidadeVolume];
    
    // escolhi o item atual
    int ans1 = 0;
    if(capacidadePeso >= peso[item] && capacidadeVolume >= volume[item])
        ans1 = mochila(item+1, capacidadePeso - peso[item], capacidadeVolume - volume[item]) + valor[item];

    // nao escolhi o item atual
    int ans2 = mochila(item+1, capacidadePeso, capacidadeVolume);

    int ans = max(ans1, ans2);

    solucaoPeso[item][capacidadePeso] = ans;
    solucaoVolume[item][capacidadeVolume] = ans;
    return ans;
}

int main(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 400; j++)
            solucaoPeso[i][j] = -1;
        
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 1000; j++)
            solucaoVolume[i][j] = -1;
    
    cout << mochila(0, 400, 1000) << endl;

    return 0;
}