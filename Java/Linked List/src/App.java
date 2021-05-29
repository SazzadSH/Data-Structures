import java.util.ArrayList;
import java.util.List;

public class App {
    public static void main(String[] args) throws Exception {
        LinkedList<Integer> list = new LinkedList<Integer>();

        list.add(10);
        list.add(102);
        list.add(300);

        list.remove(102);

        list.printAll();
    }
}