import java.io.FileNotFoundException;
//import java.io.FileOutputStream;
import java.io.IOException;
//import java.io.ObjectOutputStream;
import java.io.FileInputStream;
import java.io.ObjectInputStream;

public class App {
    public static void main(String[] args) {
        Alunos aluno;
        // Alunos aln = new Alunos("Lucas", 3);
        FileInputStream fluxo;
        try {
            fluxo = new FileInputStream("alunos.ser");
            ObjectInputStream alunos = new ObjectInputStream(fluxo);
            // alunos.writeObject(aln);
            aluno = (Alunos) alunos.readObject();
            alunos.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
