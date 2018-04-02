#include <iostream>

using namespace std;

#define queueSize 100

class Queue
{
private:
    int ara[queueSize];
    int front, rear, counter;

public:

    Queue()
    {
        front = -1;
        rear = -1;
    }

    void Enqueue(int data)
    {
        if(this->isFull())
        {
            cout << "Failed! Queue is Full." << endl;
        }
        else
        {
            if(rear < queueSize-1)
            {
                ara[++rear] = data;
            }
            else
            {
                rear = -1;
                this->Enqueue(data);
            }
        }
    }

    int Dequeue()
    {
        if(isEmpty())
        {
            cout << "Failed! Queue is empty." << endl;
        }
        else
        {
            if(front < queueSize-1)
            {
                int data = ara[++front];
                ara[front] = NULL;
                return data;
            }
            else
            {
                front = -1;
                return this->Dequeue();
            }
        }
    }

    bool isFull()
    {
        if(((rear == queueSize) && (front == 0)) || (rear == (front - 1)))
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
        if(rear == front)
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
    for(int i = 0; i < 102; i++)
    {
        test.Enqueue((i+3)*4);
    }

    for(int i = 0; i < 102; i++)
    {
        cout << test.Dequeue() << endl;
    }
}
