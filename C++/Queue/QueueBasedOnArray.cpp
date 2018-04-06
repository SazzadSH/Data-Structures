#include <iostream>

using namespace std;

#define queueSize 10

class Queue
{
public:
    int queueArray[queueSize];
    int front, rear, dataCount;

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

    int Dequeu()
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
        test.Enqueue(100+i);
    }

    test.Dequeu();
    test.Dequeu();
    test.Dequeu();
    test.Dequeu();

    test.Enqueue(90);
    test.Enqueue(91);
    test.Enqueue(92);
    test.Enqueue(93);

    for(int i = 0; i < 10; i++)
    {
        cout << test.queueArray[i] << endl;
    }

    cout << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << test.Dequeu() << endl;
    }
    return 0;
}
