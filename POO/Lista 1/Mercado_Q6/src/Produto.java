import java.util.Scanner;

public class Produto {
    private String nome;
    private double preco;
    private int estoque;

    // CONSTRUTOR
    public Produto(String nome, double preco, int estoque) {
        this.nome = nome;
        this.preco = preco;
        this.estoque = estoque;
    }

    // MÉTODO PARA ADICIONAR PRODUTOS AO ESTOQUE
    public void adicionarEstoque(Scanner scanner) {
        System.out.print("Quanto deseja adicionar ao estoque? ");
        int qtd = scanner.nextInt();
        if (qtd > 0) {
            setEstoque(getEstoque() + qtd);
            System.out.println("Estoque realizado.");
        } else {
            System.out.println("Valor para estoque invalido! Tente novamente.");
        }
    }

    // MÉTODO PARA REMOVER PRODUTOS DO ESTOQUE
    public void removerEstoque(Scanner scanner) {
        System.out.print("Quanto deseja remover do estoque? ");
        int qtd = scanner.nextInt();
        if (getEstoque() < qtd) {
            System.out.println("Não é possível remover esta quantidade do estoque.");
        } else {
            setEstoque(getEstoque() - qtd);
            System.out.println("Quantidade removida.");
        }
    }

    // MÉTODO PARA EXIBIR DADOS DO PRODUTO
    public void exibirInformacoes() {
        System.out.printf("Nome: %s\nPreco: %.2f\nEstoque: %d\n", this.nome, this.preco, this.estoque);
    }

    // MÉTODOS SETTERS E GETTERS
    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return this.nome;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public double getPreco() {
        return this.preco;
    }

    public void setEstoque(int estoque) {
        this.estoque = estoque;
    }

    public int getEstoque() {
        return this.estoque;
    }
}
