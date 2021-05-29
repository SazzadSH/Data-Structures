public class LinkedList<T> {
    Node<T> head;

    //Add data to the end of the Linked List
    public void add(T data) {
        Node<T> temp = new Node<T>();
        temp.data = data;
        temp.next = null;
        
        if(this.head == null) {
            this.head = temp;
        }
        else{
            Node<T> last = this.head;

            while(last.next != null) {
                last = last.next;
            }

            last.next = temp;
        }
    }

    //Search given element and deletes from the list if found
    public void remove(T data) {
        Node<T> node = this.head;

        while(node.next != null) {
            if(node.next.data.equals(data)) {
                Node<T> temp = node.next;
                node.next = node.next.next;
                temp = null;
                
                return;
            }
        }
    }

    //Prints all existing elements in the list
    public void printAll() {
        Node<T> temp = this.head;

        while(temp != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }
}