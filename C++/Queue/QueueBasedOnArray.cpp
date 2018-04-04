#include <iostream>

using namespace std;

#define queueSize 10;

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
            if(rear == (queueSize-1))
            {
                rear = -1;
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
        if(((rear == queueSize-1) && (front == -1)) || (rear == (front-1)))
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

}
