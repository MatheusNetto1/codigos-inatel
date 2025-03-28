import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        Cliente cliente = new Cliente("Matheus", 123456789);
        MemoriaUSB novaMemoriaUSB;

        int opcaoPromocao;
        int indexArrayCompra = 0;

        System.out.println("\nBem vindo ao Sistema de Promoção!");

        System.out.println("Promoção 1:");
        System.out.println("Positivo - R$3300,00");
        System.out.println("Pentium Core i3 (2200 Mhz)");
        System.out.println("8 Gb de Memória RAM");
        System.out.println("500 Gb de HD");
        System.out.println("Sistema Operacional Linux Ubuntu  (32 bits)");
        System.out.println("Acompanha Pen-drive de 16 Gb");
        System.out.println("----------------------------");
        System.out.println("Promoção 2:");
        System.out.println("Acer - R$8800");
        System.out.println("Pentium Core i5 (3370 Mhz)");
        System.out.println("16 Gb de Memória RAM");
        System.out.println("1 Tb de HD");
        System.out.println("Sistema Operacional Windows 8 (64 bits)");
        System.out.println("Acompanha Pen-drive de 32 Gb");
        System.out.println("----------------------------");
        System.out.println("Promoção 3:");
        System.out.println("Vaio - R$4800");
        System.out.println("Pentium Core i7 (4500 Mhz)");
        System.out.println("32 Gb de Memória RAM");
        System.out.println("2 Tb de HD");
        System.out.println("Sistema Operacional Windows 10 (64 bits)");
        System.out.println("Acompanha HD Externo 1 Tb");
        System.out.println("----------------------------");
        System.out.println();
        System.out.print("Qual das promoções gostaria de comprar? ");

        opcaoPromocao = entrada.nextInt();
        while (opcaoPromocao != 0) {
            switch (opcaoPromocao) {
                case 0:
                    break;
                case 1:
                    cliente.computadores[indexArrayCompra] = new Computador("Positivo", 3300, "Linux Ubuntu", 32);
                    cliente.computadores[indexArrayCompra].hard[0] = new HardwareBasico("Pentium Core i3", 220);
                    cliente.computadores[indexArrayCompra].hard[1] = new HardwareBasico("Memória Ram", 8);
                    cliente.computadores[indexArrayCompra].hard[2] = new HardwareBasico("HD", 500);
                    novaMemoriaUSB = new MemoriaUSB("Pen-drive", 16);
                    cliente.computadores[indexArrayCompra].addMemoriaUSB(novaMemoriaUSB);
                    break;
                case 2:
                    cliente.computadores[indexArrayCompra] = new Computador("Acer", 8800, "Windows 8", 64);
                    cliente.computadores[indexArrayCompra].hard[0] = new HardwareBasico("Pentium Core i5", 3370);
                    cliente.computadores[indexArrayCompra].hard[1] = new HardwareBasico("Memória Ram", 16);
                    cliente.computadores[indexArrayCompra].hard[2] = new HardwareBasico("HD", 1);
                    novaMemoriaUSB = new MemoriaUSB("Pen-drive", 32);
                    cliente.computadores[indexArrayCompra].addMemoriaUSB(novaMemoriaUSB);
                    break;
                case 3:
                    cliente.computadores[indexArrayCompra] = new Computador("Vaio", 4800, "Windows 10", 64);
                    cliente.computadores[indexArrayCompra].hard[0] = new HardwareBasico("Pentium Core i7", 4500);
                    cliente.computadores[indexArrayCompra].hard[1] = new HardwareBasico("Memória Ram", 32);
                    cliente.computadores[indexArrayCompra].hard[2] = new HardwareBasico("HD", 2);
                    novaMemoriaUSB = new MemoriaUSB("HD Externo", 1);
                    cliente.computadores[indexArrayCompra].addMemoriaUSB(novaMemoriaUSB);
                    break;
            }

            System.out.print("Digite 0 para sair ou (1 - 3) para comprar mais algum PC: ");
            opcaoPromocao = entrada.nextInt();
            indexArrayCompra++;
        }

        for (int i = 0; i < cliente.computadores.length; i++) {
            if (cliente.computadores[i] != null){
                cliente.computadores[i].mostraPCConfig();
            }
        }

        System.out.println("O total da compra foi: R$" + cliente.calculaTotalCompra());
        entrada.close();
    }
}