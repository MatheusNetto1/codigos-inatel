package org.example;

public class Aluno implements Comparable<Aluno>{
    private String nomeAluno;
    private int matriculaAluno;
    private String cursoAluno;
    private float mediaAluno;

    public Aluno(String nomeAluno, int matriculaAluno, String cursoAluno, float mediaAluno) {
        this.nomeAluno = nomeAluno;
        this.matriculaAluno = matriculaAluno;
        this.cursoAluno = cursoAluno;
        this.mediaAluno = mediaAluno;
    }

    public Aluno() {
    }

    // metodos getters e setters
    public String getNomeAluno() {
        return nomeAluno;
    }

    public void setNomeAluno(String nomeAluno) {
        this.nomeAluno = nomeAluno;
    }

    public int getMatriculaAluno() {
        return matriculaAluno;
    }

    public void setMatriculaAluno(int matriculaAluno) {
        this.matriculaAluno = matriculaAluno;
    }

    public String getCursoAluno() {
        return cursoAluno;
    }

    public void setCursoAluno(String cursoAluno) {
        this.cursoAluno = cursoAluno;
    }

    public float getMediaAluno() {
        return mediaAluno;
    }

    public void setMediaAluno(float mediaAluno) {
        this.mediaAluno = mediaAluno;
    }

    // metodo compareTo para a media
    @Override
    public int compareTo(Aluno o) {
        if (this.mediaAluno < o.mediaAluno) {
            return -1;
        } if (this.mediaAluno > o.mediaAluno) {
            return 1;
        }
        return 0;
    }
}
