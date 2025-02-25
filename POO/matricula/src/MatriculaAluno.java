import java.util.Scanner;
import java.util.Random;

public class MatriculaAluno {
    public static void main(String[] args) throws Exception {
        System.out.println("Boas-vindas ao novo semestre da UNICAP.");
        Scanner scanner = new Scanner(System.in);
        System.out.print("Insira seu nome: ");
        String nome = scanner.nextLine();
        Aluno aluno1 = new Aluno(nome);
        aluno1.inserirNotas(scanner);
        aluno1.exibirInformacoes();
        scanner.close();
    }
}

class Aluno {
    private String nome;
    private int RA;
    private double[] notas = new double[3];
    private double media;

    public Aluno(String nome) {
        this.nome = nome;
        Random random = new Random();
        this.RA = 100000 + random.nextInt(900000);
    }

    public void exibirInformacoes() {
        System.out.println("Nome: " + this.nome);
        System.out.println("RA: " + this.RA);
        calcularMedia();
        System.out.println("Media das notas: " + this.media);
    }

    public void inserirNotas(Scanner scanner) {
        System.out.print("Insira suas notas: ");
        for (int i = 0; i < notas.length; ++i) {
            notas[i] = scanner.nextDouble();
        }
    }

    public void calcularMedia() {
        double soma = 0;
        for (double n : this.notas) {
            soma += n;
        }
        this.media = soma / this.notas.length;
    }
}