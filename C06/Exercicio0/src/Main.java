import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        Cantina cantina = new Cantina("Cantina");

        System.out.println("Digite os nomes dos salgados novos: ");
        for(int i = 0; i < cantina.salgados.length; i++){
            cantina.addSalgado(new Salgado(entrada.nextLine()));
        }

        cantina.mostraInfo();

        entrada.close();
    }
}