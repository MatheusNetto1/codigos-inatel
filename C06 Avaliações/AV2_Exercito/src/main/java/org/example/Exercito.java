package org.example;

public class Exercito {
    private String nomeExercito;
    private Soldado[] soldados;

    // construtor da classe Exercito
    public Exercito(String nomeExercito) {
        this.nomeExercito = nomeExercito;
        this.soldados = new Soldado[5];
    }

    // método addSoldado
    public void addSoldado(Soldado novoSoldado) {
        for (int i = 0; i < soldados.length; i++) {
            if (soldados[i] == null) {
                soldados[i] = novoSoldado;
                break;
            }
        }
    }

    // método para mostrar as informações do exército
    public void mostraInfo() {
        System.out.println("\nExército: " + this.getNomeExercito());
        for (int i = 0; i < soldados.length; i++) {
            if (soldados[i] != null) {

                // chama o mostraInfo do sargento
                if (soldados[i] instanceof Sargento) {
                    Sargento sarg = (Sargento) soldados[i];
                    sarg.usandoItem();
                    sarg.defender();
                    sarg.mostraInfo();
                }

                // chama o mostraInfo do oficial
                else if (soldados[i] instanceof Oficial) {
                    Oficial ofic = (Oficial) soldados[i];
                    ofic.usandoItem();
                    ofic.defender();
                    ofic.mostraInfo();
                }

                // chama o mostraInfo do medico
                else if (soldados[i] instanceof Medico) {
                    Medico med = (Medico) soldados[i];
                    med.usandoItem();
                    med.curar();
                    med.mostraInfo();
                }
            }
        }
    }

    // getter
    public String getNomeExercito() {
        return nomeExercito;
    }
}
