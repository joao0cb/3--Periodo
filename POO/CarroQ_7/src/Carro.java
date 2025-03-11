public class Carro {
    public static void main(String[] args) {
        Carrinho carro1 = new Carrinho("Renault", "Kwid", 2024);
        carro1.exibirVelocidade();
        carro1.acelerarCarro();
        carro1.acelerarCarro();
        carro1.acelerarCarro();
        carro1.acelerarCarro();
        carro1.exibirVelocidade();
        carro1.frearCarro();
        carro1.frearCarro();
        carro1.exibirVelocidade();
    }
}
