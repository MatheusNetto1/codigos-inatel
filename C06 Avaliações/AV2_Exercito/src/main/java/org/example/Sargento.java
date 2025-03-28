package org.example;

public class Sargento extends Soldado implements Defesa {
    private String especializacaoSargento;
    private int experienciaCombate;

    // construtor da classe Sargento
    public Sargento(String nomeSoldado, long cpfSoldado, ItemEspecial itemEspecial, String especializacaoSargento, int experienciaCombate) {
        super(nomeSoldado, cpfSoldado, itemEspecial);
        this.especializacaoSargento = especializacaoSargento;
        this.experienciaCombate = experienciaCombate;
    }

    // método mostraInfo
    public void mostraInfo() {
        super.mostraInfo();
        System.out.println("\tEspecialização: " + this.getEspecializacaoSargento());
        System.out.println("\tExperiência: " + this.getExperienciaCombate());
    }

    // método usandoItem
    @Override
    public void usandoItem() {
        System.out.println("------------------------");
        if (getItemEspecial() != null){
            setExperienciaCombate(getExperienciaCombate()+300);
            System.out.println("\t" + this.getNomeSoldado() + " utilizando item especial");
        } else {
            System.out.println("\t" + this.getNomeSoldado() + " não tem item especial para utilizar");
        }
    }

    // método defender
    @Override
    public void defender() {
        if (getExperienciaCombate() > 650) {
            System.out.println("\t" + this.getNomeSoldado() + " conseguiu se defender");
        } else {
            System.out.println("\t" + this.getNomeSoldado() + " não conseguiu se defender");
        }
    }

    // getters e setter

    public String getEspecializacaoSargento() {
        return especializacaoSargento;
    }

    public int getExperienciaCombate() {
        return experienciaCombate;
    }

    public void setExperienciaCombate(int experienciaCombate) {
        this.experienciaCombate = experienciaCombate;
    }
}
