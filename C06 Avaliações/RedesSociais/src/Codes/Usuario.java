package Codes;

import Exceptions.MinRedesExc;
import Exceptions.RedeVaziaExc;

import java.util.Set;

public class Usuario {
    private String nomeUsuario;
    private String emailUsuario;
    Set<RedeSocial> redes;

    public Usuario(String nomeUsuario, String emailUsuario, Set<RedeSocial> redes) {
        this.nomeUsuario = nomeUsuario;
        this.emailUsuario = emailUsuario;
        this.redes = redes;
    }

    public void usarRedeSocial() {
        int contadorNumRedes = 0;

        for (RedeSocial rede : redes) {
            if (rede != null) {
                contadorNumRedes++;
            }
        }

        try {
            if (contadorNumRedes < 2) {
                throw new MinRedesExc("Existem menos de 2 redes!");
            }
        } catch (MinRedesExc e) {
            e.printStackTrace();
        }

        for (RedeSocial rede : redes) {
            try {
                if (rede == null) {
                    throw new RedeVaziaExc("NO DATA!");
                } else if (rede instanceof Facebook) {
                    Facebook f = (Facebook) rede;
                    f.curtirPublicacao();
                    f.fazStreaming();
                    f.compartilhar();
                } else if (rede instanceof Instagram) {
                    Instagram i = (Instagram) rede;
                    i.postarFoto();
                    i.postarVideo();
                    i.postarComentario();
                }
            } catch (RedeVaziaExc e) {
                System.out.println(e);
            }
        }
    }
}
