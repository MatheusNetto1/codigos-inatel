#include <iostream>
#include <string>

using namespace std;

struct info{
    string nome;
    string fabricante;
    int tier;
    float taxaPsicose;
};

int main(){
    info *implantes = NULL;
    info *p = NULL;

    float soma = 0;
    int N;

    cin >> N;

    implantes = new info[N];

    p = implantes;

    for(int i = 0; i < N; i++){
        getline(cin >> ws, p->nome);
        getline(cin >> ws, p->fabricante);
        do{
            cin >> p->tier;
        }while(p->tier < 1 || p->tier > 5);
        cin >> p->taxaPsicose;

        soma += p->taxaPsicose;
        p++;
    }

    if(soma > 60.){
        cout << "Alerta! Recompensa de 50000 edinhos pela cabeca do Ciberpsicopata." << endl;
    } else {
        cout << "Vamos tchum! temos uma cidade pra conquistar!" << endl;
    }

    delete[] implantes;
    return 0;
}