package org.example;

public class Main {
    public static void main(String[] args) {
        // instanciamento da classe exército
        Exercito exer = new Exercito("Legião");

        // instanciamento dos itens especiais
        ItemEspecial itemSarg = new ItemEspecial("Defesa Superior");
        ItemEspecial itemOfic = new ItemEspecial("Defesa");
        ItemEspecial itemMed = new ItemEspecial("Cura Superior");

        // instanciamento dos soldados
        Sargento s = new Sargento("Soldado1", 111111, itemSarg, "Infantaria", 600);
        Oficial o = new Oficial("Soldado2", 222222, itemOfic, "Centurião");
        Medico m = new Medico("Soldado3", 333333, itemMed, 15, 900);

        // chama o método para adicionar os soldados
        exer.addSoldado(s);
        exer.addSoldado(o);
        exer.addSoldado(m);

        // método para mostrar as informações dos soldados
        exer.mostraInfo();

        // quantidade de soldados registrados
        System.out.println("\n" + Soldado.qtdSoldado + " soldado(s) registrados");
    }
}