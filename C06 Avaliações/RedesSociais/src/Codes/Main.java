package Codes;

import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) {

        Facebook facebook = new Facebook("senha1", 10);
        Instagram instagram = new Instagram("senha2", 20);
        Set<RedeSocial> redes = new HashSet<>();

        redes.add(facebook);
        redes.add(instagram);

        Usuario user = new Usuario("User", "user@gmail.com", redes);

        user.usarRedeSocial();
    }
}