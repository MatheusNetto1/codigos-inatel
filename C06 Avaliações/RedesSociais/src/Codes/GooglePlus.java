package Codes;

public class GooglePlus extends RedeSocial implements VideoConferencia, Compartilhamento {
    public GooglePlus(String senha, int numAmigos) {
        super(senha, numAmigos);
    }

    @Override
    public void postarFoto() {
        System.out.println("Postou foto no GooglePlus!");
    }

    @Override
    public void postarVideo() {
        System.out.println("Postou vídeo no GooglePlus!");
    }

    @Override
    public void postarComentario() {
        System.out.println("Postou comentário no GooglePlus!");
    }

    @Override
    public void curtirPublicacao() {
        super.curtirPublicacao();
        System.out.println(" no GooglePlus!");
    }

    @Override
    public void fazStreaming() {
        System.out.println("Fazendo stream no GooglePlus!");
    }

    @Override
    public void compartilhar() {
        System.out.println("Compartilhou no GooglePlus!");
    }
}
