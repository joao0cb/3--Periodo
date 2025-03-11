import java.util.Scanner;

public class Time {
    // private String nome;
    private Jogador[] jogador = new Jogador[3];

    public void setTime() {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < jogador.length; ++i) {
            jogador[i] = new Jogador();
            System.out.print("Nome do jogador " + (i + 1) + ": ");
            jogador[i].setNome(scanner.nextLine());
            System.out.print("Posicao do jogador " + (i + 1) + ": ");
            jogador[i].setPosicao(scanner.nextLine());
            System.out.print("Numero da camisa do jogador " + (i + 1) + ": ");
            jogador[i].setCamisa(scanner.nextInt());
            scanner.nextLine();
        }
        scanner.close();
    }

    public void exibirTime() {
        System.out.println("JOGADORES DO TIME");
        for (int i = 0; i < jogador.length; ++i) {
            System.out.println("Jogador nº " + (i + 1) + ": " + jogador[i].getNome() + ", " + jogador[i].getPosicao()
                    + ", " + jogador[i].getCamisa());
        }
    }
}