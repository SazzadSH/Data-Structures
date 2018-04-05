#include <iostream>

using namespace std;

#define queueSize 10

class Queue
{
private:
    int queueArray[queueSize];
    int front, rear;

public:
    Queue()
    {
        front = 0;
        rear = 0;
    }
    void Enqueue(int data)
    {
        if(this->isFull())
        {
            cout << "Queue is Full!" << endl;
        }
        else
        {
            if(rear == queueSize)
            {
                rear = -1;

                this->Enqueue(data);
            }
            else
            {
                if(rear == -1)
                {
                    rear = 0;
                }

                queueArray[rear] = data;
                rear++;
            }
        }
    }

    int Dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            if(front == queueSize)
            {
                front = -1;

                this->Dequeue();
            }
            else
            {
                if(front == -1)
                {
                    front = 0;
                }

                queueArray[front] = NULL;
                front++;
            }
        }
    }

    bool isEmpty()
    {
        if(rear == front)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool isFull()
    {
        if(rear == (front - 1))
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

    for(int i = 0; i < 10; i++)
    {
       cout << test.Dequeue() << endl;
    }
}
