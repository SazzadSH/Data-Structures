#include <iostream>

using namespace std;

#define defaultSize 100

class stack
{
    int stackAra[defaultSize];
    int top;

public:
    stack()
    {
        top = -1;
    }

    void Push(int data)
    {
        if(this->isFull())
        {
            cout << "Stack Overflow!" << endl;
        }
        else
        {
            stackAra[++top] = data;
        }
    }

    int Pop()
    {
        if(this->isEmpty())
        {
            cout << "Stack Underflow!" << endl;
        }
        else
        {
            return stackAra[top--];
        }
    }

    int Top()
    {
        if(this->isEmpty())
        {
            cout << "Stack Underflow!" << endl;
        }
        else
        {
            return stackAra[top];
        }
    }

    bool isEmpty()
    {
        if(top < 0)
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
        if(top >= defaultSize-1)
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
    stack test;

    for(int i = 1; i <= 20; i++)
    {
        test.Push((i*3)+4);
    }

    for(int i = 1; i <= 20; i++)
    {
        cout << test.Pop() << endl;
    }

    test.Pop();
    test.Top();

    if(test.isEmpty())
    {
        cout << "Stack Empty" << endl;
    }

    for(int i = 1; i <= 100; i++)
    {
        test.Push(i);
    }

    test.Push(10);
    cout << test.Top() << endl;

    if(test.isFull())
    {
        cout << "Stack Full" << endl;
    }

    return 0;
}
