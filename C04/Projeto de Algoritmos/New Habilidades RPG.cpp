#include<iostream>
#include <locale.h> 
#include<string>
#include <cstdlib>

using namespace std;

string atributos_base[3] = {"Mental", "Físico", "Espiritual"};

typedef struct habilidade {
	int codigo;
	string descricao;
	int atributo_base;
	int modificador;
} Habilidade;

struct Node{
    Habilidade info;
    Node *esquerda;
    Node *direita;
};

void insere_habilidade(Node *&raiz, Habilidade h){

    if(raiz == NULL){
        raiz = new Node;
        raiz->info = h;
        raiz->esquerda = NULL;
        raiz->direita = NULL;
    } else {
        if(h.codigo < raiz->info.codigo){
            insere_habilidade(raiz->esquerda, h);
        } else {
            insere_habilidade(raiz->direita, h);
        }
    }
}

void exibe_info(Habilidade info){
    cout << "Código: " << info.codigo << endl;
    cout << "Descrição: " << info.descricao << endl;
    cout << "Atributo base: " << info.atributo_base << endl;
    cout << "Modificador: " << info.modificador << endl;
}

void lista_em_ordem(Node *raiz){
    if(raiz->esquerda != NULL){
        lista_em_ordem(raiz->esquerda);
    }

    exibe_info(raiz->info);

    if(raiz->direita != NULL){
        lista_em_ordem(raiz->direita);
    }
}

void limpa_arvore(Node *&raiz){
    if(raiz->esquerda != NULL){
        limpa_arvore(raiz->esquerda);
    }

    if(raiz->direita != NULL){
        limpa_arvore(raiz->direita);
    }

    delete raiz;
    raiz = NULL;
}

Node *encontra_redir_menor(Node *&raiz){
    Node * t = raiz;

    if(t->esquerda == NULL){
        raiz = raiz->direita;
        return t;
    } else {
        return encontra_redir_menor(raiz->esquerda);
    }
}

int remove_habilidade(Node *&raiz, int codigo_habilidade){
    if(raiz == NULL){
        return 1;
    }
    Node *p;
    if(raiz->info.codigo == codigo_habilidade){
        p = raiz;
        if(raiz->esquerda == NULL){
            raiz = raiz->direita;
        } else {
            if(raiz->direita == NULL){
                raiz = raiz->esquerda;
            } else {
                p = encontra_redir_menor(raiz->direita);
                raiz->info = p->info;
            }
        }

        delete p;
        p = NULL;
        return 0;
    } else {
        if(codigo_habilidade < raiz->info.codigo){
            return remove_habilidade(raiz->esquerda, codigo_habilidade);
        } else {
            return remove_habilidade(raiz->direita, codigo_habilidade);
        }
    }
}

Habilidade *busca_habilidade(Node *raiz, int codigo_habilidade){
    if(raiz == NULL){
        return NULL;
    }
    if(raiz->info.codigo == codigo_habilidade){
        return &(raiz->info);
    }
    if(codigo_habilidade < raiz->info.codigo){
        return busca_habilidade(raiz->esquerda, codigo_habilidade);
    } else {
        return busca_habilidade(raiz->direita, codigo_habilidade);
    }
}

typedef struct desafio{
	int dificuldade;
	int atributo_base;	
} Desafio;

Desafio gerar_desafio(){
	Desafio d;
	d.dificuldade = rand() % 30;
	d.atributo_base = rand() % 3;
	return d;
}

int rolar_d20(){
	return rand() % 20;
}

int main(){
	setlocale(LC_ALL,"");
	
	cout<<"Bem vindo ao sistema de habilidades.";
	
	int op=4;

    Node *raiz = NULL;
	
	do{	
		cout<<"\n\t\tMenu\n\t1> Cadastrar nova habilidade\n\t2> Testar habilidades\n\n\t3> Sair\n";
		
		
	
		do{	
			cout<<"Entre com a opção desejada: ";
			cin >> op;
			if(op != 1 && op != 2 && op != 3)
				cout<<"Opção inválida!"<<endl;	
		} while(op != 1 && op != 2 && op != 3);
		
		if(op == 1){
			// ----Cadastrar habilidade----
			cout<<"\n\tCadastro de habilidade"<<endl;
			//Solicitar dados da habilidade
            Habilidade h;
            cout << "Insira o codigo da habilidade: ";
            cin >> h.codigo;

            cout << "Insira a descricao da habilidade: ";
            getline(cin >> ws, h.descricao);

            cout << "Informe o atributo base (1> Mental, 2> Físico, 3> Espiritual): ";
            cin >> h.atributo_base;

            cout << "Informe o modificador: ";
			cin >> h.modificador;
			
			// Alocar memória dinâmicamente
			
			// Adicionar na estrutura de dados
			
		} else if(op ==2){
			cout<<"\n\tTeste de habilidade"<<endl;
			// -----Testar habilidade-----
			// Gerar desafio
			Desafio d = gerar_desafio();
			cout<<"Desafio entrentado: "<<atributos_base[d.atributo_base]<<endl;
			cout<<d.dificuldade<<endl;
			
			// Escolher habilidade			
			int habilidade;

            bool hvalido = true;
			Habilidade *resultado = NULL;
            do{
                cout<<"Escolha a sua habilidade: ";			
                cin>>habilidade;
                
                // Buscar habilidade na estrutura de dados
                resultado = busca_habilidade(raiz, habilidade);

                if(resultado == NULL){
                    cout << "Habilidade nao existe!\nInsira uma habilidade valida.\n";
                    hvalido = false;
                } else {
                    if(resultado->atributo_base != d.atributo_base){
                        cout << "Habilidade nao existe!\nInsira uma habilidade valida.\n";
                        hvalido = false;
                    } else {
                        hvalido = true;
                    }
                }
            }while(hvalido == false);
			
			int valor_aleatorio = rolar_d20();
			cout << "resultado: " << valor_aleatorio << " + ";

            cout << resultado->modificador << endl;

            if(valor_aleatorio + resultado->modificador >= d.dificuldade){
                cout << "Você superou esse desafio!" << endl;										
            } else {
                cout << "Você fracassou nesse desafio..." << endl;
            }
		}
		
			
	}while(op != 3);
	
	cout << "Obrigado por utilizar o sistema de habilidades!" << endl;
	
	return 0;
} 