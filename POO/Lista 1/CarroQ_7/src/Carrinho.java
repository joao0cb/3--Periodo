public class Carrinho {
    private String marca;
    private String modelo;
    private int ano;
    private double velocidadeAtual;

    // CONSTRUTOR
    public Carrinho(String marca, String modelo, int ano) {
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
    }

    // MÉTODO ACELERAR
    public void acelerarCarro() {
        if (getVelocidade() == 80) {
            System.out.println("Velocidade muito alta! Tenha cuidado.");
        } else {
            setVelocidade(+1);
        }
    }

    // MÉTODO FREAR
    public void frearCarro() {
        if (getVelocidade() == 0) {
            System.out.println("O carro esta parado.");
        } else {
            setVelocidade(-1);
        }
    }

    // MÉTODO EXIBIR VELOCIDADE
    public void exibirVelocidade() {
        System.out.printf("Velocidade Atual: %.2f\n", this.velocidadeAtual);
    }

    // MÉTODOS GETTERS E SETTERS
    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getMarca() {
        return this.marca;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public String getModelo() {
        return this.modelo;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public int getAno() {
        return this.ano;
    }

    public void setVelocidade(double velocidadeAtual) {
        this.velocidadeAtual = velocidadeAtual;
    }

    public double getVelocidade() {
        return this.velocidadeAtual;
    }
}
