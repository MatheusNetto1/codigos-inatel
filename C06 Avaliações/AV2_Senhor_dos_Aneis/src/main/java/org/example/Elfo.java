package org.example;

public class Elfo extends Habitante implements Cura {
    private String triboElfo;

    // construtor para a classe Elfo
    public Elfo(String nomeHabitante, int idadeHabitante, float energiaHabitante, Arma novaArma, String triboElfo) {
        super(nomeHabitante, idadeHabitante, energiaHabitante, novaArma);
        this.triboElfo = triboElfo;
    }

    // método viajar
    public void viajar(){
        System.out.println(this.getNomeHabitante() + " está viajando!");
    }

    // método atacar do Elfo
    @Override
    public void atacar() {
        super.atacar();
    }

    // método mostrar informações do Elfo
    @Override
    public void mostraInfo() {
        System.out.println("--------------------------");
        System.out.println("\tElfo");
        super.mostraInfo();
        System.out.println("\tTribo: " + this.getTriboElfo());
        this.arma.mostraInfo();
    }

    // método curar com interface
    @Override
    public void curar() {
        this.setEnergiaHabitante(this.getEnergiaHabitante()*1.15f);
        System.out.println(this.getNomeHabitante() + " foi curado!");
    }

    // método getter para triboElfo
    public String getTriboElfo() {
        return this.triboElfo;
    }
}