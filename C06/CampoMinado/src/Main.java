import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        boolean[][] campoMinado = new boolean[2][2];

        Random rand = new Random();
        Scanner entrada = new Scanner(System.in);

        int posicaoMinaX = rand.nextInt(2);
        int posicaoMinaY = rand.nextInt(2);
        campoMinado[posicaoMinaX][posicaoMinaY] = true;

        int posicaoXJogador, posicaoYJogador;

        int contador = 0;
        do {
            System.out.print("Digite uma posicao X: ");
            posicaoXJogador = entrada.nextInt();

            System.out.print("Digite uma posicao Y: ");
            posicaoYJogador = entrada.nextInt();

            if(campoMinado[posicaoXJogador][posicaoYJogador]){
                System.out.println("EXPLODIU!!");
                contador = 0;
            }else{
                System.out.println("Safe!");
                contador++;
            }
        } while (contador < 3);
    }
}