package Exercicio4;

public class Zumbi {
    double vida;
    String nome;

    double mostraVida(){
        return this.vida;
    }

    boolean isAlive(Zumbi zumbi){
        if(this.vida > 0){
            return true;
        } else {
            return false;
        }
    }

    void transfereVida(Zumbi zumbiAlvo, Zumbi zumbi, double quantia){
        if(isAlive(zumbiAlvo)){
            zumbiAlvo.vida -= quantia;
            zumbi.vida += quantia;
        }
    }
}
