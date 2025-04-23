public class Pagamento {
    public static void main(String[] args) {
        Funcionario f1 = new Funcionario(5326.67);
        System.out.println("Salario: R$" + f1.calcularPagamento());
    }

    public interface Pagavel {
        public double calcularPagamento();
    }

    public static class Funcionario implements Pagavel {
        protected double salario;

        public Funcionario(double salario) {
            this.salario = salario;
        }

        public void setSalario(double salario) {
            this.salario = salario;
        }

        public double getSalario() {
            return this.salario;
        }

        @Override
        public double calcularPagamento() {
            return getSalario();
        }
    }
}