public class PolimorfismoEmAcao {
    public static void main(String[] args) {
        Animal[] animais = new Animal[2];
        animais[0] = new Cachorro();
        animais[1] = new Gato();

        for (Animal animal : animais) {
            animal.emitirSom();
        }
    }

    public static class Animal {

        public void emitirSom() {
            System.out.println("Som generico de animal.");
        }
    }

    public static class Cachorro extends Animal {
        @Override
        public void emitirSom() {
            System.out.println("Latido.");
        }
    }

    public static class Gato extends Animal {
        @Override
        public void emitirSom() {
            System.out.println("Miado.");
        }
    }
}
