#include <iostream>
#include <list>

using namespace std;

struct dado{
	int k;
	int status;
};

int h1(int k, int m){
	int pos = k % m;

	if(pos < 0)
		pos += m;

	return pos;
}

int h2(int k, int m){
	int pos = 1 + k % (m - 1);

	if(pos < 0)
		pos += m;

	return pos;
}

int hash(int k, int m, int i){
	return (h1(k, m) + (i * h2(k, m))) % m;
}

void hash_insert(dado t[], int k, int m){
	int i;
	int j;
	i = 0;

	while(i < m)
	{
		j = hash(k, m, i);
		if(t[j].status == 0 || t[j].status == 2)
		{
			t[j].k = k;
			t[j].status = 1;
			return ;
		}
		else i++;
	}
}

int hash_search(dado t[], int k, int m){
	int i;
	int j;
	i = 0;
	do
	{
		j = hash(k, m, i);
		if(t[j].k == k)
			return j;
		else i++;
	}
	while(t[j].status != 0 || i < m);

	return -1;
}

void hash_remove(dado t[], int k, int m){
	int j;
	j = hash_search(t, k, m);
	if(j != -1)
	{
		t[j].status = 2;
		t[j].k = -1;
	}
}

int main()
{
	int k; // chave
	int m; // tamanho da tabela
    list<int> pilha;
	dado t[100]; // tabela hash
	int x; // quantidade de elementos inseridos
    int aux;

	cin >> m;
    cin >> x;

    for(int i = 0; i < x; i++){
        cin >> aux;
        pilha.push_front(aux);
    }

	for(int i = 0; i < m; i++){
		t[i].status = 0;
		t[i].k = -1;
	}

    while(!pilha.empty()){
        aux = *pilha.begin();
        hash_insert(t, aux, m);
        pilha.pop_front();
    }

	for(int i = 0; i < m; i++)
		cout << t[i].k << " ";

}