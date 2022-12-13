#include <iostream>

using namespace std;

void swap(int &a,int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
    cout << a <<" " <<  b <<endl;
}

int main()
{
    int a = 4,b = 5;
    swap(a,b);
    cout << a << " " << b << endl;


    return 0;
}
