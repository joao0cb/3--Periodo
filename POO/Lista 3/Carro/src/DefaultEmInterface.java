public class DefaultEmInterface {
    public static void main(String[] args) {
        Carro kwid = new Carro();
        kwid.status();
        kwid.acelerar();
    }

    public interface Veiculo {
        public void acelerar();

        default void status() {
            System.out.println("Veículo pronto para uso.");
        }
    }

    public static class Carro implements Veiculo {
        @Override
        public void acelerar() {
            System.out.println("Carro acelerando...");
        }

        public void status() {
            Veiculo.super.status();
        }
    }
}