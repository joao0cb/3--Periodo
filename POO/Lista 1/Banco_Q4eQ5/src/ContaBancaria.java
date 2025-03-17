import java.util.Scanner;

public class ContaBancaria {
    private String titular;
    private double saldo;

    // CONSTRUTOR
    public ContaBancaria(String titular, double saldo) {
        this.titular = titular;
        this.saldo = saldo;
    }

    // MÉTODO PARA DEPÓSITO
    public void depositarDinheiro(Scanner scanner) {
        System.out.println("Quanto voce deseja depositar?");
        double valor = scanner.nextDouble();
        if (valor > 0) {
            setSaldo(getSaldo() + valor);
            System.out.println("Deposito realizado.");
        } else {
            System.out.println("Valor para deposito invalido! Tente novamente.");
        }
    }

    // MÉTODO PARA SAQUE
    public void sacarDinheiro(Scanner scanner) {
        System.out.println("Quanto você deseja sacar?");
        double valor = scanner.nextDouble();
        if (getSaldo() < valor) {
            System.out.println("Não é possível sacar este valor.");
        } else {
            setSaldo(getSaldo() - valor);
            System.out.println("Valor sacado.");
        }
    }

    // MÉTODO PARA EXIBIR SALDO
    public void exibirSaldo() {
        System.out.printf("Saldo: R$%.2f\n", getSaldo());
    }

    // MÉTODOS SETTERS E GETTERS
    public void setTitular(String titular) {
        this.titular = titular;
    }

    public String getTitular() {
        return this.titular;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public double getSaldo() {
        return this.saldo;
    }

}