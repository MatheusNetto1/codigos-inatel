package Exercicio4;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Zumbi zumbi = new Zumbi();
        Zumbi zumbi2 = new Zumbi();
        Scanner entrada = new Scanner(System.in);

        double quantia;

        zumbi.vida = 250f;
        zumbi.nome = "Gabriel";
        zumbi2.vida = 250f;
        zumbi2.nome = "Schuller";

        System.out.println("Vida do zumbi 1: " + zumbi.mostraVida());
        System.out.println("Vida do zumbi 2: " + zumbi2.mostraVida());

        System.out.print("Digite a vida a ser transferida: ");
        quantia = entrada.nextDouble();
        System.out.println();

        zumbi.transfereVida(zumbi, zumbi2, quantia);

        System.out.println("Vida do zumbi 1: " + zumbi.mostraVida());
        System.out.println("Vida do zumbi 2: " + zumbi2.mostraVida());

        entrada.close();
    }
}