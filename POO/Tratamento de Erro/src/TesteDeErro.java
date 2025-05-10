public class TesteDeErro {
    /*
     * public static void main(String[] args) throws Exception {
     * int num, den;
     * Scanner scan = new Scanner(System.in);
     * try {
     * num = scan.nextInt();
     * den = scan.nextInt();
     * System.out.println(num + " " + den);
     * } catch (InputMismatchException e) {
     * System.out.println("Digite apenas números. Atribuirei valor 1.");
     * num = 1;
     * den = 1;
     * }
     * divisao(num, den);
     * scan.close();
     * }
     * 
     * public static int divisao(int num, int den) throws ArithmeticException {
     * return num / den;
     * }
     */

    public static void verificarIdade(int idade) throws IdadeInvalidaException {
        if (idade < 0) {
            throw new IdadeInvalidaException("Idade Inválida. Menor do que 0.");
        } else if (idade < 18) {
            throw new IdadeInvalidaException("Idade inválida. Apenas para maiores de 18 anos.");
        }
        System.out.println("Idade válida.");
    }

    public static void main(String[] args) {
        try {
            verificarIdade(1);
        } catch (IdadeInvalidaException e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }
}

class IdadeInvalidaException extends Exception {
    public IdadeInvalidaException(String mensagem) {
        super(mensagem);
    }
}