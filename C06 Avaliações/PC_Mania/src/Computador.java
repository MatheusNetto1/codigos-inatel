public class Computador {
    String marcaComputador;
    float precoComputador;

    HardwareBasico[] hard;
    SistemaOperacional sistemaOperacional;
    MemoriaUSB memoriaUSB;

    public Computador(String marcaComputador, float precoComputador, String nomeSistemaOperacional, int tipoSistema) {
        this.marcaComputador = marcaComputador;
        this.precoComputador = precoComputador;
        this.hard = new HardwareBasico[3];
        this.sistemaOperacional = new SistemaOperacional(nomeSistemaOperacional, tipoSistema);
    }

    void mostraPCConfig(){
        System.out.println("-------CONFIGURAÇÕES DO(s) PC(s)-------");
        System.out.println("Marca: " + this.marcaComputador);
        System.out.println("Preço: R$" + this.precoComputador);
        System.out.println("Hardwares:");
        System.out.println("\t" + this.hard[0].nomeHardwareBasico + " (" + this.hard[0].capacidadeHardwareBasico + " Mhz)");
        System.out.println("\t" + this.hard[1].nomeHardwareBasico + " de " + this.hard[1].capacidadeHardwareBasico + " Gb");
        if (this.hard[0].capacidadeHardwareBasico > 2) {
            System.out.println("\t" + this.hard[2].nomeHardwareBasico + " de " +this.hard[2].capacidadeHardwareBasico + " Gb");
        } else {
            System.out.println("\t" + this.hard[2].nomeHardwareBasico + " de " + this.hard[2].capacidadeHardwareBasico + " Tb");
        }
        System.out.println("OS: " + this.sistemaOperacional.nomeSistemaOperacional + " (" + this.sistemaOperacional.tipoSistemaoperacional + " bits)");
        if(this.memoriaUSB != null){
            if (this.memoriaUSB.capacidadeMemoriaUSB == 1){
                System.out.println("USB: " + this.memoriaUSB.nomeMemoriaUSB + " de " + this.memoriaUSB.capacidadeMemoriaUSB + " Tb");
            }
        }
    }

    void addMemoriaUSB(MemoriaUSB novaMemoriaUSB){
        this.memoriaUSB = new MemoriaUSB(novaMemoriaUSB.nomeMemoriaUSB, novaMemoriaUSB.capacidadeMemoriaUSB);
    }
}
