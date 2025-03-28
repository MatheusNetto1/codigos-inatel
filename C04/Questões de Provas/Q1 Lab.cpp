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

    p = 0;

    for(int i = 0; i < n; i++){
        if(i != planeta_inicial){
            v[p] = i;
            p++;
        }
    }
    
    cout << "0 ";
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    

    return 0;
}