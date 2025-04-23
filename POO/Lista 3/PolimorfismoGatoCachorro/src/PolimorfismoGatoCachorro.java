public class PolimorfismoGatoCachorro {
    public static final int TAM_LISTA = 4;

    public static void main(String[] args) {
        Animal[] animais = new Animal[TAM_LISTA];
        animais[0] = new Gato("Lolo");
        animais[1] = new Cachorro("Bob");

        for (Animal anim : animais) {
            if (anim != null) {
                anim.emitirSom();
            }
        }
    }

    public interface Animal {
        void emitirSom();
    }

    public static class Cachorro implements Animal {
        protected String nome;

        public Cachorro(String nome) {
            this.nome = nome;
        }

        public void setNome(String nome) {
            this.nome = nome;
        }

        public String getNome() {
            return this.nome;
        }

        @Override
        public void emitirSom() {
            System.out.println(nome + ": Au Au!");
        }
    }

    public static class Gato implements Animal {
        protected String nome;

        public Gato(String nome) {
            this.nome = nome;
        }

        public void setNome(String nome) {
            this.nome = nome;
        }

        public String getNome() {
            return this.nome;
        }

        @Override
        public void emitirSom() {
            System.out.println(nome + ": Miau!");
        }
    }
}