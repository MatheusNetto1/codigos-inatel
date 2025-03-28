#include <iostream>
#include <list>

using namespace std;

int main()
{
	//Variaveis de entrada
	int n;                                                          // numero de maquinas por linha
	int a[2][100];                                                  // a[i][j]: tempo de processamento da maquina j da linha i -> a[0,4] = 8
	int t[2][100];                                                  // t[i][j]: tempo pra ir da maquina j da linha i para a outra linha -> t[0,4] = 4
	int e[2];                                                       // e[i]: tempo de entrar na linha i
	int x[2];                                                       // x[i]: tempo para sair da linha i
	int custo_aux_melhor = 0;
	int custo_aux_pior = 0;
	
	//Variaveis que serão calculadas
	int f[2][100];                                                  // menor tempo para levar um chassi desde a entrada até a estacao da linha "i" e maquina "j" -> f[0,4]
	int l[2][100];                                                  // linha cuja estacaoo j-1 eh usada como o caminho mais rapido atraves da estacao da linha "i" e maquina "j" -> dois valores 0 ou 1 
	
	int f_;                                                         // f* -> menor tempo total
	int l_;                                                         // l* -> linha cuja ultima estacao eh usada como o caminho mais rapido atraves de toda a fabrica
	
	// Entrada
	cin >> n;
	
	for(int i = 0; i < 2; i++) {
		cin >> e[i];
	}
	
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		
	for(int i = 0;i < 2; i++)
		for(int j = 0;j < n-1; j++) {
			cin >> t[i][j];
		}	
		
	for(int i = 0; i < 2; i++) {
		cin >> x[i];
	}
	
	// PROGRAMACAO DINAMICA
	// inicializacao
	int custo1, custo2;

	// caso base
	f[0][0] = e[0] + a[0][0];                 //caso base
	f[1][0] = e[1] + a[1][0];                 //case base
	l[0][0] = -1; 
	l[1][0] = -1;
	
	
	// caso geral
	for (int maq = 1;maq < n; maq++)                                                  // A maquina 0 já foi processada no caso base
	{
		for(int linha = 0; linha < 2; linha++)
		{
			// calculo os custos para continuar na linha ou mudar
			// O(n)
			if(linha == 0)
			{
				custo1 = f[0][maq-1] + a[0][maq];                                     //manter na linha 0
				custo2 = f[1][maq-1] + t[1][maq-1] + a[0][maq];                       //trocar de linha 
			}
			else //linha = 1
			{
				custo1 = f[1][maq-1] + a[1][maq];                                     //manter na linha 1
				custo2 = f[0][maq-1] + t[0][maq-1] + a[1][maq];                       //trocar de linha
			}

			// avalio qual eh melhor
			if(custo1 < custo2)                                                       // manter na linha
			{
				f[linha][maq] = custo1;
				l[linha][maq] = linha;
				//custo_aux_melhor += custo1;
			}
			else                                                                      // (cussto2 < custo 1) trocar de linha
			{
				f[linha][maq] = custo2;
				//custo_aux_melhor += custo2;
				if(linha == 0)
					l[linha][maq] = 1;
				else
					l[linha][maq] = 0;
			}
		}	
	}
	
	// calculo para sair da linha de producao
	f[0][n] = f[0][n-1] + x[0];                          //(0,6)
	l[0][n] = 0; 
	f[1][n] = f[1][n-1] + x[1];                          //(1,6)
	l[1][n] = 1;

	// analise do melhor tempo total
	if(f[0][n] < f[1][n])
	{
		f_ = f[0][n];
		l_ = 0;
		custo_aux_melhor = f[0][n];
	}
	else
	{
		f_ = f[1][n];
		l_ = 1;
		custo_aux_melhor = f[1][n];
	}

	// Resposta melhor
	int i = l_;
	
	cout << endl << "Melhor caminho " << endl;
	
	cout << endl;

    cout << "linha " << i << " estacao " << (n - 1) << endl;

    for (int j = n - 1; j > 0; j--){
        i = l[i][j];
        cout << "linha " << i << " estacao " << (j - 1) << endl;
    }
    
    cout << endl;
    
    
    // caso geral para o pior
	for (int maq = 1;maq < n; maq++)                                                  // A maquina 0 já foi processada no caso base
	{
		for(int linha = 0; linha < 2; linha++)
		{
			if(linha == 0)
			{
				custo1 = f[0][maq-1] + a[0][maq];
				custo2 = f[1][maq-1] + t[1][maq-1] + a[0][maq];
			}
			else //linha = 1
			{
				custo1 = f[1][maq-1] + a[1][maq];
				custo2 = f[0][maq-1] + t[0][maq-1] + a[1][maq];
			}

			// avalio qual eh pior
			if(custo1 > custo2)
			{
				f[linha][maq] = custo1;
				l[linha][maq] = linha;
				//custo_aux_pior += custo1;
			}
			else
			{
				f[linha][maq] = custo2;
				//custo_aux_pior += custo2;
				if(linha == 0)
					l[linha][maq] = 1;
				else
					l[linha][maq] = 0;
			}
		}	
	}
	
	
	// calculo para sair da linha de producao
	f[0][n] = f[0][n-1] + x[0];                          //(0,6)
	l[0][n] = 0; 
	f[1][n] = f[1][n-1] + x[1];                          //(1,6)
	l[1][n] = 1;

	// analise do pior tempo total
	if(f[0][n] > f[1][n])
	{
		f_ = f[0][n];
		l_ = 0;
		custo_aux_pior = f[0][n];
	}
	else
	{
		f_ = f[1][n];
		l_ = 1;
		custo_aux_pior = f[1][n];
	}

	// Resposta pior
	i = l_;
	
	cout << endl << "Pior caminho " << endl;
	
	cout << endl;

    cout << "linha " << i << " estacao " << (n - 1) << endl;

    for (int j = n - 1; j > 0; j--){
        i = l[i][j];
        cout << "linha " << i << " estacao " << (j - 1) << endl;
    }
    
    cout << endl;
    
    cout << custo_aux_pior - custo_aux_melhor << endl;
	
	return 0;	
}