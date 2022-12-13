#include <iostream>

using namespace std;

class CD{
    public:
        ~CD()
        {
            cout << "d called" << endl;
        }
};

int main()
{
    CD array[2];
    CD* p = new CD;
    delete p;
    cout << "-------------" << endl;
    p = new CD[2];
    delete [] p;
    cout << "main ends" << endl;
    return 0;
}
