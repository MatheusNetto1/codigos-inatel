public class Kart {
    String nome;
    Piloto piloto;
    Motor motor;

    public Kart(){
        this.motor = new Motor();
    }

    void pular(){
        System.out.println(this.nome + " Pulou!");
    }

    void soltaTurbo(){
        System.out.println(this.nome + " Usou turbo!");
    }

    void fazerDrift(){
        System.out.println(this.nome + " É o DK!!");
    }
}
