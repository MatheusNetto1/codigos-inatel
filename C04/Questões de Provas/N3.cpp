#include <iostream>
#include <math.h>

using namespace std;

typedef struct {
    int x;
    int y;
} Ponto;

float distancia(Ponto p1, Ponto p2){
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int main(){
    Ponto A, B, C, D;

    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;

    // considerando que o diametro da figura eh igual tanto na base como no topo, entao basta medir a distancia entre uma extremidade e outra 
    cout << (int)distancia(C, D) << endl;
    // seguindo a mesma logica, a altura vai ser a distancia de um ponto no topo ate um ponto na base da mesma extremidade
    cout << (int)distancia(C, A) << endl;

    return 0;
}