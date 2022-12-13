#include <iostream>

using namespace std;

class cr
{
    public:
        int w,h;
        void init(int w_,int h_);
        int area();
        int peri();
};

void cr::init(int w_,int h_)
{
    w = w_;
    h = h_;
}
int cr::area()
{
    return w * h;
}

int cr::peri()
{
    return 2 * (w + h);
}

int main()
{
    int w,h;
    cr r;
    cin >> w >> h;
    r.init(w,h);
    cout << r.area() << endl;
    cout << r.peri() << endl;
    return 0;
}

