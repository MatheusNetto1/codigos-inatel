package org.example;

public class Arma {
    private String nomeArma;
    private boolean magicaArma;

    // construtor da classe Arma
    public Arma(String nomeArma, boolean magicaArma) {
        this.nomeArma = nomeArma;
        this.magicaArma = magicaArma;
    }

    // método para mostrar as informações da classe Arma
    public void mostraInfo() {
        System.out.println("\tNome da arma: " + this.getNomeArma());
        System.out.print("\tStatus de magia: ");
        if (this.isMagicaArma()) {
            System.out.println("Mágica");
        } else {
            System.out.println("Comum");
        }
        System.out.println();
    }

    // método getter para nomeArma
    public String getNomeArma() {
        return this.nomeArma;
    }

    // método getter para magicaArma
    public boolean isMagicaArma() {
        return this.magicaArma;
    }
}