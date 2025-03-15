public class Aluno extends Pessoa {
    protected String matricula;

    public Aluno(String nome, int idade, String matricula) {
        super(nome, idade);
        this.matricula = matricula;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public String getMatricula() {
        return this.matricula;
    }

    @Override
    public void exibirInformacoes() {
        System.out.println(
                "\nINFORMACOES\nNome: " + getNome() + "\nIdade: " + getIdade() + "\nMatricula: " + getMatricula() + "");
    }
}
