#include <bits/stdc++.h>
using namespace std;
class Complex
{
  public:
    Complex (double x = 0 ,double y = 0):real(x),imag(y){}
    Complex operator + (Complex & c2);
    Complex operator - (Complex & c2);
    friend Complex operator * (Complex &c1,Complex & c2);
    void print();
 private:
    double real;
    double imag;
};
Complex Complex::operator + (Complex &c2)
{
  return Complex(c2.real + real,c2.imag + imag);
}
Complex Complex::operator - (Complex &c2)
{
  return Complex(real- c2.real, imag- c2.imag);
}
Complex operator * (Complex &c1,Complex &c2)
{
  return Complex (c1.real * c2.real - c1.imag * c2.imag,c1.real * c2.imag + c1.imag * c2.real);
}
void Complex::print()
{
  printf("(%.2f,%.2f)\n",real,imag);
}
int main()
{
  double a,b,c,d;
  while(cin >> a >> b >> c >> d){
    Complex c1(a,b);
    Complex c2(c,d);
    Complex c3 = c1 + c2;
    c3.print();
    c3 = c1 - c2;
    c3.print();
    c3 = c1 * c2;
    c3.print();
  }
  return 0;
}
