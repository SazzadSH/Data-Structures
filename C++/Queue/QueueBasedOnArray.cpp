#include <iostream>

using namespace std;

#define queueSize 10

class Queue
{
public:
    int queueArray[queueSize];
    int front, rear;

    Queue()
    {
        front = 0;
        rear = -1;
    }

    void Enqueue(int data)
    {
        if(this->isFull())
        {
            cout << "Queue is Full!" << endl;
        }
        else
        {
            rear++;
            queueArray[rear] = data;
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
            int data = queueArray[front];
            front++;

            return data;
        }
    }

    bool isEmpty()
    {
        if(front == queueSize)
        {
            front = 0;
        }

        if(rear == (front - 1))
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
        if(rear == (queueSize - 1))
        {
            rear = -1;
        }

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
        cout << test.queueArray[i] << endl;
    }

    cout << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << test.Dequeue() << endl;
    }
}
