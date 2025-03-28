#include <iostream>
using namespace std;

typedef struct box{
	int volume;
	int quant;
	int preco;
}box;

int main()
{
	int contAlt, contLarg, contComp; // altura larcura e comprimento do container
	int contVol; // volume do container e volume total das caixas
	int maiorPreco = 0;
	int ai=0, bi=0, ci=0; // quantidades ideais de cada caixa
	
	cin >> contAlt >> contLarg >> contComp;
	contVol = contAlt*contLarg*contComp;
	
	box caixa[3];
	
	caixa[0].volume = 20; // caixa A
	caixa[0].quant = 10;
	caixa[0].preco = 200;
	caixa[1].volume = 3;  // caixa B
	caixa[1].quant = 20;
	caixa[1].preco = 150;
	caixa[2].volume = 4;  // caixa C
	caixa[2].quant = 25;
	caixa[2].preco = 100;
	
	for(int a = 0; a <= caixa[0].quant; a++){
		for(int b = 0; b <= caixa[1].quant; b++){
			for(int c = 0; c <= caixa[2].quant; c++){
				int vol = a * caixa[0].volume + b * caixa[1].volume + c * caixa[2].volume;
				if(vol <= contVol){
					int preco = a * caixa[0].preco + b * caixa[1].preco + c * caixa[2].preco;
					if(preco > maiorPreco){
						maiorPreco = preco;
						ai = a;
						bi = b;
						ci = c;
					}
				}
			}
		}
	}
	
	cout << "O melhor preco e: " << maiorPreco << endl;
    cout << "Quantidade de caixas A: " << ai << endl;
    cout << "Quantidade de caixas B: " << bi << endl;
    cout << "Quantidade de caixas C: " << ci << endl;
		
	return 0;
}