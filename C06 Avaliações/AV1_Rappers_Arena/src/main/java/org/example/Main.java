package org.example;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        // declaração do teclado e da arena
        Scanner sc = new Scanner(System.in);
        Arena arena = new Arena("Arena1", "Lugar da Arena1");

        // variaveis auxiliares para as opções do menu
        int opcaoMenu;
        int opcaoSaida = 1;
        int opcaoCadastro = 1;

        // variáveis auxiliares para cadastro do novo rapper
        String novoNomeRapper;
        float novaNotaRapper;
        int novaIdadeRapper;
        String novoMicrofone;

        // estrutura de repetição para o menu
        while (opcaoSaida == 1) {

            // mensagens iniciais do menu
            System.out.println("\n\tBem vindo ao menu da Arena!");
            System.out.println("\nEscolha entre as opções abaixo:");
            System.out.println("1 Adicionar um novo Rapper");
            System.out.println("2 Mostrar informações da Arena e de seus Rappers");
            System.out.println("3 Mostrar qual Rapper tem microfone dourado");
            System.out.println("4 Mostrar qual Rapper ganhou a batalha e qual ficou em último lugar");

            // entrada da opção escolhida do menu
            System.out.print("Opção: ");
            opcaoMenu = sc.nextInt();
            sc.nextLine();

            // estrutura de decisão para as escolhas do menu
            switch (opcaoMenu) {
                case 1:

                    // estrutura de repetição para o cadastro
                    while (opcaoCadastro == 1){

                        // entrada do nome
                        System.out.print("\tNome: ");
                        novoNomeRapper = sc.nextLine();

                        // entrada da nota
                        System.out.print("\tNota: ");
                        novaNotaRapper = sc.nextFloat();

                        // entrada da idade
                        System.out.print("\tIdade: ");
                        novaIdadeRapper = sc.nextInt();
                        sc.nextLine();

                        // entrada do material do microfone
                        System.out.print("\tMaterial do microfone: ");
                        novoMicrofone = sc.nextLine();

                        // cria uma instância do novo rapper e envia ela pra função de adicionar rappers
                        Rapper novoRapper = new Rapper(novoNomeRapper, novaNotaRapper, novaIdadeRapper, novoMicrofone);
                        arena.addRapper(novoRapper);

                        // estrutura para decidir permanecer ou não no cadastro com validação de emntrada
                        System.out.print("Gostaria de continuar o cadastro? (1 - sim | 0 - não) ");
                        do {
                            opcaoCadastro = sc.nextInt();
                        } while (opcaoCadastro != 0 && opcaoCadastro !=1);
                        sc.nextLine();
                    }
                    break;
                case 2:

                    // mostra info da arena e dos rappers
                    arena.mostraInfo();
                    break;
                case 3:

                    // mostra quem tem o microfone dourado
                    arena.microfoneDou();
                    break;
                case 4:

                    // mostra quem venceu e quem perdeu
                    arena.ranking();
                    break;
                default:
                    break;
            }

            // estrutura para decidir permanecer ou não no menu com validação de emntrada
            System.out.print("Gostaria de voltar ao menu? (1 - sim | 0 - não) ");
            do {
                opcaoSaida = sc.nextInt();
            } while (opcaoSaida != 0 && opcaoSaida != 1);
            sc.nextLine();
        }

        // encerra a entrada
        sc.close();
    }
}