public class HerançaMetodosSobrescritos {
    public static void main(String[] args) {
        Funcionario f1 = new Funcionario("Joao", 3450);
        Gerente g1 = new Gerente("Joao", 5320);
        f1.exibirBonus();
        g1.exibirBonus();
    }

    public static class Funcionario {
        protected String nome;
        protected double salario;

        public Funcionario() {

        }

        public Funcionario(String nome, double salario) {
            this.nome = nome;
            this.salario = salario;
        }

        public void setNome(String nome) {
            this.nome = nome;
        }

        public String getNome() {
            return this.nome;
        }

        public void setSalario(double salario) {
            this.salario = salario;
        }

        public double getSalario() {
            return this.salario;
        }

        public double calcularBonus() {
            return (getSalario() / 100) * 10;
        }

        public void exibirBonus() {
            double bonus = calcularBonus();
            System.out.println("BONUS DO FUNCIONARIO " + getNome() + ": R$" + bonus + "\n");
        }
    }

    public static class Gerente extends Funcionario {

        public Gerente(String nome, double salario) {
            super(nome, salario);
        }

        @Override
        public double calcularBonus() {
            return ((getSalario() / 100) * 10) + super.calcularBonus();
        }

        @Override
        public void exibirBonus() {
            super.exibirBonus();
        }
    }
}
