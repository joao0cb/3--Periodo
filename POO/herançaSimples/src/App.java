public class App {
    public static void main(String[] args) {
        Pessoa p1 = new Pessoa("Joao", 19);
        Aluno a1 = new Aluno("Bento", 20, "0851547");

        p1.exibirInformacoes();
        a1.exibirInformacoes();
    }
}
