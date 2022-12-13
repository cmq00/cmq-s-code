#include <iostream>

using namespace std;

class com{
    public:
        double real,imag;
        com(double r = 0.0,double i = 0.0):real(r),imag(i){  }
        com operator - (const com & c);
};

com operator + (const com & a,const com & b)
{
    return com(a.real + b.real,a.imag + b.imag);
}

com com::operator - (const com & c)
{
    return com(real - c.real,imag - c.imag);
}

int main()
{
    com a(4,4),b(1,1);
    com c = a + b;
    cout << c.real << "," << c.imag << endl;
    cout << (a - b).real << "," << (a - b).imag << endl;
    return 0;
}
