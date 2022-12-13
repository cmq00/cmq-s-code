#include <iostream>

using namespace std;

class com{
    public:
        double real,imag;
        com(double r,double i){
            real = r;
            imag = i;
        }
        com(const com & c){
            real = 2 * c.real;
            imag = 2 * c.imag;
            cout << "copy construct called" << endl;
        }
};

int main()
{
    com c1(1,2);
    com c2(c1);
    cout << c2.real <<","<< c2.imag << endl;
    return 0;
}
