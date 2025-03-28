package org.example;

public class Produto implements Comparable<Produto> {
    private String nomeProduto;
    private double precoProduto;
    private String tipoProduto;

    public Produto(String nomeProduto, double precoProduto, String tipoProduto) {
        this.nomeProduto = nomeProduto;
        this.precoProduto = precoProduto;
        this.tipoProduto = tipoProduto;
    }

    public Produto() {
    }

    public String getNomeProduto() {
        return nomeProduto;
    }

    public void setNomeProduto(String nomeProduto) {
        this.nomeProduto = nomeProduto;
    }

    public double getPrecoProduto() {
        return precoProduto;
    }

    public void setPrecoProduto(double precoProduto) {
        this.precoProduto = precoProduto;
    }

    public String getTipoProduto() {
        return tipoProduto;
    }

    public void setTipoProduto(String tipoProduto) {
        this.tipoProduto = tipoProduto;
    }

    @Override
    public int compareTo(Produto o) {
        if (this.precoProduto < o.precoProduto) {
            return -1;
        } if (this.precoProduto > o.precoProduto) {
            return 1;
        }
        return 0;
    }
}
