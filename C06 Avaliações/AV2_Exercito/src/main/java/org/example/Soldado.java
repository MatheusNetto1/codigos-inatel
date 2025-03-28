package org.example;

public abstract class Soldado {
    public static int qtdSoldado = 0;

    private String nomeSoldado;
    private long cpfSoldado;
    private ItemEspecial itemEspecial;

    // construtor da classe Soldado
    public Soldado(String nomeSoldado, long cpfSoldado, ItemEspecial itemEspecial) {
        qtdSoldado++;
        this.nomeSoldado = nomeSoldado;
        this.cpfSoldado = cpfSoldado;
        this.itemEspecial = itemEspecial;
    }

    // método mostraInfo
    public void mostraInfo() {
        System.out.println("\tNome: " + this.getNomeSoldado());
        System.out.println("\tCpf: " + this.getCpfSoldado());
    }

    // método abstrato usandoItem
    public abstract void usandoItem();


    // getters

    public String getNomeSoldado() {
        return nomeSoldado;
    }

    public long getCpfSoldado() {
        return cpfSoldado;
    }

    public ItemEspecial getItemEspecial() {
        return itemEspecial;
    }
}
