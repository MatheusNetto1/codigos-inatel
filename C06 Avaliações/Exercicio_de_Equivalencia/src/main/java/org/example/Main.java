package org.example;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Arquivo arquivo = new Arquivo();
        Scanner entrada = new Scanner(System.in);

        String nomeCliente;
        String cpfCliente;
        String enderecoCliente;
        int idadeCliente;

        boolean continuarNoMenu = true;
        while(continuarNoMenu) {
            System.out.println("-----------------------------");
            System.out.println("\t1 - Cadastrar");
            System.out.println("\t2 - Listar");
            System.out.println("\t3 - Ordenar por ordem alfabética");
            System.out.println("\t4 - Ordenar por ordem alfabética decrescente");
            System.out.println("\t5 - Sair");
            int opcao = entrada.nextInt();

            switch (opcao) {
                case 1:
                    entrada.nextLine();
                    System.out.println("\tNome: ");
                    nomeCliente = entrada.nextLine();
                    System.out.println("\tCpf: ");
                    cpfCliente = entrada.nextLine();
                    System.out.println("\tEndereço: ");
                    enderecoCliente = entrada.nextLine();
                    System.out.println("\tIdade: ");
                    idadeCliente = entrada.nextInt();

                    Cliente c1 = new Cliente(nomeCliente, cpfCliente, enderecoCliente, idadeCliente);
                    arquivo.escrever(c1);
                    break;

                case 2:
                    ArrayList<Cliente> clientes = arquivo.ler();
                    for (int i = 0; i < clientes.size(); i++) {
                        System.out.println("\tNome: " + clientes.get(i).getNomeCliente());
                        System.out.println("\tCpf: " + clientes.get(i).getCpfCliente());
                        System.out.println("\tEndereço: " + clientes.get(i).getEnderecoCliente());
                        System.out.println("\tIdade: " + clientes.get(i).getIdadeCliente());
                    }
                    break;

                case 3:
                    clientes = arquivo.ler();
                    Collections.sort(clientes);
                    for (int i = 0; i < clientes.size(); i++) {
                        System.out.println("\tNome: " + clientes.get(i).getNomeCliente());
                        System.out.println("\tCpf: " + clientes.get(i).getCpfCliente());
                        System.out.println("\tEndereço: " + clientes.get(i).getEnderecoCliente());
                        System.out.println("\tIdade: " + clientes.get(i).getIdadeCliente());
                    }
                    break;

                case 4:
                    clientes = arquivo.ler();
                    Collections.sort(clientes,Collections.reverseOrder());
                    for (int i = 0; i < clientes.size(); i++) {
                        System.out.println("\tNome: " + clientes.get(i).getNomeCliente());
                        System.out.println("\tCpf: " + clientes.get(i).getCpfCliente());
                        System.out.println("\tEndereço: " + clientes.get(i).getEnderecoCliente());
                        System.out.println("\tIdade: " + clientes.get(i).getIdadeCliente());
                    }
                    break;

                case 5:
                    continuarNoMenu = false;
                    break;
            }
        }
    }
}