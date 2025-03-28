#include <iostream>

using namespace std;

typedef struct dados{
    int codigo;
    float EM;
    float P;
    float D;
    float A;
    int PF;
} Dados;

struct treenode {
    Dados torta;
    treenode *esquerda;
    treenode *direita;
};

typedef treenode *treenodeptr;

void tree_insert(treenodeptr &tree, Dados t){
    if(tree == NULL){
        tree = new treenode;
        tree->torta = t;
        tree->esquerda = NULL;
        tree->direita = NULL;
    } else if (t.PF < tree->torta.PF){
        tree_insert(tree->esquerda, t);
    } else {
        tree_insert(tree->direita, t);
    }
}

int calcula_PF(Dados torta){
    return (torta.EM + torta.P + (torta.A * torta.D) + torta.A);
}

void imprime(treenodeptr tree){
    cout << tree->torta.codigo << ":";
    cout << tree->torta.PF << endl;
}

void ordenar(treenodeptr tree){
    if(tree != NULL){
        ordenar(tree->esquerda);
        imprime(tree);
        ordenar(tree->direita);
    }
}

void destroy_tree(treenodeptr &tree){
    if (tree != NULL){
        destroy_tree(tree->esquerda);
        destroy_tree(tree->direita);
        delete tree;
    }
    tree = NULL;
}

int main(){
    int T;
    Dados torta;
    treenodeptr tree = NULL;

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> torta.EM >> torta.P >> torta.D >> torta.A;
        torta.PF = calcula_PF(torta);
        torta.codigo = i;

        tree_insert(tree, torta);
    }

    ordenar(tree);

    destroy_tree(tree);

    return 0;
}