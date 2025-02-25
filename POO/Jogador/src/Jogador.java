public class Jogador {
    private String nome;
    private String posicao;
    private int camisa;

    // CONSTRUTOR PADRAO/DEFAULT
    public Jogador() {

    }

    // CONSTRUTOR COM TODOS OS PARAMETROS
    public Jogador(String nome, String posicao, int camisa) {
        this.nome = nome;
        this.posicao = posicao;
        this.camisa = camisa;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getPosicao() {
        return this.posicao;
    }

    public void setPosicao(String posicao) {
        this.posicao = posicao;
    }

    public int getCamisa() {
        return this.camisa;
    }

    public void setCamisa(int camisa) {
        this.camisa = camisa;
    }

}
