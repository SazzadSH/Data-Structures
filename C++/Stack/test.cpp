#include <iostream>

using namespace std;

int m = 12;

class test
{
public:

    int m = 11;

    test()
    {
        cout << m << endl;
    }

    test(int data)
    {
        m = data;
        cout << m << endl;
    }

    void print()
    {
        cout << m << endl;
    }
};

int main()
{
    test t1(5);

    t1.print();

    cout << m << endl;
}
