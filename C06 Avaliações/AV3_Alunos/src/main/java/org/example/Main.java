package org.example;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Arquivo arquivo = new Arquivo();
        Scanner sc = new Scanner(System.in);

        boolean continuarNoMenu = true;
        while(continuarNoMenu) {
            // menu de cadastro
            System.out.println("-----------------------------");
            System.out.println("\t1 - Cadastrar");
            System.out.println("\t2 - Listar");
            System.out.println("\t3 - Listar em ordem crescente da média");
            System.out.println("\t4 - Quantidade de alunos por curso");
            System.out.println("\t5 - Sair");
            int opcao = sc.nextInt();

            switch (opcao) {
                case 1:
                    try {
                        sc.nextLine();
                        System.out.println("\tNome: ");
                        String nomeAluno = sc.nextLine();

                        // entrada da matricula com validacao
                        System.out.println("\tMatricula: ");
                        int matriculaAluno = sc.nextInt();
                        sc.nextLine();
                        if (matriculaAluno <= 0) {
                            throw new InfoInvalidaException("Matrícula inválida!");
                        }

                        // entrada do curso com validacao
                        System.out.println("\tCurso: ");
                        String cursoAluno = sc.nextLine();
                        if (!cursoAluno.equals("Software") && !cursoAluno.equals("Computação") && !cursoAluno.equals("Telecomunicações")) {
                            throw new InfoInvalidaException("Curso inválido!");
                        }

                        System.out.println("\tMédia: ");
                        float mediaAluno = sc.nextFloat();
                        sc.nextLine();

                        Aluno a1 = new Aluno(nomeAluno, matriculaAluno, cursoAluno, mediaAluno);
                        arquivo.escrever(a1);
                        break;

                    } catch (InfoInvalidaException e) {
                        System.out.println(e.getMessage());
                        break;
                    }

                case 2:
                    // listar na ordem do cadastro
                    ArrayList<Aluno> alunos = arquivo.ler();
                    for (int i = 0; i < alunos.size(); i++) {
                        System.out.println("\tNome: " + alunos.get(i).getNomeAluno());
                        System.out.println("\tMatrícula: " + alunos.get(i).getMatriculaAluno());
                        System.out.println("\tCurso: " + alunos.get(i).getCursoAluno());
                        System.out.println("\tMédia: " + alunos.get(i).getMediaAluno());
                    }
                    break;

                case 3:
                    // listar em ordem crescente
                    alunos = arquivo.ler();
                    Collections.sort(alunos);
                    for (int i = 0; i < alunos.size(); i++) {
                        System.out.println("\tNome: " + alunos.get(i).getNomeAluno());
                        System.out.println("\tMatrícula: " + alunos.get(i).getMatriculaAluno());
                        System.out.println("\tCurso: " + alunos.get(i).getCursoAluno());
                        System.out.println("\tMédia: " + alunos.get(i).getMediaAluno());
                    }
                    break;

                case 4:
                    // verifica quantos alunos tem por curso
                    alunos = arquivo.ler();
                    Collections.sort(alunos, Collections.reverseOrder());

                    int contSoftware = 0;
                    int contComputacao = 0;
                    int contTelecom = 0;

                    for (int i = 0; i < alunos.size(); i++) {
                        if (alunos.get(i).getCursoAluno().equals("Software")) {
                            contSoftware++;
                        } else if (alunos.get(i).getCursoAluno().equals("Computação")) {
                            contComputacao++;
                        } else {
                            contTelecom++;
                        }
                    }

                    System.out.println("\tQuantidade de alunos por cada curso: ");
                    System.out.println("\tSoftware: " + contSoftware);
                    System.out.println("\tComputação: " + contComputacao);
                    System.out.println("\tTelecomuicações: " + contTelecom);
                    break;

                case 5:
                    // flag pra continuar no menu
                    continuarNoMenu = false;
                    break;
            }
        }
    }
}