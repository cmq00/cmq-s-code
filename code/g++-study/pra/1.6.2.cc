#include <iostream>
using namespace std;

int n = 4;

int &f(){
    return n;
}

int main()
{
    f() = 40;
    cout << n << endl;
    int &r = f();
    cout << r << endl;
    return 0;
}
