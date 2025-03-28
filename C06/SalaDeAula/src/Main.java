import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);

        System.out.print("Digite a quantidade de alunos: ");
        int alunos = entrada.nextInt();

        switch (alunos){
            case 10, 20:
                System.out.println("A sala deve I-16 deve ser utilizada");
            break;
            case 30:
                System.out.println("A sala deve I-22 deve ser utilizada");
            break;
            default:
                System.out.println("Nenhuma sala disponível");
            break;
        }

        entrada.close();
    }
}