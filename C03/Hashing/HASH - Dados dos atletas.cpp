#include <iostream>
#include <string.h>

using namespace std;

struct info {
    string nome;
    int idade;
    float peso;
    float altura;
};

struct table {
    info atleta;
    int k;
    int status;
};

int h1(int k, int m) {
    int h = k % m;
    if (h < 0) {
        h += m;
    }
    return h;
}

int h2(int k, int m) {
    int h = 1 + (k % (m - 1));
    if (h < 0) {
        h += m;
    }
    return h;
}

int dhash(int k, int i, int m) {
    return (h1(k, m) + i * h2(k, m)) % m;
}

int hash_insert(table T[], int k, int m, info atleta) {
    int i = 0;
    do {
        int j = dhash(k, i, m);
        if (T[j].status != 1) {
            T[j].k = k;
            T[j].status = 1;
            T[j].atleta = atleta;
            return j;
        } else {
            i++;
        }
    } while (i != m);
    return -1;
}

int hash_search(table T[], int k, int m) {
    int j, i = 0;
    do {
        j = dhash(k, i, m);
        if (T[j].k == k) {
            return j;
        }
        i++;
    } while (T[j].status != 0 && i < m);
    return -1;
}

int hash_remove(table T[], int k, int m) {
    int j = hash_search(T, k, m);
    if (j != -1) {
        T[j].k = -1;
        T[j].status = 2;
        return 0;
    } else {
        return -1;
    }
}

int main() {
    int k, m, opcao_menu, posicao_busca;
    bool sair_do_programa = false;
    info atleta_value;
    string nome_busca;

    cin >> m;

    table T[m];

    for (int i = 0; i < m; i++) {
        T[i].k = -1;
        T[i].status = 0;
    }

    do {
        cin >> opcao_menu;
        switch (opcao_menu) {
            case 1:
                k = 0;
                getline(cin >> ws, atleta_value.nome);
                cin >> atleta_value.idade >> atleta_value.peso >> atleta_value.altura;
                for (unsigned int i = 0; i < atleta_value.nome.length(); i++) {
                    k += atleta_value.nome[i];
                }
                hash_insert(T, k, m, atleta_value);
                break;

            case 2:
                k = 0;
                getline(cin >> ws, nome_busca);
                for (unsigned int i = 0; i < nome_busca.length(); i++) {
                    k += nome_busca[i];
                }
                posicao_busca = hash_search(T, k, m);

                if (posicao_busca != -1) {
                    cout << T[posicao_busca].atleta.nome << endl;
                    cout << T[posicao_busca].atleta.idade << endl;
                    cout << T[posicao_busca].atleta.peso << endl;
                    cout << T[posicao_busca].atleta.altura << endl;
                } else {
                    cout << nome_busca << " nao encontrado" << endl;
                }
                break;

            case 3:
                k = 0;
                getline(cin >> ws, nome_busca);
                for (unsigned int i = 0; i < nome_busca.length(); i++) {
                    k += nome_busca[i];
                }
                hash_remove(T, k, m);
                break;

            case 4:
                for (int i = 0; i < m; i++) {
                    if (T[i].status == 1) {
                        cout << "Nome: " << T[i].atleta.nome << endl;
                        cout << "Idade: " << T[i].atleta.idade << endl;
                        cout << "Peso: " << T[i].atleta.peso << endl;
                        cout << "Altura: " << T[i].atleta.altura << endl;
                        cout << endl;
                    }
                }
                break;

            case 5:
                sair_do_programa = true;
                break;

            default:
                break;
        }
    } while (!sair_do_programa);

    return 0;
}