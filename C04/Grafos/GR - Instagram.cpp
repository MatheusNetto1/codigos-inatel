#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(){
    int numeroDeUsuarios;
    string nomeDosUsuarios[10];
    list <int> usuariosSeguidos[10];
    list <int> :: iterator p;
    int usuarioSeguido;
    int verificarUsuario;

    cin >> numeroDeUsuarios;

    for(int i = 0; i < numeroDeUsuarios; i++){
        getline(cin >> ws, nomeDosUsuarios[i]);
    }

    for(int i = 0; i < numeroDeUsuarios; i++){
        cin >> usuarioSeguido;
        while(usuarioSeguido != -1){
            usuariosSeguidos[i].push_back(usuarioSeguido);
            cin >> usuarioSeguido;
        }
    }

    cin >> verificarUsuario;
    for(int i = 0; i < numeroDeUsuarios; i++){
        for(p = usuariosSeguidos[i].begin(); p != usuariosSeguidos[i].end(); ++p){
            if(verificarUsuario == *p){
                cout << nomeDosUsuarios[i] << endl;
                break;
            }
        }
    }

    int i = 0;
    while (!usuariosSeguidos[i].empty()) {
        usuariosSeguidos[i].pop_front();
        i++;
    }

    return 0;
}
