public class Cliente {
    String nomeCliente;
    long cpfCliente;

    Computador[] computadores = new Computador[3];

    public Cliente(String nomeCliente, long cpfCliente) {
        this.nomeCliente = nomeCliente;
        this.cpfCliente = cpfCliente;
    }

    float calculaTotalCompra(){
        float soma = 0;
        for (int i = 0; i < computadores.length; i++) {
            if (computadores[i] != null) {
                soma += computadores[i].precoComputador;
            }
        }
        return soma;
    }
}
