import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);

        System.out.print("Digite o numero de lanches na primeira hora: ");
        int lanche1 = entrada.nextInt();
        System.out.print("Digite o numero de lanches na segunda hora: ");
        int lanche2 = entrada.nextInt();
        System.out.print("Digite o numero de lanches na terceira hora: ");
        int lanche3 = entrada.nextInt();

        int total = lanche1 + lanche2 + lanche3;
        float media = total/3.0f;

        System.out.println("Total de lanches foi: " + total);
        System.out.println("A media de lanches foi: " + media);

        entrada.close();
    }
}
