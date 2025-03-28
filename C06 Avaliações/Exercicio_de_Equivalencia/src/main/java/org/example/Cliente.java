package org.example;

public class Cliente implements Comparable<Cliente>{
    private String nomeCliente;
    private String cpfCliente;
    private String enderecoCliente;
    private int idadeCliente;

    public Cliente(String nomeCliente, String cpfCliente, String enderecoCliente, int idadeCliente) {
        this.nomeCliente = nomeCliente;
        this.cpfCliente = cpfCliente;
        this.enderecoCliente = enderecoCliente;
        this.idadeCliente = idadeCliente;
    }

    public Cliente() {
    }

    public String getNomeCliente() {
        return nomeCliente;
    }

    public void setNomeCliente(String nomeCliente) {
        this.nomeCliente = nomeCliente;
    }

    public String getCpfCliente() {
        return cpfCliente;
    }

    public void setCpfCliente(String cpfCliente) {
        this.cpfCliente = cpfCliente;
    }

    public String getEnderecoCliente() {
        return enderecoCliente;
    }

    public void setEnderecoCliente(String enderecoCliente) {
        this.enderecoCliente = enderecoCliente;
    }

    public int getIdadeCliente() {
        return idadeCliente;
    }

    public void setIdadeCliente(int idadeCliente) {
        this.idadeCliente = idadeCliente;
    }

    @Override
    public int compareTo(Cliente o) {
        return nomeCliente.compareTo(o.nomeCliente);
    }
}
