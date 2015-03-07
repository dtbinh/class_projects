#include <iostream>
using namespace std;

class myVector
{
private:
    int* arr;
    int count;
public:
    myVector(int = 5);
};

myVector::myVector(int size)
{
    int numElements = 0;
    cout << "please enter the number of elements"
    cin >> numElements;
    count = size;
    arr = new int[count];
}

int main(void)
{
    myVector a(10), b(2), c;
    cin >> a;
    cin >> b;
    cout << a;
    cout << b;
    c = a+b;
    cout << c;
    return 0;
}