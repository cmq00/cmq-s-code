#include <bits/stdc++.h>
#define pi 3.14

using namespace std;

class cr
{
    public:
        double r;
        void init(double rr);
        double area();
        double price1();
        double price2();
};

void cr::init(double rr)
{
    r = rr;
}

double cr::price1()
{
    return (r + 3) * 2 * pi * 15;
}

double cr::price2()
{
    return pi * ((r + 3) * (r + 3) - r * r) * 30;
}

double cr::area()
{
    return pi * r * r;
}

int main()
{
    int r;
    cr R;
    while(cin >> r){
        R.init(r);
        double ans1 = R.price1();
        double ans2 =  R.price2();
        double ans3 = R.area();
        printf("%.2f\n%.2f\n%.2f\n",ans1,ans2,ans3);
    }
    return 0;
}
