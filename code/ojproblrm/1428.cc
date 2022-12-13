#include <bits/stdc++.h>

using namespace std;

const int N = 1e9 + 10;

int main()
{
    string a,b,c,d;
    while(cin >> a){
        cin >> b;
        cout << a << endl << b << endl;
        int la = a.size();
        int lb = b.size();
        //cout << la << " " << lb << endl;
        //cout << a[la - 1] << "sd" << endl;
        int k = 0;
        if(la < lb){     
            for(int i = la - 1,j = 0;i >= 0;--i,++j){
               cout <<"a "<<a[i]<<" b " <<b[j]<<endl;
                d[j] = int(a[i] + b[j]);
              //cout << d[j] << endl;;
            }
        }
        cout << d << endl;
        for(int i = la;i < lb;++i)
            cout << b[i];
        cout << d << endl;

    }
    return 0;

}
