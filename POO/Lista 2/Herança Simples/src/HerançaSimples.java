public class HerançaSimples {
    public static void main(String[] args) {
        Pessoa p1 = new Pessoa("Joao", 19);
        Aluno a1 = new Aluno("Bento", 20, "0851547");

        p1.exibirInformacoes();
        a1.exibirInformacoes();
    }

    public static class Pessoa {
        protected String nome;
        protected int idade;

        public Pessoa() {
        }

        public Pessoa(String nome, int idade) {
            this.nome = nome;
            this.idade = idade;
        }

        public void setNome(String nome) {
            this.nome = nome;
        }

        public String getNome() {
            return this.nome;
        }

        public void setIdade(int idade) {
            this.idade = idade;
        }

        public int getIdade() {
            return this.idade;
        }

        public void exibirInformacoes() {
            System.out.println("\nINFORMACOES\nNome: " + getNome() + "\nIdade: " + getIdade());
        }
    }

    public static class Aluno extends Pessoa {
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
                    "\nINFORMACOES\nNome: " + getNome() + "\nIdade: " + getIdade() + "\nMatricula: " + getMatricula()
                            + "");
        }
    }
}