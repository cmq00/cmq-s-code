#include <bits/stdc++.h>

using namespace std;

string fun(long long k)
{
    if(k == 1){
        //cout << "s3: " << s3 << "  " << "s4: " << s4 << endl;
        //cout << s3 + s + s4 << endl;
        return "2";
    }
    if(k % 2 == 1)
        return "(2*" + fun(k - 1) + ")";
    else
        return "(" + fun(k / 2) + ")^2";
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        long long n;
        scanf("%lld",&n);
        cout << fun(n) << endl;;
    }
    return 0;
}