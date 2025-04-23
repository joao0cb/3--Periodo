import java.util.TreeSet;

public class ExemploTreeSet {
    public static void main(String[] args) {
        TreeSet<Integer> numeros = new TreeSet<>();

        // Adicionando elementos
        numeros.add(5);
        numeros.add(2);
        numeros.add(8);
        numeros.add(1);
        System.out.println(numeros); // Saída: [1, 2, 5, 8]

        numeros.remove(5);
        System.out.println(numeros); // Saída: [1, 2, 8]

        System.out.println(numeros.contains(2)); // Saída: true
    }
}