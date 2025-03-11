import java.util.Scanner;

public class Mercado {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nome: ");
        String nome = scanner.nextLine();
        System.out.print("Preco: ");
        double preco = scanner.nextDouble();
        System.out.print("Estoque: ");
        int estoque = scanner.nextInt();
        Produto p1 = new Produto(nome, preco, estoque);
        p1.exibirInformacoes();
        p1.adicionarEstoque(scanner);
        p1.removerEstoque(scanner);
        p1.exibirInformacoes();

        scanner.close();
    }
}
