#include <iostream>

using namespace std;

class com{
    private:
        double real,imag;
    public:
        com(double r);
        com(double r,double i);
        com(com c1,com c2);
};

com::com(double r)
{
    real = r;imag = 0;
}

com::com(double r,double i)
{
    real = i;imag = i;
}

com::com(com c1,com c2)
{
    real = c1.real + c2.real;
    imag = c1.imag + c2.imag;
}

int main()
{
    com c1(3),c2(1,2),c3(c1,c2),c4 = 7;
    return 0;
}
