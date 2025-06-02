class TarefaImprimir extends Thread {
    int idTarefa;
    int tempo;

    public TarefaImprimir(int idTarefa, int tempo) {
        this.idTarefa = idTarefa;
        this.tempo = tempo;
    }

    public void run() {
        try {
            System.out.println("Tarefa #" + idTarefa + " vai dormir " + tempo + " milisegundos");
            Thread.sleep(tempo);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Tarefa #" + idTarefa + " parou de dormir");
    }

}

public class App {
    public static void main(String[] args) throws Exception {
        TarefaImprimir t1 = new TarefaImprimir(1, 5000);
        t1.start();
        TarefaImprimir t2 = new TarefaImprimir(2, 1000);
        t2.start();
        TarefaImprimir t3 = new TarefaImprimir(3, 900);
        t3.start();

    }
}
