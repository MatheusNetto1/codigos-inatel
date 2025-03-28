package org.example;

public abstract class Habitante {
    public static int contadorHabitante = 0;

    protected int idHabitante;
    protected String nomeHabitante;
    protected int idadeHabitante;
    protected float energiaHabitante;
    protected Arma arma;

    // construtor da classe Habitante
    public Habitante(String nomeHabitante, int idadeHabitante, float energiaHabitante, Arma novaArma) {
        contadorHabitante++;
        this.idHabitante = contadorHabitante;
        this.nomeHabitante = nomeHabitante;
        this.idadeHabitante = idadeHabitante;
        this.energiaHabitante = energiaHabitante;
        this.arma = novaArma;
    }

    // método atacar
    public void atacar(){
        if (this.arma.isMagicaArma()) {
            this.setEnergiaHabitante(this.getEnergiaHabitante()-20);
        } else {
            this.setEnergiaHabitante(this.getEnergiaHabitante()-10);
        }
        System.out.println(this.getNomeHabitante() + " atacou!");
    }

    // método para mostrar as informações do Habitante
    public void mostraInfo() {
        System.out.println("\tId: " + this.getIdHabitante());
        System.out.println("\tNome: " + this.getNomeHabitante());
        System.out.println("\tIdade: " + this.getIdadeHabitante());
        System.out.println("\tEnergia: " + this.getEnergiaHabitante());
    }

    // método getter para idHabitante
    public int getIdHabitante() {
        return this.idHabitante;
    }

    // método getter para nomeHabitante
    public String getNomeHabitante() {
        return this.nomeHabitante;
    }

    // método getter para idadeHabitante
    public int getIdadeHabitante() {
        return this.idadeHabitante;
    }

    // método getter para energiaHabitante
    public float getEnergiaHabitante() {
        return this.energiaHabitante;
    }

    // método setter para energiaHabitante
    public void setEnergiaHabitante(float energiaHabitante) {
        this.energiaHabitante = energiaHabitante;
    }
}