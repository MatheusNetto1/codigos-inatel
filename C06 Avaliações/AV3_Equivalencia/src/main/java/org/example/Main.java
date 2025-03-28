package org.example;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Arquivo arquivo = new Arquivo();
        Scanner sc = new Scanner(System.in);

        String nomeProduto;
        double precoProduto;
        String tipoProduto;

        boolean continuarNoMenu = true;
        while(continuarNoMenu) {
            System.out.println("-----------------------------");
            System.out.println("\t1 - Cadastrar");
            System.out.println("\t2 - Listar");
            System.out.println("\t3 - Listar em ordem decrescente do preço");
            System.out.println("\t4 - Quantidade de produtos por tipo");
            System.out.println("\t5 - Sair");
            int opcao = sc.nextInt();

            switch (opcao) {
                case 1:
                    try {
                        sc.nextLine();
                        System.out.println("\tNome: ");
                        nomeProduto = sc.nextLine();

                        System.out.println("\tPreço: ");
                        precoProduto = sc.nextDouble();
                        sc.nextLine();
                        if (precoProduto <= 0) {
                            throw new InfoInvalidaException("Preço do produto inválido!");
                        }

                        System.out.println("\tTipo: ");
                        tipoProduto = sc.nextLine();
                        if (!tipoProduto.equals("Comida") && !tipoProduto.equals("Higiene") && !tipoProduto.equals("Decoração")) {
                            throw new InfoInvalidaException("Tipo do produto inválido!");
                        }

                        Produto p1 = new Produto(nomeProduto, precoProduto, tipoProduto);
                        arquivo.escrever(p1);
                        break;

                    } catch (InfoInvalidaException e) {
                        System.out.println(e.getMessage());
                        break;
                    }

                case 2:
                    ArrayList<Produto> produtos = arquivo.ler();
                    for (int i = 0; i < produtos.size(); i++) {
                        System.out.println("\tNome: " + produtos.get(i).getNomeProduto());
                        System.out.println("\tPreço: " + produtos.get(i).getPrecoProduto());
                        System.out.println("\tTipo: " + produtos.get(i).getTipoProduto());
                    }
                    break;

                case 3:
                    produtos = arquivo.ler();
                    Collections.sort(produtos, Collections.reverseOrder());
                    for (int i = 0; i < produtos.size(); i++) {
                        System.out.println("\tNome: " + produtos.get(i).getNomeProduto());
                        System.out.println("\tPreço: " + produtos.get(i).getPrecoProduto());
                        System.out.println("\tTipo: " + produtos.get(i).getTipoProduto());
                    }
                    break;

                case 4:
                    produtos = arquivo.ler();
                    Collections.sort(produtos,Collections.reverseOrder());

                    int contComida = 0;
                    int contHigiene = 0;
                    int contDecoracao = 0;

                    for (int i = 0; i < produtos.size(); i++) {
                        if (produtos.get(i).getTipoProduto().equals("Comida")) {
                            contComida++;
                        } else if (produtos.get(i).getTipoProduto().equals("Higiene")) {
                            contHigiene++;
                        } else {
                            contDecoracao++;
                        }
                    }

                    System.out.println("\tQuantidade de produtos por cada tipo: ");
                    System.out.println("\tComida: " + contComida);
                    System.out.println("\tHigiene: " + contHigiene);
                    System.out.println("\tDecoração: " + contDecoracao);
                    break;

                case 5:
                    continuarNoMenu = false;
                    break;
            }
        }

    }
}