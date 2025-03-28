package org.example;

public class Oficial extends Soldado implements Defesa {
    private String patenteOficial;

    // construtor da classe Oficial
    public Oficial(String nomeSoldado, long cpfSoldado, ItemEspecial itemEspecial, String patenteOficial) {
        super(nomeSoldado, cpfSoldado, itemEspecial);
        this.patenteOficial = patenteOficial;
    }

    // método mostraInfo
    public void mostraInfo() {
        super.mostraInfo();
        System.out.println("\tPatente: " + this.getPatenteOficial());
    }

    // método usandoItem
    @Override
    public void usandoItem() {
        System.out.println("------------------------");
        if (getItemEspecial() != null){
            System.out.println("\t" + this.getNomeSoldado() + " utilizando item especial");
        } else {
            System.out.println("\t" + this.getNomeSoldado() + " não tem item especial para utilizar");
        }
    }

    // método defender
    @Override
    public void defender() {
        if (getItemEspecial() != null) {
            System.out.println("\t" + this.getNomeSoldado() + " conseguiu se defender");
        } else {
            System.out.println("\t" + this.getNomeSoldado() + " não conseguiu se defender");
        }
    }

    // getter
    public String getPatenteOficial() {
        return patenteOficial;
    }
}
