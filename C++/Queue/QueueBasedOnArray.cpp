/*
Queue Data Structure based on Array
Program author: Sazzad Hossen
Github: https://github.com/SazzadSH
*/


#include <iostream>

using namespace std;

#define queueSize 10

class Queue
{
private:
    int queueArray[queueSize];
    int front, rear, dataCount;

public:
    Queue()
    {
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
            rear++;
            queueArray[rear] = data;
            dataCount++;

            if(rear == (queueSize -1))
            {
                rear = -1;
            }
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
            int data = queueArray[front];
            queueArray[front] = NULL;
            front++;
            dataCount--;

            if(front == queueSize)
            {
                front = 0;
            }

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
            return queueArray[front];
        }
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

    int Size()
    {
        return dataCount;
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

    test.Enqueue(100);
    test.Enqueue(110);
    test.Enqueue(250);
    test.Enqueue(500);
    test.Enqueue(95);

    cout << test.Dequeue() << endl;
    cout << test.Dequeue() << endl;

    test.Enqueue(402);

    cout << test.Front() << endl;
    cout << test.Size() << endl;
    return 0;
}
