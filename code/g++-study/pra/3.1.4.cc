#include <iostream>

using namespace std;

class com{
    public:
        double real,imag;
        com(int i){
            cout << "haha" <<endl;
            real = i,imag = 0;
        }   
        com(double r,double i){
            cout << "ha" <<endl;
            real = r;imag = i;
        }
};

int main(){
    com c1(7,8);
    cout << c1.real << " " << c1.imag << endl;
    c1 = 9;
    cout << c1.real << " " << c1.imag << endl;
    com c2 = 12;
    cout << c2.real << " " << c2.imag << endl;
    return 0;
}
