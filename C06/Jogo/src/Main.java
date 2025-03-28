public class Main {
    public static void main(String[] args) {
        Personagem personagem1 = new Personagem();
        personagem1.nome = "Richtofen";
        personagem1.vida = 250;

        Arma arma1 = new Arma();
        arma1.nome = "Ray Gun Mark II";
        arma1.poder = 999;
        arma1.resistencia = 500;
        arma1.descricao = "Matadora de Zumbis";

        personagem1.arma1 = arma1;

        arma1.mostraInfoArmas();
        System.out.println();

        personagem1.tomarDano();
        personagem1.mostraInfoPersonagem();
        System.out.println();

        personagem1.usarArmas();
        arma1.mostraInfoArmas();
    }
}