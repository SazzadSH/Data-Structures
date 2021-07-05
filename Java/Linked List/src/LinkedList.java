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

    //Add data to the the index provided
    public void add(int index, T data) {
        Node<T> node = new Node<T>();
        node.data = data;
        node.next = null;

        Node<T> temp = this.head;

        if(index == 0) {
            node.next = temp;
            this.head = node;
            return;
        }

        int i = 1;

        for(i = 1; i < index; i++) {
            if(temp.next == null) {
                break;
            }
            temp = temp.next;
        }

        if(i == index) {
            node.next = temp.next;
            temp.next = node;
        }
    }

    //Get an element of the particular index
    public T get(int index) {
        if(index == 0) {
            return this.head.data;
        }

        Node<T> node = this.head;

        for(int i = 1; i <= index; i++) {
            if(node.next == null && i != index) {
                return null;
            }
            node = node.next;
        }

        return node.data;
    }

    //Search given element and deletes from the list if found
    public void remove(T data) {
        Node<T> node = this.head;

        if(this.head.data.equals(data)) {
            this.head = this.head.next;
            node = null;
            return;
        }

        while(node.next != null) {
            if(node.next.data.equals(data)) {
                Node<T> temp = node.next;
                node.next = node.next.next;
                temp = null;
                return;
            }
            node = node.next;
        }
    }

    //Delete an element from the particular index
    public void remove(int index) {
        Node<T> node = this.head;
        
        if(index == 0) {
            this.head = node.next;
            node = null;
            return;
        }

        int i = 1;
        for(i = 1; i < index; i++) {
            if(node.next == null) {
                break;
            }

            node = node.next;
        }

        if(i == (index - 1)) {
            Node<T> temp = node.next;
            node.next = node.next.next;
            temp = null;
        }
    }

    public Boolean isEmpty() {
        return this.head == null ? true : false;
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