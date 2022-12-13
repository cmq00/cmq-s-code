#include <bits/stdc++.h>

using namespace std;

int main()
{
    int year;
    cin >> year;
    int p;
    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0)
                p = 1;
            else
             p = 0;
        }
        else
            p = 0;
    }
    else
        p = 0;
    if(p == 1)
        cout << "Y" << endl;
    else
        cout << "N" << endl;
    return 0;
}
        
        
