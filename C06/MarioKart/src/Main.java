public class Main {
    public static void main(String[] args) {
        Kart kart1 = new Kart();
        Kart kart2 = new Kart();
        Piloto piloto1 = new Piloto();
        Piloto piloto2 = new Piloto();

        kart1.nome = "Hb20";
        kart2.nome = "Fiat Mille";

        kart1.motor.cilindradas = "400";
        kart1.motor.velocidadeMaxima = 99.5f;
        kart2.motor.cilindradas = "450";
        kart2.motor.velocidadeMaxima = 85.9f;

        piloto1.nome = "Gabriel";
        piloto2.nome = "Eduardo";

        kart1.piloto = piloto1;
        kart2.piloto = piloto2;

        piloto1.soltaSuperPoder();

        kart1.fazerDrift();
        kart1.soltaTurbo();
        kart1.motor.mostraInfo();

        piloto2.soltaSuperPoder();

        kart2.fazerDrift();
        kart2.soltaTurbo();
        kart2.motor.mostraInfo();
    }
}