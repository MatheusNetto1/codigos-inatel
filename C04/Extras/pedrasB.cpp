#include<iostream>
#include<string>
using namespace std;

#define ITENS 1000
#define CAP_PESO 400
#define CAP_VOLUME 1000

int memoria[ITENS][CAP_PESO][CAP_VOLUME];

struct pedra{
	string nome;
	int valor;
	int peso;
	int volume;	
};

int potencia(int base, int expoente){
	if(expoente == 0) return 1;
	return base * potencia(base, expoente-1);
}

int calcula_valor(pedra pedras[], int n, int cap_peso, int cap_volume, bool pedras_atuais[]){
	int valor = 0;
	for(int i=0; i<n; i++){
		if(pedras_atuais[i]){
			cap_peso -= pedras[i].peso;
			cap_volume -= pedras[i].volume;
			if(cap_peso >= 0 && cap_volume >= 0){
				valor += pedras[i].valor;
			} else return 0;			
		}
	}
	return valor;
}

void escolhe_pedras_gulosa(pedra pedras[], int n,int cap_peso, int cap_volume){
	for(int i=0; i<n; i++){
		if(cap_peso >= pedras[i].peso && cap_volume >= pedras[i].volume){
			cout<< pedras[i].nome << endl;
			cap_peso -= pedras[i].peso;
			cap_volume -= pedras[i].volume;
		}
	}
}

void escolhe_pedras_iterativo(pedra pedras[], int n, int cap_peso, int cap_volume){
	bool melhores_pedras[n], pedras_atuais[n];
	for(int i=0; i<n; i++){
		melhores_pedras[i] = false;
		pedras_atuais[i] = false;
	}
	int valor_atual = 0, melhor_valor = 0;
	int limite = potencia(2, n);
	for(int i=1; i <= limite; i++){
		for(int i=0; i<n; i++){
			if(pedras_atuais[i] == false){
				pedras_atuais[i] = true;
				break;
			} else {
				pedras_atuais[i] = false;
			}
		}
		valor_atual = calcula_valor(pedras, n, cap_peso, cap_volume, pedras_atuais);
		if(valor_atual > melhor_valor){
			melhor_valor = valor_atual;
			for(int i=0; i<n; i++)
				melhores_pedras[i] = pedras_atuais[i];
		}
	}
	cout << melhor_valor << endl;
	for(int i=0; i<n; i++){
		if(melhores_pedras[i])
		  cout << pedras[i].nome << endl;
	}
}

int escolhe_pedras(pedra pedras[], int n, int i, int cap_peso, int cap_volume){
	if( i >= n || cap_peso <= 0 || cap_volume <= 0){
		return 0;
	}
	
	int solucao1=0, solucao2 = 0;
	solucao1 = 0 + 
	escolhe_pedras(pedras, n, i+1, cap_peso, cap_volume);
	
	int nova_cap_peso = cap_peso - pedras[i].peso;
	int nova_cap_volume = cap_volume - pedras[i].volume;
	if(nova_cap_peso >= 0 && nova_cap_volume >= 0){
		solucao2 = pedras[i].valor + 
		escolhe_pedras(pedras, n, i+1, nova_cap_peso, nova_cap_volume);
	}
	
	return max(solucao1, solucao2);
}

int escolhe_pedras_pd(pedra pedras[], int n, int i, int cap_peso, int cap_volume){
	if( i >= n || cap_peso <= 0 || cap_volume <= 0){
		return 0;
	}
	if(memoria[i][cap_peso][cap_volume] != -1)
		return memoria[i][cap_peso][cap_volume];
	int solucao1=0, solucao2 = 0;
	solucao1 = 0 + 
	escolhe_pedras_pd(pedras, n, i+1, cap_peso, cap_volume);
	
	int nova_cap_peso = cap_peso - pedras[i].peso;
	int nova_cap_volume = cap_volume - pedras[i].volume;
	if(nova_cap_peso >= 0 && nova_cap_volume >= 0){
		solucao2 = pedras[i].valor + 
		escolhe_pedras_pd(pedras, n, i+1, nova_cap_peso, nova_cap_volume);
	}
	
	memoria[i][cap_peso][cap_volume] = max(solucao1, solucao2);
	return memoria[i][cap_peso][cap_volume];
}

void inicializa_memoria(){
	for(int i=0; i<ITENS; i++){
		for( int j=0; j < CAP_PESO; j++){
			for(int k=0; k<CAP_VOLUME; k++){
				memoria[i][j][k] = -1;
			}
		}
	}
}

int main(){
	inicializa_memoria();
	int n;
	cin >> n;
	pedra pedras[n];
	for(int i=0; i<n; i++){
		float volume;
		cin>>pedras[i].nome;
		cin>>volume;
		pedras[i].volume = volume*1000;
		cin>>pedras[i].peso;
		cin>>pedras[i].valor;
	}
	
	cout << escolhe_pedras_pd(pedras, n, 0, 400, 1000) << endl;
	//escolhe_pedras_iterativo(pedras, n, 400, 1000);
	
	return 0;
}