public class App {
    public static void main(String[] args) throws Exception {
        LinkedList<Integer> list = new LinkedList<Integer>();

        System.out.println(list.isEmpty());
        list.add(10);
        list.add(102);
        list.add(300);

        list.add(500);
        list.add(600);
        list.add(3, 18);

        list.remove(1);

        list.printAll();

        //System.out.println(list.get(3));

        System.out.println(list.isEmpty());
    }
}