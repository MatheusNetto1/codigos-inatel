#include<iostream>
using namespace std;

struct ponto {
	int x, y;	
};

float area_triangulo(ponto a, ponto b, ponto c){
	float area = 	(a.x*b.y) - (a.y*b.x) + 
					(a.y*c.x) - (a.x*c.y) + 
					(b.x*c.y) - (b.y*c.x);
	area = area / 2;
	return area;
}

int posicao_relativa(ponto a, ponto b, ponto p){
	float area = area_triangulo(a,b,p);
	if(area > 0)
		return 1;
	if(area < 0)
		return -1;
	return 0;
	
}

int main(){
	
	// ponto a, b, c;
	// a.x = 1;
	// a.y = 2;
	// b.x = 4;
	// b.y = 4;
	// c.x = 4;
	// c.y = 1;
	// 
	// float resultado = area_triangulo(a,b,c);
	// cout << resultado << endl;
	// if(resultado > 0){
	// 	cout << "Sentido anti-horario" << endl;
	// } else if(resultado < 0) {
	// 	cout << "Sentido horario" << endl;
	// } else {
	// 	cout << "Os pontos s�o colineares" << endl;
	// }
	
	// ponto p = {3,2};
	ponto p1 = {1,2};
	ponto p2 = {4,4};
	ponto p3 = {4,1};
	// float a = area_triangulo(p1,p2,p3);
	// float l1 = area_triangulo(p,p2,p3)/a;
	// float l2 = area_triangulo(p1,p,p3)/a;
	// float l3 = area_triangulo(p1,p2,p)/a;
	// 
	// cout << l1 << endl;
	// cout << l2 << endl;
	// cout << l3 << endl;
	
	
	
	int pos = posicao_relativa(p1,p2,p3);
	if(pos > 0){
		cout<<"A esquerda"<<endl;
	} else if (pos < 0) {
		cout<<"A direita"<<endl;
	} else {
		cout<<"Alinhado"<<endl;
	}
	
	
	
	
	return 0;
}