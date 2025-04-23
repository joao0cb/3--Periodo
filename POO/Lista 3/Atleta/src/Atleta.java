public class Atleta {
    public static void main(String[] args) {
        Triatleta t1 = new Triatleta("João", 237);
        t1.correr();
        t1.nadar();
    }

    public interface Nadador {
        void nadar();
    }

    public interface Corredor {
        void correr();
    }

    public static class Triatleta implements Nadador, Corredor {
        protected int numero;
        protected String nome;

        public Triatleta(String nome, int numero) {
            this.nome = nome;
            this.numero = numero;
        }

        public void setNumero(int numero) {
            this.numero = numero;
        }

        public int getNumero() {
            return this.numero;
        }

        public void setNome(String nome) {
            this.nome = nome;
        }

        public String getNome() {
            return this.nome;
        }

        @Override
        public void correr() {
            System.out.println("Triatleta " + getNome() + "(" + getNumero() + ") está correndo.");
        }

        @Override
        public void nadar() {
            System.out.println("Triatleta " + getNome() + "(" + getNumero() + ") está nadando.");
        }
    }
}