#include <bits/stdc++.h>
using namespace std;
string f(long long n)
{
    if (n == 1)
        return "2";
    //string s;
    if (n % 2 == 1)
        return "(2*" + f(n - 1) + ")";
    else
        return "(" + f(n / 2) + ")^2";
}
int t;
long long n;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        cout << f(n) << endl;
    }
    return 0;
}


