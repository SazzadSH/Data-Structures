public class DoublyLinkedList<T> {
    private Node<T> head;


    /*
    Method to append or add data to the list
    */
    public void add(T data) {
        Node<T> node = new Node<>();
        node.setData(data);

        if(this.head == null) {
            this.head = node;
        }
        else {
            Node<T> last = this.head;

            while(last.getNext() != null) {
                last = last.getNext();
            }

            node.setPrevious(last);
            last.setNext(node);
        }
    }

    /*
    Checks if the list is empty
    */
    public boolean isEmpty() {
        return this.head == null ? true : false;
    }

    /*
    print all items of the list
    */
    public void printAll() {
        Node<T> node = this.head;

        while(node != null) {
            System.out.println(node.getData());
            node = node.getNext();
        }
    }
}
