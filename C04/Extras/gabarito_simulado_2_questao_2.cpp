#include <iostream>
#include <math.h>
using namespace std;

typedef struct {
	int x;
	int y;	
} Ponto;

double area_triangulo(
	Ponto a, 
	Ponto b, 
	Ponto c
){
	return 
		((a.x*b.y) - (a.y*b.x) + 
		(a.y*c.x) - (a.x*c.y) + 
		(b.x*c.y) - (b.y*c.x))/2.0;  
}

double distancia(Ponto p1, Ponto p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y));
}

int orientacao(Ponto a, Ponto b, Ponto c){
	double area = area_triangulo(a,b,c);
	if(area > 0){
		return 1; 
	} else if(area < 0){
		return -1; 
	} else {
		return 0; 
	}
}

int main(){
    Ponto pontoa, pontob, pontoc, pontod;
    cin>>pontoa.x>>pontoa.y;
    cin>>pontob.x>>pontob.y;
    cin>>pontoc.x>>pontoc.y;
    cin>>pontod.x>>pontod.y;
    
    int em, a, d;
    em = distancia(pontoa, pontob);
    a = distancia(pontoa, pontoc);
    d = distancia(pontoc, pontod);
    
    cout << em << endl << d << endl << a << endl;
    return 0;
}












