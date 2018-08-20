#include <iostream>
#include <string>

template <typename T>  //Template used in Node to adopt given data type by user in runtime.

struct Node            //Structure of each node in a list.
{
    T data;            //variable of given data type by user to carry data element of each node in the list.
    Node *nextRef;     //Pointer that points and refers the next node in the list. This pointer carries the the address of the next node's memory location.
};

template <class T>     //Template used in the LinkedList class to adopt given data type by user in runtime.

class LinkedList       //Actual Linked List class that the user can use to create a object of linked list.
{
public:
    Node <T> *head;
    Node <T> *tail;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push(const T& data)
    {
        if(head != nullptr)
        {
            Node <T> *temp = new Node <T>;
            temp->data = data;
            temp->nextRef = head;
            head = temp;
        }
        else
        {
            head = new Node <T>;
            head->data = data;
            head->nextRef = nullptr;
            tail = head;
        }
    }

    void append(const T& data)
    {
        if(head != nullptr)
        {
            Node <T> *temp = new Node <T>;
            temp->data = data;
            temp->nextRef = nullptr;
            tail->nextRef = temp;
            tail = temp;
        }
        else
        {
            head = new Node <T>;
            head->data = data;
            head->nextRef = nullptr;
            tail = head;
        }
    }

    void insert(const T& data, int index)
    {
        if(index == 0)
        {
            this->push(data);
        }
        else if(index > (this->length() - 1))
        {
            std::cout << "Error! This index of position does not exist." << std::endl;
        }
        else
        {
            Node <T> *temp = head;
            int i = 1;
            while(i != index)
            {
                temp = temp->nextRef;
                i++;
            }

            Node <T> *newTemp = new Node <T>;
            newTemp->data = data;
            newTemp->nextRef = temp->nextRef;
            temp->nextRef = newTemp;
        }
    }

    T pop()
    {
        if(head != nullptr)
        {
            Node <T> *temp = head;
            head = head->nextRef;
            T data = temp->data;
            delete temp;
            return data;
        }
        else
        {
            std::cout << "Error! List is empty." << std::endl;
        }
    }

    void popTail()
    {
        if(head != nullptr)
        {
            if(head == tail)
            {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                Node <T> *temp = head;

                while(temp->nextRef->nextRef != nullptr)
                {
                    temp = temp->nextRef;
                }

                delete tail;
                tail = temp;
                tail->nextRef = nullptr;
            }
        }
        else
        {
            std::cout << "Error! List is empty." << std::endl;
        }
    }

   /* void popAt()
    {

    }

    void remove()
    {

    }

    void search()
    {

    } */

    void showAll()
    {
        if(head != nullptr)
        {
            Node <T> *temp = head;

            while(temp != nullptr)
            {
                std::cout << temp->data << std::endl;
                temp = temp->nextRef;
            }
        }
        else
        {
            std::cout << "List is empty!" << std::endl;
        }
    }

    /*void reverseList()
    {

    }

    void replace()
    {

    }

    void swap()
    {

    }

    void sort()
    {

    }*/

    void clearList()
    {
        Node <T> *temp = head;
        Node <T> *newTemp = temp;
        while(temp != nullptr)
        {
            temp = temp->nextRef;
            delete newTemp;
            newTemp = temp;
        }

        head = nullptr;
        tail = nullptr;
    }

    int length()
    {
        if(head == nullptr)
        {
            return 0;
        }
        else
        {
            int i = 0;
            Node <T> *temp = head;
            while(temp != nullptr)
            {
                i++;
                temp = temp->nextRef;
            }

            return i;
        }
    }

    bool isEmpty()
    {
        if(head == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

   /* void inputArray()
    {

    }

    void getHead()
    {

    }

    void getTail()
    {

    }

    void get()
    {

    } */
};

int main()
{

    LinkedList <int> test;

    test.push(10);
    test.push(101);
    test.push(12);
    test.append(244);
    test.push(34);
    test.append(161);
    test.append(42);

    test.insert(101, 0);
    test.insert(102, 1);

    test.popTail();

    test.showAll();
    std::cout << "length: " << test.length() << std::endl;
    return 0;
}
