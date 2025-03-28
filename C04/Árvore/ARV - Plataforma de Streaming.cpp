#include <iostream>
#include <string>

using namespace std;

struct dados {
    string nome, genero;
    int duracao, classificacao, ano;
};

struct treenode {
    dados filme;
    treenode *esquerda;
    treenode *direita;
};

typedef treenode *treenodeptr;

void tree_insert(treenodeptr &tree, dados filme){
    if(tree == NULL){
        tree = new treenode;
        tree->filme = filme;
        tree->esquerda = NULL;
        tree->direita = NULL;
    } else if (filme.nome < tree->filme.nome){
        tree_insert(tree->esquerda, filme);
    } else {
        tree_insert(tree->direita, filme);
    }
}

treenodeptr search_tree(treenodeptr tree, string nome_busca){
    if(tree == NULL){
        return NULL;
    }
    if(nome_busca == tree->filme.nome){
        return tree;
    }
    if(nome_busca < tree->filme.nome){
        return search_tree(tree->esquerda, nome_busca);
    } else {
        return search_tree(tree->direita, nome_busca);
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
    int opcao_menu;
    bool sair_do_programa = false;
    string nome_busca;
    treenodeptr tree = NULL, tree_busca = NULL;
    dados filme_auxiliar;

    do {
        cin >> opcao_menu;
        switch (opcao_menu) {
        case 0:
            sair_do_programa = true;
            break;

        case 1:
            getline(cin >> ws, filme_auxiliar.nome);
            getline(cin >> ws, filme_auxiliar.genero);
            cin >> filme_auxiliar.duracao >> filme_auxiliar.classificacao >> filme_auxiliar.ano;
            tree_insert(tree, filme_auxiliar);
            break;

        case 2:
            getline(cin >> ws, nome_busca);
            tree_busca = search_tree(tree, nome_busca);
            if(tree_busca != NULL){
                cout << "Nome: " << tree_busca->filme.nome << endl;
                cout << "Genero: " << tree_busca->filme.genero  << endl;
                cout << "Duracao: " << tree_busca->filme.duracao << " mins" << endl;
                cout << "Classificacao: " << tree_busca->filme.classificacao << endl;
                cout << "Ano: " << tree_busca->filme.ano << endl;
            } else {
                cout << "Filme nao encontrado" << endl;
            }
            break;
        
        default:
            cout << "Operacao invlida" << endl;
            break;
        }
    } while (!sair_do_programa);

    destroy_tree(tree);

    return 0;
}