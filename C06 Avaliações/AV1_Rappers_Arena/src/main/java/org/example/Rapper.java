package org.example;

public class Rapper {

    // variaveis do nome, nota, idade e microfone dos rappers
    String nomeRapper;
    float notaRapper;
    int idadeRapper;
    Microfone microfone;

    // constructor da classe "Rapper" com o "Microfone" em composição
    public Rapper(String nomeRapper, float notaRapper, int idadeRapper, String materialMicrofone) {
        this.nomeRapper = nomeRapper;
        this.notaRapper = notaRapper;
        this.idadeRapper = idadeRapper;
        this.microfone = new Microfone(materialMicrofone);
    }

    // função do tipo void para mostrar as informações dos rappers
    void mostraInfo(){
        System.out.println("\t--------------------");
        System.out.println("\tNome do Rapper: " + this.nomeRapper);
        System.out.println("\tNota do Rapper: " + this.notaRapper);
        System.out.println("\tIdade do Rapper: " + this.idadeRapper);
        System.out.println("\tMaterial do Microfone: " + this.microfone.materialMicrofone);
    }
}
