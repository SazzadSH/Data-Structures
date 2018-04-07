#include <iostream>

using namespace std;

struct Node
{
    int element;
    Node *next;
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = NULL;
        tail = head;
    }

    void insert(int data)
    {
        if(head == NULL)
        {
            head = new Node;
            head->element = data;
            head->next = NULL;
            tail = head;
        }
        else
        {
            tail->next = new Node;
            tail = tail->next;
            tail->element = data;
            tail->next = NULL;
        }
    }

    void insertAtHead(int data)
    {
        Node *temp = new Node;
        temp->element = data;
        temp->next = head;
        head = temp;

        delete temp;
    }

    void insertAt(int position, int data)
    {
        if(position > this->length())
        {
            cout << "Position exceeds length of the list!" << endl;
            return;
        }
        else if(position == 1)
        {
            this->insertAtHead(data);
            return;
        }
        else if(position <= 0)
        {
            cout << "Position does not exist!" << endl;
            return;
        }

        Node *temp = head;

        for(int i = 2; i < position; i++)
        {
            temp = temp->next;
        }

        Node *newNode = new Node;
        newNode->element = data;
        newNode->next = temp->next;
        temp->next = newNode;

        delete temp;
        delete newNode;
    }

    void removeHead()
    {
        Node *temp = head;
        head = head->next;
        delete head;
    }

    void removeAt(int position)
    {
        if(position == 1)
        {
            this->removeHead();
        }
        else if(position < 1)
        {
            cout << "Position does not exist!" << endl;
        }
        else if (position > this->length())
        {
            cout << "Position exceeds length of the list!" << endl;
        }
        else
        {
            Node *temp = head;
            Node *newNOde;

            for(int i = 2; i < position; i++)
            {
                temp = temp->next;
            }

            newNOde = temp->next;
            temp->next = newNOde->next;

            delete newNOde;
            delete temp;
        }
    }

    void remove()
    {
        this->removeAt(this->length());
    }

    void showAll()
    {
        Node *temp = head;

        while(temp != NULL)
        {
            cout << temp->element << endl;
            temp = temp->next;
        }

        delete temp;
    }

    void showAt(int position)
    {
        Node *temp = head;

        for(int i = 2; i <= position; i++)
        {
            temp = temp->next;
        }

        delete temp;

        cout << "Value at position " << position << ": " << temp->element << endl;
    }

    void search(int data)
    {
        Node *temp = head;
        int i = 0, flag = 0;

        while(temp != NULL)
        {
            i++;
            if(temp->element == data)
            {
                cout << "Element " << data << " found at position: " << i << endl;
                flag = 1;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }

        if(flag != 1)
        {
            cout << "Element not found in the list." << endl;
        }

        delete temp;
    }

    void deleteList()
    {
        while(head != NULL)
        {
            delete head;
            head = head->next;
        }
    }

    int valueAt(int position)
    {
        Node *temp = head;

        for(int i = 2; i <= position; i++)
        {
            temp = temp->next;
        }

        int value = temp->element;
        delete temp;

        return value;
    }

    int length()
    {
        int cnt = 0;
        Node *temp = head;

        while(temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }

        delete temp;
        return cnt;
    }

};

class Queue
{
private:
    LinkedList QueueList;
    int front, rear, dataCount, queueSize;

public:
    Queue()
    {
        queueSize = 10;
        front = 0;
        rear = -1;
        dataCount = 0;
    }

    Queue(int size)
    {
        queueSize = size;
        front = 0;
        rear = -1;
        dataCount = 0;
    }

    void Enqueue(int data)
    {
        if(this->isFull())
        {
            cout << "Queue is Full!" << endl;
        }
        else
        {
            QueueList.insert(data);
            dataCount++;
        }
    }

    int Dequeue()
    {
        if(this->isEmpty())
        {
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            int data = QueueList.head->element;
            QueueList.removeHead();
            dataCount--;
            return data;
        }
    }

    int Front()
    {
        if(this->isEmpty())
        {
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            return QueueList.head->element;
        }
    }

    int Size()
    {
        return dataCount;
    }

    bool isFull()
    {
        if(dataCount == queueSize)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool isEmpty()
    {
        if(dataCount == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    Queue test;

    for(int i = 0; i < 10; i++)
    {
        test.Enqueue((i+3)*4);
    }

    test.Enqueue(210);

    cout << test.Size() << endl << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << test.Dequeue() << endl;
    }

    test.Dequeue();

    cout << test.Size() << endl;
}
