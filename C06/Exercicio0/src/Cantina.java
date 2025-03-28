public class Cantina {
    String nome;
    Salgado[] salgados =  new Salgado[3];

    public Cantina(String nome) {

        this.nome = nome;
    }

    void addSalgado(Salgado novoSalgado){
        for(int i = 0; i < salgados.length; i++){
            if(salgados[i] == null){
                salgados[i] = novoSalgado;
                break;
            }
        }
    }

    void mostraInfo(){
        System.out.println(this.nome + " possui os salgados:");
        for(int i =  0; i < salgados.length; i++){
            if(salgados[i] != null){
                System.out.println(salgados[i].nome);
            }
        }
    }
}