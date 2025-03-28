public class Banda {
    String nomeBanda;
    String generoBanda;

    Empresario empresario = new Empresario("Jack Master", 00000000);
    Musica[] musicas = new Musica[5];
    Membro[] membros = new Membro[5];

    public Banda(String nomeBanda, String generoBanda) {
        this.nomeBanda = nomeBanda;
        this.generoBanda = generoBanda;
    }

    void mostraInfo(){
        // Banda
        System.out.println("------------------------");
        System.out.println("Banda: " + this.nomeBanda);
        System.out.println("Gênero: " + this.generoBanda);

        // Empresario
        System.out.println("------------------------");
        System.out.println("Empresário: " + this.empresario.nomeEmpresario);
        System.out.println("CNPJ: " + this.empresario.cnpjEmpresario);

        // Membros
        System.out.println("------------------------");
        for (int i = 0; i < membros.length; i++) {
            if (membros[i] != null) {
                System.out.println("Membro " + (i+1) + ": " + this.membros[i].nomeMembro);
                System.out.println("Função: " + this.membros[i].funcaoMembro);
            }
        }

        // Musicas
        System.out.println("------------------------");
        for (int i = 0; i < musicas.length; i++) {
            if (musicas[i] != null) {
                System.out.println("Música " + (i+1) + ": " + this.musicas[i].nomeMusica);
                System.out.println("Duração: " + this.musicas[i].duracaoMusica);
            }
        }
    }

    void addMusicaNova(Musica musicaNova){
        for (int i = 0; i < musicas.length; i++) {
            if (musicas[i] == null){
                musicas[i] = musicaNova;
                break;
            }
        }
    }

    void addMembroNovo(Membro membroNovo){
        for (int i = 0; i < membros.length; i++) {
            if (membros[i] == null){
                membros[i] = membroNovo;
                break;
            }
        }
    }
}