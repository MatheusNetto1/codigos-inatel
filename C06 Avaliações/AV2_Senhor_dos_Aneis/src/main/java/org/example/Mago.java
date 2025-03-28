package org.example;

public class Mago extends Habitante implements Feitico, Cura {
    private String corMago;

    // construtor para a classe Mago
    public Mago(String nomeHabitante, int idadeHabitante, float energiaHabitante, Arma novaArma, String corMago) {
        super(nomeHabitante, idadeHabitante, energiaHabitante, novaArma);
        this.corMago = corMago;
    }

    // método atacar
    @Override
    public void atacar() {
        super.atacar();
    }

    // método mostrar informações do Mago
    @Override
    public void mostraInfo() {
        System.out.println("\tMago");
        super.mostraInfo();
        System.out.println("\tCor do Mago: " + this.getCorMago());
        this.arma.mostraInfo();
    }

    // método lançar feitiço com interface
    @Override
    public void lancarFeitico() {
        this.setEnergiaHabitante(this.getEnergiaHabitante()*0.9f);
        System.out.println(this.getNomeHabitante() + " lançou um feitiço!");
    }

    // método curar com interface
    @Override
    public void curar() {
        this.setEnergiaHabitante(this.getEnergiaHabitante()*1.15f);
        System.out.println(this.getNomeHabitante() + " foi curado!");
    }

    // método getter para corMago;
    public String getCorMago() {
        return this.corMago;
    }
}