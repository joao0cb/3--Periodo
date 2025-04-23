public class Pessoa {
    protected String nome;
    protected String idade;
    protected String cpf;

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getIdade() {
        return this.idade;
    }

    public void setIdade(String idade) {
        this.idade = idade;
    }

    public String getCpf() {
        return this.cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public Pessoa(String nome) {
        this.nome = nome;
    }

    @Override
    public String toString() {
        return "Pessoa [Nome: " + getNome() + " Idade: " + getIdade() + " CPF: " + getCpf() + "]";
    }

    // public final boolean validarCPF() {
    // if(cpf == null || cpf.length() != 11 || !cpf.matches("\\d+")) {
    // return false;
    // }
    // return true;
    // }

    // public abstract boolean validarCPF();

    // public abstract void respirar();
}