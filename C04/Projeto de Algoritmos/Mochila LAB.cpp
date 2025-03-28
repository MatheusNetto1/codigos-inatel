//complexidade:

//1) O(n)

//2) O(n)

//3)

#include <iostream>//mochila01

using namespace std;

struct item{
    
    int val; // valor das obras
    int peso; // peso das obras
    
};

int main (){
    
    int pd[100][100];
    int caminho[100][100];
    int n;
    int capacidade; // capacidade da mochila
    item v[100]; // Vetor Struct
    
    //Entrada:
    cout << "Entre com a quantidade de itens" << endl;
    cin >> n;
    
    cout << "Entre com a capacidade da mochila" << endl;
    cin >> capacidade;
    
    for(int i=0; i<n; i++){
        cout << "Entre com o valor e peso do item" << endl;
        cin >> v[i].val >> v[i].peso; 
    }
    
    //Caso Base:
    for(int j = 0; j <= capacidade; j++)
		pd[n][j] = 0;

	for(int i = 0; i <= n; i++)
		pd[i][0] = 0;
    
    //Caso Geral:   
    for(int i = n - 1; i >= 0; i--) {
		for(int j = 1; j <= capacidade; j++)
		{
			int pega, npega; // val. para caso eu pegar ou nao pegar o item 'i'
			
			npega = pd[i + 1][j]; // olhar o proximo item, mantendo a capacidade 'j'

			if(j >= v[i].peso) // se eu tiver capacidade disponivel p/ pegar o item 'i'
				pega = pd[i + 1][j - v[i].peso] + v[i].val;
			// olho o proximo item, subtraio o peso da capacidade
			// disponivel, e somo o valor do item 'i'
			else
				pega = 0; // se nao posso pegar, o valor eh 0

			if(pega > npega) // se valer a pena pegar
			{
				pd[i][j] = pega;
				caminho[i][j] = 1;
			}
			
			else // se valer a pena nao pegar
			{
				pd[i][j] = npega;
				caminho[i][j] = 0;
			}
        }
    }

    cout << "O valor maximo que consigo guardar e " << pd[0][capacidade] << endl;
    
    // Recuperacao
    // Comeca na posicao final 
    int i, j;
    i = 0;
    j = capacidade;
    
    while(i != n){
        if(caminho[i][j] == 0){
            i++;
        }
        
        else{
            cout << "Peguei o item " << i << endl;
            cout << "Peso: " << v[i].peso << endl;
            cout << "Valor: " << v[i].val << endl;
            cout << "<----------------------->" << endl;
            j -= v[i].peso;
            i++;
        }
    }   
    
    return 0;
}