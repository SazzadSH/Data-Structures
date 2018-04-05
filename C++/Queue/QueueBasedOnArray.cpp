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
        rear = 0;
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

}
