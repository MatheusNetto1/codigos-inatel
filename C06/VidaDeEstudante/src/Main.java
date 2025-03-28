import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);

        int npa;
        int np3;

        System.out.print("Digite a nota NPA: ");
        npa = entrada.nextInt();

        if(npa >= 60){
            System.out.println("Aprovado");
        } else {
            System.out.println("Ainda tem como");
            System.out.print("Digite a NP3: ");

            np3 = entrada.nextInt();

            if ((np3 + npa) / 2 >= 50){
                System.out.println("Aprovado");
            } else {
                System.out.println("Reprovou");
            }

            entrada.close();
        }
    }
}