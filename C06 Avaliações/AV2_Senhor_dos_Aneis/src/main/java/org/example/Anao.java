package org.example;

public class Anao extends Habitante implements Mineracao {
    private float alturaAnao;
    private String reinoAnao;

    // construtor da classe Anao
    public Anao(String nomeHabitante, int idadeHabitante, float energiaHabitante, Arma novaArma, float alturaAnao, String reinoAnao) {
        super(nomeHabitante, idadeHabitante, energiaHabitante, novaArma);
        this.alturaAnao = alturaAnao;
        this.reinoAnao = reinoAnao;
    }

    // método atacar do Anao
    @Override
    public void atacar() {
        super.atacar();
    }

    // método mostrar informações do Anao
    @Override
    public void mostraInfo() {
        System.out.println("\tAnão");
        super.mostraInfo();
        System.out.println("\tAltura: " + this.getAlturaAnao());
        System.out.println("\tReino: " + this.getReinoAnao());
        this.arma.mostraInfo();
    }

    // método minerar com interface
    @Override
    public void minerar() {
        System.out.println(this.getNomeHabitante() + " está minerando!");
    }

    // método getter  para alturaAnao
    public float getAlturaAnao() {
        return this.alturaAnao;
    }

    // método getter para reinoAnao
    public String getReinoAnao() {
        return this.reinoAnao;
    }
}