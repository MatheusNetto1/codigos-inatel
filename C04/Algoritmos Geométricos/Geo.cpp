#include <iostream>
#include <cmath>

using namespace std;

struct ponto {
    int x;
    int y;
};

int area_triangulo (ponto a, ponto b, ponto c){
    return (a.x * b.y - a.y * b.x + a.y * c.x - a.x * c.y + b.x * c.y - b.y * c.x)/2;
}

int sentido_rotacao(ponto a, ponto b, ponto c){
    int area = area_triangulo(a, b, c);
    if (area > 0){
        return 1; // anti-horario
    } else if (area < 0){
        return 2; // horario
    } else {
        return 0; // colinear
    }
}

int main(){
    string sentidos[] = {"Colinear", "Anti-horario", "Horario"};
    int tprincipal;
    int l1, l2, l3;

    ponto a;
    a.x = 1;
    a.y = 2;

    ponto b;
    b.x = 4;
    b.y = 4;

    ponto c;
    c.x = 4;
    c.y = 1;

    cout << "Area: " << area_triangulo(a, b, c) << endl;
    cout << "Sentido: " << sentidos[sentido_rotacao(a, b, c)] << endl;

    ponto p1;
    ponto p2;
    ponto p3;

    ponto p;

    tprincipal = area_triangulo(p1, p2, p3);

    l1 = area_triangulo(p, p2, p3);
    l2 = area_triangulo(p1, p, p3);
    l3 = area_triangulo(p, p2, p3);

    return 0;
}