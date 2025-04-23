public class Aluno extends Pessoa {
    private String identificacao;

    public String getIdentificacao() {
        return identificacao;
    }

    public void setIdentificacao(String identificacao) {
        this.identificacao = identificacao;
    }

    public Aluno(String identificacao, String nome) {
        super(nome);
        this.identificacao = identificacao;
    }

    @Override
    public String toString() {
        String aux = super.toString() + " " + getIdentificacao() + " " + getIdade() + " " + getCpf();
        return aux;
    }

    public final boolean validarCPF() {

        return true;
    }

    public void respirar() {

    }
}