#include <iostream>
#include <iomanip>

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
    } else if(busca == tree->numero){
        return tree;
    } else {
        if(busca < tree->numero){
            return search_tree(tree->esquerda, busca);
        } else {
            return search_tree(tree->direita, busca);
        }
    }
}

treenodeptr tree_menor(treenodeptr &tree){
    treenodeptr t = tree;

    if (t->esquerda == NULL){
        tree = tree->direita;
        return t;
    } else {
        return tree_menor(tree->esquerda);
    }
}

int remove(treenodeptr &tree, int remove_numero){
    treenodeptr p;

    if (tree == NULL){
        return 1;
    }
    if (remove_numero == tree->numero){
        p = tree;
        if (tree->esquerda == NULL){
            tree = tree->direita;
        } else if (tree->direita == NULL){
            tree = tree->esquerda;
        } else {
            p = tree_menor(tree->direita);
            tree->numero = p->numero;
        }
        
        delete p;
        p = NULL;
        return 0;
    } else if (remove_numero < tree->numero){
        return remove(tree->esquerda, remove_numero);
    } else {
        return remove(tree->direita, remove_numero);
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
    treenodeptr tree = NULL;
    int n, node_info;
    char opcao_menu;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> opcao_menu >> node_info;
        switch (opcao_menu) {
        case 'i':
            tree_insert(tree, node_info);
            break;

        case 'b':
            ;
            if(search_tree(tree, node_info) != NULL){
                cout << "Sim" << endl;
            } else {
                cout << "Nao" << endl;
            }
            break;

        case 'r':
            remove(tree, node_info);
            break;
        
        default:
            break;
        }
    }

    destroy_tree(tree);
    return 0;
}