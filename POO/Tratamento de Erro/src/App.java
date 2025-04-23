import java.util.Scanner;
import java.util.InputMismatchException;

public class App {
    public static void main(String[] args) throws Exception {
        int num, den;
        Scanner scan = new Scanner(System.in);
        try {
            num = scan.nextInt();
            den = scan.nextInt();
            System.out.println(num + " " + den);
        } catch (InputMismatchException e) {
            System.out.println("Digite apenas números. Atribuirei valor 1.");
            num = 1;
            den = 1;
        }
        divisao(num, den);
        scan.close();
    }

    public static int divisao(int num, int den) throws ArithmeticException {
        return num / den;
    }
}
