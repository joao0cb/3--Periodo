public class HerancaMultiplaInterfaces {
    public static void main(String[] args) {
        Estagiario estg = new Estagiario("Joao", "Ciencia da Computacao");
        estg.exibirInformacoes();
        estg.trabalhar();
    }

    public interface Trabalhador {
        public void trabalhar();
    }

    public static class Estudante {
        protected String nome;
        protected String curso;

        public Estudante() {
        }

        public Estudante(String nome, String curso) {
            this.nome = nome;
            this.curso = curso;
        }

        public void setNome(String nome) {
            this.nome = nome;
        }

        public String getNome() {
            return this.nome;
        }

        public void setCurso(String curso) {
            this.curso = curso;
        }

        public String getCurso() {
            return this.curso;
        }

        public void exibirInformacoes() {
            System.out.println("Nome: " + getNome() + "\nCurso: " + getCurso());
        }
    }

    public static class Estagiario extends Estudante implements Trabalhador {

        public Estagiario(String nome, String curso) {
            super(nome, curso);
        }

        @Override
        public void trabalhar() {
            System.out.println("Estagiario trabalhando...");
        }

    }
}
