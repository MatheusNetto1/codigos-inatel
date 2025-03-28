public class Personagem {
    String nome;
    int pontos;
    int vida;

    Arma arma1;

    void usarArmas(){
        arma1.resistencia -= 2;
    }

    void tomarDano(){
        vida -= 5;
    }

    void mostraInfoPersonagem(){
        System.out.println("Personagem");
        System.out.println("Nome: " + nome);
        System.out.println("Vida: " + vida);
    }
}
