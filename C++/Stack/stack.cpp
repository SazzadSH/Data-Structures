#include <iostream>

using namespace std;

#define defaultSize 100

class stack
{
    static int maxSize;
    stack()
    {
        maxSize = defaultSize;
    }

    stack(int customSize)
    {
        maxSize = customSize;
    }

    int stackAra[defaultSize];
};

int main()
{
   // int ara[maxSize];
    return 0;
}
