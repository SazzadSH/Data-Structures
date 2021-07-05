public class Node<T> {
    private T data;
    private Node next;
    private Node previous;

    public void setData(T data) {
        this.data = data;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public void setPrevious(Node previous) {
        this.previous = previous;
    }

    public T getData() {
        return this.data;
    }

    public Node getNext() {
        return this.next;
    }

    public Node getPrevious() {
        return this.previous;
    }
}
