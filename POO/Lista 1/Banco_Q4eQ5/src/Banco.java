import java.util.Scanner;

public class Banco {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ContaBancaria contaBancaria = new ContaBancaria("João", 1000.0);
        contaBancaria.exibirSaldo();
        contaBancaria.depositarDinheiro(scanner);
        contaBancaria.sacarDinheiro(scanner);
        contaBancaria.exibirSaldo();

        scanner.close();
    }
}
