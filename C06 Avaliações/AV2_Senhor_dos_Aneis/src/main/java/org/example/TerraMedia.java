package org.example;

public class TerraMedia {
    private Habitante[] herois;

    // construtor da classe TerraMedia
    public TerraMedia() {
        this.herois = new Habitante[5];
    }

    // método para adicionar um novo Habitante
    public void addHabitante(Habitante novoHabitante){
        for (int i = 0; i < herois.length; i++) {
            if (herois[i] == null) {
                herois[i] = novoHabitante;
                break;
            }
        }
    }

    // método para listar os Habitantes
    public void listarHabitante() {
        for (int i = 0; i < herois.length; i++) {
            if (herois[i] != null){
                // chama os métodos da classe elfo
                if (herois[i] instanceof Elfo) {
                    Elfo elfo = (Elfo) herois[i];
                    elfo.viajar();
                    elfo.atacar();
                    elfo.curar();
                    elfo.mostraInfo();
                }
                // chama os métodos da classe anao
                else if (herois[i] instanceof Anao){
                    Anao anao = (Anao) herois[i];
                    anao.minerar();
                    anao.atacar();
                    anao.mostraInfo();
                }
                // chama os métodos da classe mago
                else if (herois[i] instanceof Mago) {
                    Mago mago = (Mago) herois[i];
                    mago.atacar();
                    mago.lancarFeitico();
                    mago.curar();
                    mago.mostraInfo();
                }
            }
        }
    }
}