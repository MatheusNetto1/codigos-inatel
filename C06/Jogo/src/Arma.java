public class Arma {
    String nome;
    int poder;
    int resistencia;
    String descricao;

    void mostraInfoArmas(){
        System.out.println("Arma");
        System.out.println("Nome: " + nome);
        System.out.println("Poder: " + poder);
        System.out.println("Resistência: " + resistencia);
        System.out.println("Descrição: " + descricao);
    }
}
