public class Empregado {
    private int id;
    private String nome;

    public Empregado(int id, String nome) {
        this.id = id;
        this.nome = nome;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getId() {
        return this.id;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return this.nome;
    }

    // public int compareTo(Object obj) {
    //     return this.nome.compareTo(((Empregado) obj).getNome());
    // }
}
