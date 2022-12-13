#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1,s2;
    int n;

    getline(cin,s1);
    //char p = getchar();
    getline(cin,s2);
    cin >> n;

    s1.insert(n - 1,s2);
    cout << s1;
    return 0;
}

