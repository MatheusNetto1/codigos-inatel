public class Main {
    public static void main(String[] args) {
        Banda banda = new Banda("SAMURAI", "Rock");

        Membro membro1 = new Membro("Johnny Silverhand", "Vocal");
        Membro membro2 = new Membro("Kerry Eurodyne",  "Guitarra");
        Membro membro3 = new Membro("Danny", "Bateria");
        Membro membro4 = new Membro("Nancy", "Teclado");
        Membro membro5 = new Membro("Henry", "Baixo");

        Musica musica1 = new Musica("Chippin' in", 3.33);
        Musica musica2 = new Musica("Never Fade Away", 3.10);
        Musica musica3 = new Musica("The Ballad Of Buck Ravers", 4.28);
        Musica musica4 = new Musica("A Like Supreme", 3.48);
        Musica musica5 = new Musica("Black Dog", 4.23);

        banda.addMembroNovo(membro1);
        banda.addMembroNovo(membro2);
        banda.addMembroNovo(membro3);
        banda.addMembroNovo(membro4);
        banda.addMembroNovo(membro5);

        banda.addMusicaNova(musica1);
        banda.addMusicaNova(musica2);
        banda.addMusicaNova(musica3);
        banda.addMusicaNova(musica4);
        banda.addMusicaNova(musica5);

        banda.mostraInfo();
    }
}