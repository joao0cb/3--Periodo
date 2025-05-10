import java.io.Serializable;

public class Alunos implements Serializable {
    private String nome;
    private int turma;

    public Alunos(String nome, int turma) {
        this.nome = nome;
        this.turma = turma;
    }
}
