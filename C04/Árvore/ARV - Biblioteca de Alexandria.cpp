#include <iostream>
#include <string>

using namespace std;

struct treenode {
    int numero;
    treenode *esquerda;
    treenode *direita;
};

typedef treenode *treenodeptr;

void tree_insert(treenodeptr &tree, int insere){
    if(tree == NULL){
        tree = new treenode;
        tree->numero = insere;
        tree->esquerda = NULL;
        tree->direita = NULL;
    } else if (insere < tree->numero){
        tree_insert(tree->esquerda, insere);
    } else {
        tree_insert(tree->direita, insere);
    }
}

treenodeptr search_tree(treenodeptr tree, int busca){
    if(tree == NULL){
        return NULL;
    }
    if(busca == tree->numero){
        return tree;
    }
    if(busca < tree->numero){
        return search_tree(tree->esquerda, busca);
    } else {
        return search_tree(tree->direita, busca);
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

int main() {
    treenodeptr tree = NULL;
    treenodeptr tree_auxiliar = NULL;
    int N;
    int manuscrito;
    string opcao;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> opcao;
        cin >> manuscrito;

        if (opcao == "i") {
            tree_insert(tree, manuscrito);
        } else if (opcao == "b") {
            tree_auxiliar = search_tree(tree, manuscrito);
            if (tree_auxiliar != NULL){
                cout << "Sim" << endl;
            } else {
                cout << "Não" << endl;
            }
        }
    }

    destroy_tree(tree);
    return 0;
}