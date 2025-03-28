#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

// estrutura para definir o ponto
struct ponto {
    float x;
    float y;
};

// estrutura para armazenar os dados do pokemon
typedef struct pokemon{
    string nome;                    // nome do pokemon
    string tipo;                    // tipo do pokemon
    int id;                         // id do pokemon
    string pokebola;                // pokebola do pokemon
    ponto coordenada;
} Pokemon;

// estrutura do no da arvore
struct treenode{
    Pokemon info;                       // informacoes do pokemon
    treenode *esquerda;                 // ponteiro do nó que vai apontar para a esquerda
    treenode *direita;                  // ponteiro do nó que vai apontar para a esquerda
};

// define o nó da arvore como um ponteiro
typedef treenode *treenodeptr;

// função para inserir na arvore organizando pelo id
void tree_insert_id(treenodeptr &tree_id, Pokemon p){
    if (tree_id == NULL){
        tree_id = new treenode;
        tree_id->info = p;
        tree_id->esquerda = NULL;
        tree_id->direita = NULL;
    } else if (p.id < tree_id->info.id){
        tree_insert_id(tree_id->esquerda, p);
    } else {
        tree_insert_id(tree_id->direita, p);
    }
}

// função para inserir na arvore organizando pelo nome
void tree_insert_name(treenodeptr &tree_name, Pokemon p){
    if (tree_name == NULL){
        tree_name = new treenode;
        tree_name->info = p;
        tree_name->esquerda = NULL;
        tree_name->direita = NULL;
    } else if (p.nome < tree_name->info.nome){
        tree_insert_name(tree_name->esquerda, p);
    } else {
        tree_insert_name(tree_name->direita, p);
    }
}

// função para inserir na arvore organizando pelo tipo
void tree_insert_type(treenodeptr &tree_type, Pokemon p){
    if(tree_type == NULL){
        tree_type = new treenode;
        tree_type->info = p;
        tree_type->esquerda = NULL;
        tree_type->direita = NULL;
    } else if (p.tipo < tree_type->info.tipo){
        tree_insert_type(tree_type->esquerda, p);
    } else {
        tree_insert_type(tree_type->direita, p);
    }
}

// função para inserir na arvore organizando pela pokebola
void tree_insert_pokebola(treenodeptr &tree_pokebola, Pokemon p){
    if(tree_pokebola == NULL){
        tree_pokebola = new treenode;
        tree_pokebola->info = p;
        tree_pokebola->esquerda = NULL;
        tree_pokebola->direita = NULL;
    } else if (p.pokebola < tree_pokebola->info.pokebola){
        tree_insert_pokebola(tree_pokebola->esquerda, p);
    } else {
        tree_insert_pokebola(tree_pokebola->direita, p);
    }
}

// função para imprimir nós da arvore
void imprime(treenodeptr tree){
    cout << "\n Nome: " << tree->info.nome << endl;
    cout << " Tipo: " << tree->info.tipo << endl;
    cout << " Id: " << tree->info.id << endl;
    cout << " Pokebola: " << tree->info.pokebola << endl;
    cout << " Coordenada: (" << tree->info.coordenada.x << "," << tree->info.coordenada.y << ")" << endl;
}

// função para organizar imprimir nós da arvore por ordem alfabetica (usada nos parametros de string)
void ordem_alfabetica(treenodeptr tree){
    if(tree != NULL){
        ordem_alfabetica(tree->esquerda);
        imprime(tree);
        ordem_alfabetica(tree->direita);
    }
}

// função para procurar todos os pokemons por pokebolas na arvore
void search_all_pokebola(treenodeptr tree, string pokebola, bool &existe_pokebola){
    if(tree != NULL){
        search_all_pokebola(tree->esquerda, pokebola, existe_pokebola);

        if (tree->info.pokebola == pokebola){
            existe_pokebola = true;                 // variavel para definir se foi achado
            imprime(tree);                          // imprime o pokemon
        }

        search_all_pokebola(tree->direita, pokebola, existe_pokebola);
    }
}

// função de busca pokemon por nome
treenodeptr search_name(treenodeptr tree, string nome){
    if(tree == NULL){
        return NULL;
    }
    if(nome == tree->info.nome){
        return tree;
    }
    if(nome < tree->info.nome){
        return search_name(tree->esquerda, nome);
    } else {
        return search_name(tree->direita, nome);
    }
}

// função de busca pokemon por tipo
treenodeptr search_type(treenodeptr tree, string tipo, int &contador_tipo){
    if(tree == NULL){
        return NULL;
    }
    if(tipo == tree->info.tipo){
        contador_tipo++;
    }
    if(tipo < tree->info.tipo){
        return search_type(tree->esquerda, tipo, contador_tipo);
    } else {
        return search_type(tree->direita, tipo, contador_tipo);
    }
}

// função de busca pokemon por pokebola
treenodeptr search_pokebola(treenodeptr tree, string pokebola){
    if(tree == NULL){
        return NULL;
    }
    if(pokebola == tree->info.pokebola){
        return tree;
    }
    if(pokebola < tree->info.pokebola){
        return search_pokebola(tree->esquerda, pokebola);
    } else {
        return search_pokebola(tree->direita, pokebola);
    }
}

// função para redirecionar a árvore para o nó "menor"
treenodeptr tree_menor(treenodeptr &tree){
    treenodeptr t;
    t = tree;

    if (t->esquerda == NULL){
        tree = tree->direita;
        return t;
    } else {
        return tree_menor(tree->esquerda);
    }
}

// função para remover um pokemon pelo id
int remove_id(treenodeptr &tree_id, int id){
    treenodeptr p;

    if (tree_id == NULL){
        return 1;
    }
    if (id == tree_id->info.id){
        p = tree_id;
        if (tree_id->esquerda == NULL){
            tree_id = tree_id->direita;
        } else if (tree_id->direita == NULL){
            tree_id = tree_id->esquerda;
        } else {
            p = tree_menor(tree_id->direita);
            tree_id->info = p->info;
        }
        
        delete p;
        p = NULL;
        return 0;
    } else if (id < tree_id->info.id){
        return remove_id(tree_id->esquerda, id);
    } else {
        return remove_id(tree_id->direita, id);
    }
}

// função para remover um pokemon por nome
int remove_name(treenodeptr &tree_name, string nome){
    treenodeptr p;

    if (tree_name == NULL){
        return 1;
    }
    if (nome == tree_name->info.nome){
        p = tree_name;
        if (tree_name->esquerda == NULL){
            tree_name = tree_name->direita;
        } else if (tree_name->direita == NULL){
            tree_name = tree_name->esquerda;
        } else {
            p = tree_menor(tree_name->direita);
            tree_name->info = p->info;
        }
        
        delete p;
        p = NULL;
        return 0;
    } else if (nome < tree_name->info.nome){
        return remove_name(tree_name->esquerda, nome);
    } else {
        return remove_name(tree_name->direita, nome);
    }
}

// função para remover um pokemon por tipo
int remove_type(treenodeptr &tree_type, string tipo, string nome){
    treenodeptr p;

    if (tree_type == NULL){
        return 1;
    }
    if (tree_type->info.tipo == tipo && tree_type->info.nome == nome){
        p = tree_type;
        if (tree_type->esquerda == NULL){
            tree_type = tree_type->direita;
        } else if (tree_type->direita == NULL){
            tree_type = tree_type->esquerda;
        } else {
            p = tree_menor(tree_type->direita);
            tree_type->info = p->info;
        }
        
        delete p;
        p = NULL;
        return 0;
    } else if (tipo < tree_type->info.tipo){
        return remove_type(tree_type->esquerda, tipo, nome);
    } else {
        return remove_type(tree_type->direita, tipo, nome);
    }
}

// função para remover um pokemon por pokebola
int remove_pokebola(treenodeptr &tree_pokebola, treenodeptr &tree_id, treenodeptr &tree_name, treenodeptr &tree_type, string pokebola){
    treenodeptr p;
    int id_auxiliar;                            // id auxiliar para remover na arvore do id
    string nome_auxiliar;                       // nome auxiliar para remover na arvore do nome
    string tipo_auxiliar;                       // tipo auxiliar para remover na arvore do tipo

    if (tree_pokebola == NULL){
        return 1;
    }
    if (pokebola == tree_pokebola->info.pokebola){
        p = tree_pokebola;
        id_auxiliar = p->info.id;                           // id auxiliar recebe as informações
        nome_auxiliar = p->info.nome;                       // nome auxiliar recebe as informações
        tipo_auxiliar = p->info.tipo;                       // tipo auxiliar recebe as informações

        if (tree_pokebola->esquerda == NULL){
            tree_pokebola = tree_pokebola->direita;
        } else if (tree_pokebola->direita == NULL){
            tree_pokebola = tree_pokebola->esquerda;
        } else {
            p = tree_menor(tree_pokebola->direita);
            tree_pokebola->info = p->info;
        }

        // remove nas outras arvores
        remove_id(tree_id, id_auxiliar);                                    // remove pelo id
        remove_name(tree_name, nome_auxiliar);                              // remove pelo nome
        remove_type(tree_type, tipo_auxiliar, nome_auxiliar);               // remove pelo tipo

        delete p;
        p = NULL;
        return 0;
    } else if (pokebola < tree_pokebola->info.pokebola){
        return remove_pokebola(tree_pokebola->esquerda, tree_id, tree_name, tree_type, pokebola);
    } else {
        return remove_pokebola(tree_pokebola->direita, tree_id, tree_name, tree_type, pokebola);
    }
}

// função para determinar a distancia dos pokemons em relação a pokedex
void search_distance(treenodeptr tree, float x0, float y0, int &contador_raio){
    float x;
    float y;
    float raio_maximo = 100;
    float distancia;

    if(tree != NULL){
        x = tree->info.coordenada.x;
        y = tree->info.coordenada.y;
        distancia = sqrt(pow(x - x0, 2) + pow(y - y0, 2));                  // distancia entre dois pontos

        if (tree->esquerda != NULL){
            search_distance(tree->esquerda, x0, y0, contador_raio);
        }

        if (distancia <= raio_maximo){
            contador_raio++;                                                // contador dos pokemons dentro do raio
        }

        if (tree->direita != NULL){
            search_distance(tree->direita, x0, y0, contador_raio);
        }
    }
}

// função do trajeto pré ordem
void preOrdem(treenodeptr tree, int id_busca, int &contador_pre, int &contador_pre_final, bool &achou){
    if(tree != NULL){
        cout << tree->info.nome << " " << tree->info.id << " - ";
        if(tree->info.id != id_busca){
            contador_pre++;
        } else if (tree->info.id == id_busca){
            contador_pre_final = contador_pre;
            achou = true;
        }
        preOrdem(tree->esquerda, id_busca, contador_pre, contador_pre_final, achou);
        preOrdem(tree->direita, id_busca, contador_pre, contador_pre_final, achou);
    }
}

// função do trajeto em ordem
void emOrdem(treenodeptr tree, int id_busca, int &contador_em, int &contador_em_final, bool &achou){
    if(tree != NULL){
        emOrdem(tree->esquerda, id_busca, contador_em, contador_em_final, achou);
        cout << tree->info.nome << " " << tree->info.id << " - ";
        if(tree->info.id != id_busca){
            contador_em++;
        } else if (tree->info.id == id_busca){
            contador_em_final = contador_em;
            achou = true;
        }
        emOrdem(tree->direita, id_busca, contador_em, contador_em_final, achou);
    }
}

// função do trajeto pós ordem
void posOrdem(treenodeptr tree, int id_busca, int &contador_pos, int &contador_pos_final , bool &achou){
    if(tree != NULL){
        posOrdem(tree->esquerda, id_busca, contador_pos, contador_pos_final, achou);
        posOrdem(tree->direita, id_busca, contador_pos, contador_pos_final, achou);
        cout << tree->info.nome << " " << tree->info.id << " - ";
        if(tree->info.id != id_busca){
            contador_pos++;
        } else if (tree->info.id == id_busca){
            contador_pos_final = contador_pos;
            achou = true;
        }
    }
}

// função para destruir as arvores
void destroy_tree(treenodeptr &tree){
    if (tree != NULL){
        destroy_tree(tree->esquerda);
        destroy_tree(tree->direita);
        delete tree;
    }

    tree = NULL;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    bool existe_pokebola = false;                               // variavel para verificar se existe alguma pokebola
    bool achou_no_trajeto = false;                              // variavel para verificar se achou no trajeto

    ponto pokedex;                                              // variavel de coordenada da pokedex

    int continuar_cadastro;                                     // variavel auxiliar para o cadastro dos pokemons
    int sair_do_programa = 0;                                   // variavel para continuar o programa
    int opcao;                                                  // variavel para as opções

    // variaveis contadoras
    int contador_tipo;
    int contador_raio;
    int contador_pre;
    int contador_pre_final;
    int contador_em;
    int contador_em_final;
    int contador_pos;
    int contador_pos_final;

    int pokebola_removida = 0;                                  // auxiliar para verificar se a pokebola foi removida

    int id_busca;                                               // id a ser buscado

    string nome_busca;                                          // variavel auxiliar para busca do nome
    string tipo_busca;                                          // variavel auxiliar para busca do tipo
    string pokebola_busca;                                      // variavel auxiliar para busca da pokebola

    // declaração das arvores usadas
    treenodeptr tree_id = NULL;
    treenodeptr tree_name = NULL;
    treenodeptr tree_type = NULL;
    treenodeptr tree_pokebola = NULL;

    Pokemon pokemon_auxiliar;                                   // pokemon auxiliar para registro

    // estrutura de repetição para o menu
    do{
        cout << "\n\t\tMENU" << endl;
        cout << "\n\tSelcione a opção desejada\n"<< endl;
        cout << "\t1) Cadastrar Pokémons" << endl;
        cout << "\t2) Imprimir Pokémons cadastrados por Nome" << endl;
        cout << "\t3) Buscar Pokémons por Nome" << endl;
        cout << "\t4) Imprimir Pokémons por Tipo" << endl;
        cout << "\t5) Contar Pokémons por Tipo" << endl;
        cout << "\t6) Remover Pokémons pela Pokebola" << endl;
        cout << "\t7) Buscar Pokémons pela Pokebola" << endl;
        cout << "\t8) Verificar qual é a melhor caminho de busca (Pré-Ordem, Em Ordem, Pós-Ordem)" <<endl;
        cout << "\t9) Calcular quantos Pokémons estão perto da Pokedex" << endl;
        cout << "\t10) Sair do programa" << endl;
        cout << "\t\tOpção: ";
        cin >> opcao;

        switch (opcao){
            case 1:  // opcao 1 - cadastra pokemon
                do{
                    cout << "\n\n\tCadastre seu Pokémon:" << endl;

                    cout << "\n\tNome: ";
                    getline(cin >> ws, pokemon_auxiliar.nome);

                    cout << "\tTipo: ";
                    getline(cin >> ws, pokemon_auxiliar.tipo);

                    // id com validação de entrada
                    cout << "\tId: ";
                    cin >> pokemon_auxiliar.id;
                    while(pokemon_auxiliar.id < 0){
                        cout << "\tDigite um número válido: ";
                        cin >> pokemon_auxiliar.id;
                    }

                    cout << "\tPokebola: ";
                    getline(cin >> ws, pokemon_auxiliar.pokebola);

                    // posição X com validação
                    cout << "\tPosição X (0m - 300m): ";
                    cin >> pokemon_auxiliar.coordenada.x;
                    while(pokemon_auxiliar.coordenada.x > 300 || pokemon_auxiliar.coordenada.x < 0){
                        cout << "Digite uma posição válida (0m - 300m): ";
                        cin >> pokemon_auxiliar.coordenada.x;
                    }

                    // posição Y com validação
                    cout << "\tPosicao Y (0m - 300m): ";
                    cin >> pokemon_auxiliar.coordenada.y;
                    while(pokemon_auxiliar.coordenada.y > 300 || pokemon_auxiliar.coordenada.y < 0){
                        cout << "\tDigite uma posição válida (0m - 300m): ";
                        cin >> pokemon_auxiliar.coordenada.y;
                    }

                    // insere nas árvores
                    tree_insert_id(tree_id, pokemon_auxiliar);
                    tree_insert_name(tree_name, pokemon_auxiliar);
                    tree_insert_type(tree_type, pokemon_auxiliar);
                    tree_insert_pokebola(tree_pokebola, pokemon_auxiliar);
                    
                    // opção de continuar o cadastro
                    cout << "\n Continuar o cadastro? (0-Nao 1-Sim) ";
                    cin >> continuar_cadastro;
                }while(continuar_cadastro == 1);
                break;

            case 2: // opção 2 - imprime em ordem alfabetica pelo nome
                if(tree_name != NULL){
                    ordem_alfabetica(tree_name);
                } else {
                    cout << "\n Nenhum Pokémon cadastrado!" << endl;
                }
                break;

            case 3: //opção 3 - busca pokemon pelo nome
                cout << "\n\tDigite o nome que deseja buscar: ";
                getline(cin >> ws, nome_busca);

                if(search_name(tree_name, nome_busca) != NULL){
                    cout << "\n Encontrado!" << endl;
                } else {
                    cout << "\n Não encontrado!" << endl;
                }
                break;

            case 4: // opção 4 - imprime em ordem alfabetica do tipo
                if(tree_type != NULL){
                    ordem_alfabetica(tree_type);
                } else {
                    cout << "\n Nenhum Pokemon cadastrado!" << endl;
                }
                break;

            case 5: // opção 5 - contar quantos pokemons de determinado tipo tem
                cout << "\n\tDigite o tipo a ser contado: ";
                getline(cin >> ws, tipo_busca);

                contador_tipo = 0;

                search_type(tree_type, tipo_busca, contador_tipo);

                if (contador_tipo == 0){
                    cout << "\n Nenhum Pokémon do tipo " << tipo_busca << " encontrado!" << endl;
                } else if (contador_tipo == 1){
                    cout << "\n 1 Pokémon do tipo " << tipo_busca << " encontrado!" << endl;
                } else {
                    cout << "\n " << contador_tipo << " Pokémons do tipo " << tipo_busca << " encontrado!" << endl;
                }
                break;

            case 6: // opção 6 - remover pokemon por pokebola
                cout << "\n\tDigite a Pokebola a ser removida: ";
                getline(cin >> ws, pokebola_busca);

                // continuar removendo enquanto houver pokemons
                do{
                    pokebola_removida = remove_pokebola(tree_pokebola, tree_id, tree_name, tree_type, pokebola_busca);
                }while(pokebola_removida == 0);

                cout << "\n Pokebola " << pokebola_busca << " removida!" << endl;
                break;

            case 7: // opção 7 - buscar pokemon por pokebola
                cout << "\n\tDigite a Pokebola a ser buscada: ";
                getline(cin >> ws, pokebola_busca);

                existe_pokebola = false;

                search_all_pokebola(tree_pokebola, pokebola_busca, existe_pokebola);

                if(!existe_pokebola){
                    cout << "\n Nenhuma Pokebola do tipo " << pokebola_busca << " encontrada!" << endl;
                }
                break;
            
            case 8: // opção 8 - verificar menor trajeto
                contador_pre = 0;
                contador_pre_final = 0;

                contador_em = 0;
                contador_em_final = 0;

                contador_pos = 0;
                contador_pos_final = 0;

                achou_no_trajeto = false;

                cout << "\n\tDigite o Id do Pokémon a ser buscado: ";
                cin >> id_busca;

                cout << "\n Pré-Ordem: " << endl;
                preOrdem(tree_id, id_busca, contador_pre, contador_pre_final, achou_no_trajeto);
                cout << endl;
                if(achou_no_trajeto){
                    cout << " Distância: " << contador_pre_final << endl;
                } else {
                    cout << " Não encontrado! " << endl;
                }

                cout << "\n Em Ordem: " << endl;
                emOrdem(tree_id, id_busca, contador_em, contador_em_final, achou_no_trajeto);
                cout << endl;
                if(achou_no_trajeto){
                    cout << " Distância: " << contador_em_final << endl;
                } else {
                    cout << " Não encontrado! " << endl;
                }

                cout << "\n Pós-Ordem: " << endl;
                posOrdem(tree_id, id_busca, contador_pos, contador_pos_final, achou_no_trajeto);
                cout << endl;
                if(achou_no_trajeto){
                    cout << " Distância: " << contador_pos_final << endl;
                } else {
                    cout << " Não encontrado! " << endl;
                }

                if(achou_no_trajeto){
                    if (contador_pre_final == contador_em_final && contador_pre_final == contador_pos_final){
                        // os 3
                        cout << "\n Todos os caminhos são iguais. " << endl;
                    } else if (contador_pre_final < contador_em_final){
                        if (contador_pre_final < contador_pos_final){
                            // pre
                            cout << "\n O melhor caminho é Pré-Ordem. " << endl;
                        } else if (contador_pre_final == contador_pos_final){
                            // pre e pos
                            cout << "\n Os melhores caminhos são Pré e Pós-Ordem. " << endl;
                        }
                    } else if (contador_pos_final < contador_pre_final){
                        // pos
                        cout << "\n O melhor caminho é Pós-Ordem. " << endl;
                    } else if (contador_em_final <= contador_pre_final || contador_em_final <= contador_pos_final){
                        if (contador_em_final < contador_pos_final && contador_em_final < contador_pre_final){
                            // em
                            cout << "\n O melhor caminho é Em Ordem. " << endl;
                        } else if (contador_em_final == contador_pos_final && contador_em_final < contador_pre_final){
                            // em e pos
                            cout << "\n Os melhores caminhos são Em e Pós-Ordem. " << endl;
                        } else if (contador_em_final == contador_pre_final && contador_em_final < contador_pos_final){
                            // em e pre
                            cout << "\n Os melhores caminhos são Pré e Em Ordem. " << endl;
                        }
                    }
                }
                break;

            case 9: // opção 9 - verificar pokemons dentrio do raio de 100 metros
                cout << "\n\tDigite a localização X e Y da Pokedex dentro do espaço 300m x 300m: ";
                cin >> pokedex.x >> pokedex.y;
                while(pokedex.x > 300 || pokedex.y > 300){
                    cout << "\n\tDigite uma localização válida: ";
                    cin >> pokedex.x >> pokedex.y;
                }

                contador_raio = 0;
                
                search_distance(tree_name, pokedex.x, pokedex.y, contador_raio);

                if (contador_raio == 0){
                    cout << "\n Nenhum Pokémon dentro do raio. " << endl;
                } else if (contador_raio == 1){
                    cout << "\n 1 Pokémon dentro do raio. " << endl;
                } else {
                    cout << "\n " << contador_raio << " Pokémons dentro do raio. " << endl;
                }
                break;
            
            case 10: // opção 10 - sair do programa?
                cout << "\n Sair do programa? (0-Nao 1-Sim) ";
                cin >> sair_do_programa;
                while(sair_do_programa < 0 || sair_do_programa > 1){
                    cout << "\n Por favor, digite um valor valido! (0-Nao 1-Sim) ";
                    cin >> sair_do_programa;
                }
                break;

            default: // opção default para qualquer número fora das opções possíveis
                cout << "\n A opção escolhida nao é válida, por favor escolha novamente!" << endl;
                sair_do_programa = 0;
                break;

        }
    }while(sair_do_programa == 0);

    cout << "\n\tObrigado por utilizar o nosso cadastro :)\n\t\tFim do programa!\n" << endl;

    // destrói as árvores
    destroy_tree(tree_id);
    destroy_tree(tree_name);
    destroy_tree(tree_type);
    destroy_tree(tree_pokebola);

    return 0;
}