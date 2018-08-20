#include <iostream>

//Node class: Model of each nodes a linked list.
struct Node
{
public:

    int element;        //variable that holds integer data type for each node.
    Node *nextRef;    // pointer that holds the reference of the next node in a linked list.
};

class LinkedList
{
public:

    Node *head;
    Node *tail;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int data)
    {
        if(head != nullptr)
        {
            tail->nextRef = new Node;
            tail = tail->nextRef;
            tail->element = data;
            tail->nextRef = nullptr;
        }
        else
        {
            head = new Node;
            head->element = data;
            head->nextRef = nullptr;
            tail = head;
        }
    }

    void inHead(int data)
    {
        if(head != nullptr)
        {
            Node *temp = new Node;
            temp->element = head->element;
            temp->nextRef = head->nextRef;
            head->element = data;
            head->nextRef = temp;
            temp = nullptr;
        }
        else
        {
            head = new Node;
            head->element = data;
            head->nextRef = nullptr;
            tail = head;
        }
    }

    void insertAt(int index, int data)
    {
        if(index == 0)
        {
            this->inHead(data);
        }
        else
        {
            if(this->length() <= index)
            {
                std::cout << "This position of index " << index << " does not exit in the list." << std::endl;
            }
            else
            {
                Node *temp = head;

                int i = 0;

                while(i < index-1)
                {
                    temp = temp->nextRef;
                    i++;
                }

                Node *newTemp = new Node;
                newTemp->element = data;
                newTemp->nextRef = temp->nextRef;
                temp->nextRef = newTemp;
                newTemp = nullptr;
            }
        }
    }

    int remove()
    {
        if(head != nullptr)
        {
            if(head->nextRef == nullptr)
            {
                int data = head->element;
                delete head;
                head = nullptr;

                return data;
            }
            else
            {
                Node *temp = head;

                while(temp->nextRef->nextRef != nullptr)
                {
                    temp = temp->nextRef;
                }

                int data = temp->nextRef->element;
                delete temp->nextRef;
                temp->nextRef = nullptr;

                return data;
            }
        }
        else
        {
            std::cout << "List is already empty!" << std::endl;
            return 0;
        }
    }

    int removeHead()
    {
        if(head != nullptr)
        {
            int data = head->element;
            Node *temp = head->nextRef;
            delete head;
            head = temp;
            temp = nullptr;

            return data;
        }
        else
        {
            std::cout << "List is already empty!" << std::endl;
            return 0;
        }
    }

    int removeAt(int index)
    {
        if(index >= this->length())
        {
            std::cout << "This position of index " << index << " does not exist." << std::endl;
            return 0;
        }
        else if(index == 0)
        {
            return this->removeHead();
        }
        else
        {
            if(head != nullptr)
            {
                Node *temp = head;
                int i = 0;

                while(i < (index-1))
                {
                    temp = temp->nextRef;
                    i++;
                }

                Node *newTemp = temp->nextRef->nextRef;
                int data = temp->element;
                delete temp->nextRef;
                temp->nextRef = newTemp;
                newTemp = nullptr;
                temp = nullptr;
            }
            else
            {
                std::cout << "List is already empty!" << std::endl;
                return 0;
            }
        }
    }

    int search(int data)
    {
        int len = this->length();
        int index = 0;

        Node *temp = head;

        while(temp != nullptr)
        {
            if(temp->element == data)
            {
                return index;
                break;
            }
            else
            {
                temp = temp->nextRef;
                index++;
            }
        }

        if(temp == nullptr)
        {
            std::cout << "Element does not exist in the list." << std::endl;
            return 0;
        }
    }

    int length()
    {
        int i = 0;

        Node *temp = head;

        while(temp != nullptr)
        {
            temp = temp->nextRef;
            i++;
        }

        temp = nullptr;

        return i;
    }

    void showAll()
    {
        if(head != nullptr)
        {
            Node *temp = head;
            while(temp != nullptr)
            {
                std::cout << temp->element << std::endl;
                temp = temp->nextRef;
            }
        }
        else
        {
            std::cout << "List is empty!" << std::endl;
        }
    }

    void showAt(int index)
    {
        if(index == 0)
        {
            std::cout << head->element << std::endl;
        }
        else if(head != nullptr)
        {
            if(index < this->length())
            {
                Node *temp = head;
                int i = 0;

                while(i < index)
                {
                    temp = temp->nextRef;
                    i++;
                }

                std::cout << temp->element << std::endl;
            }
            else
            {
                std::cout << "This index of position " << index << " does not exist in the list." << std::endl;
            }
        }
        else
        {
            std::cout << "The list is already empty!" << std::endl;
        }
    }

    int valueAt(int index)
    {
        if(index == 0)
        {
            return head->element;
        }
        else if(head != nullptr)
        {
            if(index < this->length())
            {
                Node *temp = head;
                int i = 0;

                while(i < index)
                {
                    temp = temp->nextRef;
                    i++;
                }

                return temp->element;
            }
            else
            {
                std::cout << "This index of position " << index << " does not exist in the list." << std::endl;
                return 0;
            }
        }
        else
        {
            std::cout << "The list is already empty!" << std::endl;
            return 0;
        }
    }

    void deleteList()
    {
        Node *temp = head;

        while(temp->nextRef != nullptr)
        {
            temp = temp->nextRef;
            delete head;
            head = temp;
        }

        delete head;
        head = nullptr;
        temp = nullptr;
    }



};

int main()
{
    LinkedList test;

test.insert(10);
test.insert(13);
    test.insert(21);
    test.insert(31);
    test.insert(15);





    test.showAll();
    std::cout << test.length() << std::endl;
}


// Swap Nodes
//reverse
// Sorting
//replace
