#include <iostream>
#include <locale.h> 
#include <string>
#include <cstdlib>
#include <list>

using namespace std;

/*
	Considere o tipo abstrato de dados a seguir.
	Ele representa uma habilidade que pode ser usada por um personagem em um jogo de RPG.
	Habilidades são usadas para superar desafios no jogo. 
	Desafios podem ser desafios mentais, físicos ou espirituais.
	Cada desafio tem um nível de dificuldade e para conseguir superá-lo, o personagem pode usar uma de suas habilidades.
	Quando a habilidade é usada, um valor aleatório de 1 a 20 é gerado e somado ao modificador da habilidade.
	Se o valor resultante for maior que o nível de dificuldade do desafio, o personagem consegue superá-lo.
	
	Cada habilidade tem um código único e uma descrição.
	Além disso é definido um atributo base (1: Mente, 2: Corpo ou 3: Espírito).
	Por fim é definido um modificador.
*/

string atributos_base[3] = {"Mental", "Físico", "Espiritual"};

typedef struct habilidade {
	int codigo;
	string descricao;
	int atributo_base;
	int modificador;
} Habilidade;

/*
	A função gera_desafio cria um desafio de um tipo aleatório e com um valor de dificuldade de 0 a 30.
*/

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

/*
	A função rolar_d20 cria um valor aleatório de 0 a 20 para ser somado ao modificador quando uma habilidade for usada.
*/

int rolar_d20(){
	return rand() % 20;
}

/*
	Crie um sistema com as seguintes opções para o usuário: 1> Cadastrar nova habilidade e 2> Testar habilidades.
	
	Na opção 1, solicite que o usuário informe os dados sobre a habilidade a ser cadastrada. 
	Aloque memória de forma dinâmica para cada uma dessas habilidades e adicione em uma estrutura de dados.
	
	Na opção 2, gere um desafio aleatório, usando a função gerar_desafio e apresente o tipo do desafio para o usuário.
	Em seguida, solicite que o usuário informe o código da habilidade a ser testada.
	Busque a habilidade na estrutura de dados.
	Por fim, verifique se a habilidade é do mesmo tipo de atributo base que o desafio.
	Se não for, apresente a mensagem "Essa habilidade não pode ser usada para esse desafio." e solicite para o usuário entrar com outra habilidade.
	Se for, gere um valor aleatório usando a função rolar_d20 e some com o modificador da habilidade.
	Se o valor resultante for maior ou igual ao valor da dificuldade do desafio, apresente a mensagem "Você superou esse desafio!".
	Senão, mostre a mensagem "Você fracassou nesse desafio...".
*/

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	cout << "Bem vindo ao sistema de habilidades.";
	
	int op = 4;

	bool habilidade_existe = false;						// variavel auxiliar para verificar se a habilidade existe
	bool habilidade_valida = false;						// variavel auxiliar para verificar se a habilidade é válida

	list <Habilidade> lista_habilidades;				// declaração da lista de tipo "habilidade"
	list <Habilidade> :: iterator p;					// declaração do iterador p para varrer a lista

	p = lista_habilidades.begin();						// define p como o início da lista

	Habilidade aux;										// declaração da struct auxiliar
	
	do{	
		cout << "\n\t\tMenu\n\t1> Cadastrar nova habilidade\n\t2> Testar habilidades\n\n\t3> Sair\n";
		
		do{	
			cout << "Entre com a opção desejada: ";
			cin >> op;

			if(op != 1 && op != 2 && op != 3){
				cout << "Opção inválida!" << endl;
			}
		} while(op != 1 && op != 2 && op != 3);
		
		if(op == 1){
			// ----Cadastrar habilidade----
			cout << "\n\tCadastro de habilidade" << endl;
			
            cout << "\nInforme o código: ";
			cin >> aux.codigo;																	// entrada do código da habilidade na struct auxiliar

			cout << "Informe a descrição: ";
			getline(cin >> ws, aux.descricao);													// entrada da descrição da habilidade na struct auxiliar

			cout << "Informe o atributo base (1> Mental, 2> Físico, 3> Espiritual): ";
			cin >> aux.atributo_base;															// entrada do atributo base na struct auxiliar
			while(aux.atributo_base < 1 || aux.atributo_base > 3){								// estrutura para validação do atributo base
				cout << "Opção inválida!" << endl;
				cin >> aux.atributo_base;														// entrada do atributo base na struct auxiliar caso não seja validado anteriormente
			}

			cout << "Informe o modificador: ";
			cin >> aux.modificador;																// entrada do modificador na struct auxiliar

			lista_habilidades.push_back(aux);													// empurra a struct auxiliar para dentro da lista
		}

		else if(op ==2){
			// -----Testar habilidade-----
			cout << "\n\tTeste de habilidade" << endl;
			
			// Gerar desafio
			Desafio d = gerar_desafio();
			cout << "Desafio entrentado: " << atributos_base[d.atributo_base] << endl;
			
			// Escolher habilidade
			int habilidade;

			// Rolar d20
			int valor_aleatorio = rolar_d20();

			do{																										// estrutura para validar a entrada da habilidade
				cout << "Escolha a sua habilidade: ";			
				cin >> habilidade;

				// Buscar habilidade na estrutura de dados
				for(p = lista_habilidades.begin(); p != lista_habilidades.end(); ++p){                              // estrutura de repetição para varrer a lista
					if(p->codigo == habilidade){																	// verifica se a habilidade existe
						habilidade_existe = true;																	// auxiliar caso exista
					
						cout << "\ncodigo e habilidade: " << p->codigo << " " << habilidade << endl;
						cout << "atributo base e desafio: " << p->atributo_base << " " << d.atributo_base+1 << endl;
						cout << "modificador + d20 e dificuldade: " << valor_aleatorio + p->modificador << " " << d.dificuldade << "\n" << endl;

						// Verificar o atributo base da habilidade
						if(p->atributo_base == d.atributo_base+1){													// verifica se o atributo da habilidade é o mesmo do desafio
							habilidade_valida = true;																// auxiliar caso for a mesma

							// Verificar se superou o desafio
							// Somar com o modificador da habilidade
							if(valor_aleatorio + p->modificador >= d.dificuldade){									// verifica se superou ou não
								cout << "Você superou esse desafio!" << endl;										
							} else {																				// caso não tenha superado
								cout << "Você fracassou nesse desafio..." << endl;
							}
						} else {																					//caso o atributo seja diferente
							cout << "Essa habilidade não pode ser usada para esse desafio." << endl;
						}
					}
				}

				if(!habilidade_existe)																				// caso a habilidade não exista
					cout << "Habilidade não cadastrada!" << endl;
			}while(!habilidade_existe);
		}

	}while(op != 3);

	// estrutura para limpar a lista
	while(!lista_habilidades.empty()){
		lista_habilidades.pop_front();
	}
	
	cout << "Obrigado por utilizar o sistema de habilidades!" << endl;
	
	return 0;
}

/*
>>>>>>>>>>>>>>>Exemplo de uso:

Bem vindo ao sistema de habilidades.
                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a opção desejada: 5
Opção inválida!
Entre com a opção desejada: 1

	   	Cadastro de Habilidade
Informe o código: 1
Informe a descrição: Chamas do patrono
Informe o atributo base (1>Mental, 2>Físico, 3>Espiritual): 3
Informe o modificador: 5

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a opção desejada: 1

	   	Cadastro de Habilidade
Informe o código: 2
Informe a descrição: Escalada
Informe o atributo base (1>Mental, 2>Físico, 3>Espiritual): 2
Informe o modificador: 3

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a opção desejada: 1

	   	Cadastro de Habilidade
Informe o código: 3
Informe a descrição: Conhecimento de história
Informe o atributo base (1>Mental, 2>Físico, 3>Espiritual): 1
Informe o modificador: 5

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a opção desejada: 2
		
		Teste de habilidade
Desafio entrentado: Espiritual
Escolha a sua habilidade: 1
Você superou esse desafio!

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a opção desejada: 2
		
		Teste de habilidade
Desafio entrentado: Físico
Escolha a sua habilidade: 1
Essa habilidade não pode ser usada para esse desafio.
Escolha a sua habilidade: 2
Você superou esse desafio!

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a opção desejada: 2
		
		Teste de habilidade
Desafio entrentado: Mental
Escolha a sua habilidade: 3
Você fracassou nesse desafio...

                Menu
        1> Cadastrar nova habilidade
        2> Testar habilidades

        3> Sair
Entre com a opção desejada: 3
Obrigado por utilizar o sistema de habilidades!

*/