package org.example;

public class Main {
    public static void main(String[] args) {
        // instanciamento da classe TerraMedia
        TerraMedia arda = new TerraMedia();

        // instanciamento dos objetos da classe Arma
        Arma armaElfo = new Arma("Espada", true);
        Arma armaAnao = new Arma("Martelo", false);
        Arma armaMago = new Arma("Cajado", true);

        // instanciamento "auxiliar" dos habitantes
        Elfo elfo = new Elfo("Légolas", 1000, 350f, armaElfo, "Valfenda");
        Anao anao = new Anao("Thorin", 350, 500f, armaAnao, 1.45f, "Montanha Solitária");
        Mago mago = new Mago("Saruman", 2000, 400f, armaMago, "Branco");

        // chama o método addHabitante para os habitantes instancionados
        arda.addHabitante(elfo);
        arda.addHabitante(anao);
        arda.addHabitante(mago);

        // chama o método listarHabitantes
        arda.listarHabitante();
    }
}