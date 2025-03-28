import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        Random rand = new Random();

        int NumGerado, NumAdivinhado;

        NumGerado = rand.nextInt(10) + 1;

        do {
            System.out.print("Adivinhe o número: ");
            NumAdivinhado = entrada.nextInt();

            if(NumAdivinhado > NumGerado) {
                System.out.println("Seu número é maior que o gerado");
            } else if(NumAdivinhado < NumGerado) {
                System.out.println("Seu número é menor que o gerado");
            }
        } while(NumGerado != NumAdivinhado);

        System.out.println("Parabéns, você acertou");

        entrada.close();
    }
}