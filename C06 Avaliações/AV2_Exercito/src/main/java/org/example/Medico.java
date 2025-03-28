package org.example;

public class Medico extends Soldado implements Curar {
    private int anosExperiencia;
    private int capacidadeEmergencia;

    // construtor da classe Medico
    public Medico(String nomeSoldado, long cpfSoldado, ItemEspecial itemEspecial, int anosExperiencia, int capacidadeEmergencia) {
        super(nomeSoldado, cpfSoldado, itemEspecial);
        this.anosExperiencia = anosExperiencia;
        this.capacidadeEmergencia = capacidadeEmergencia;
    }

    // método mostraInfo
    public void mostraInfo() {
        super.mostraInfo();
        System.out.println("\tAnos de Experiencia: " + this.getAnosExperiencia());
        System.out.println("\tCapacidade: " + this.getCapacidadeEmergencia());
    }

    // método usandoItem
    @Override
    public void usandoItem() {
        System.out.println("------------------------");
        if (this.getItemEspecial() != null){
            setCapacidadeEmergencia(getCapacidadeEmergencia()+100);
            System.out.println("\t" + this.getNomeSoldado() + " utilizando item especial");
        } else {
            System.out.println("\t" + this.getNomeSoldado() + " não tem item especial para utilizar");
        }
    }

    // método curar
    @Override
    public void curar() {
        if (getCapacidadeEmergencia() > 920) {
            System.out.println("\t" + this.getNomeSoldado() + " conseguiu curar outro indivíduo");
        } else {
            System.out.println("\t" + this.getNomeSoldado() + " não conseguiu curar outro indivíduo");
        }
    }

    // getters e setter

    public int getAnosExperiencia() {
        return anosExperiencia;
    }

    public int getCapacidadeEmergencia() {
        return capacidadeEmergencia;
    }

    public void setCapacidadeEmergencia(int capacidadeEmergencia) {
        this.capacidadeEmergencia = capacidadeEmergencia;
    }
}
