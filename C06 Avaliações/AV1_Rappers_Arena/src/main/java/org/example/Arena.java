package org.example;

public class Arena {

    // variaveis do nome, lugar e vetor de rappers da arena
    String nomeArena;
    String lugarArena;
    Rapper[] rappers = new Rapper[5];

    // variaveis auxiliares
    float menor = 999;
    float maior = -999;
    int posicaoMaiorNota;
    int posicaoMenorNota;

    // constructor da classe "Arena"
    public Arena(String nomeArena, String lugarArena) {
        this.nomeArena = nomeArena;
        this.lugarArena = lugarArena;
    }

    // função void para adicionar novos rappers no vetor
    void addRapper(Rapper novoRapper){
        for (int i = 0; i < rappers.length; i++) {
            if (rappers[i] == null) {
                rappers[i] = novoRapper;
                break;
            }
        }
    }

    // função void para exibir as informações
    void mostraInfo(){
        System.out.println("Nome da Arena: " + this.nomeArena);
        System.out.println("Lugar da Arena: " + this.lugarArena);
        for (int i = 0; i < rappers.length; i++) {
            if (rappers[i] != null) {
                rappers[i].mostraInfo();
            }
        }
    }

    // função void para mostrar quais rappers tem o microfone dourado
    void microfoneDou(){
        for (int i = 0; i < rappers.length; i++) {

            // se a posição i do vetor não for nula, e o microfone do rapper nessa posição for dourado então o nome dele será exibido
            if (rappers[i] != null && rappers[i].microfone.materialMicrofone.equals("dourado")) {
                System.out.println(rappers[i].nomeRapper + " tem microfone dourado");
            }
        }
    }

    // função void para mostrar o primeiro e o último colocado do ranking
    void ranking(){
        for (int i = 0; i < rappers.length; i++) {

            // se a posicao do vetor não for nula
            if (rappers[i] != null){

                // se a nota do rapper for menor do que a variavel menor, guarda a posição e ela se torna a nova menor
                if (rappers[i].notaRapper < menor) {
                    posicaoMenorNota = i;
                    menor = rappers[i].notaRapper;
                }

                // se a nota do rapper for maior do que a variavel maior, guarda a posicao e ela se torna a nova menor
                if (rappers[i].notaRapper > maior) {
                    posicaoMaiorNota = i;
                    maior = rappers[i].notaRapper;
                }

                // na primeira iteração o primeiro rapper vai entrar nos dois casos, mas logo os outros vão corrigir
            }
        }

        // mensagens de saída do vencedor/perdedor
        System.out.println("-------------");
        System.out.println("O Rapper vencedor é: " + rappers[posicaoMaiorNota].nomeRapper);
        System.out.println("O Rapper perdedor é: " + rappers[posicaoMenorNota].nomeRapper);
    }
}
