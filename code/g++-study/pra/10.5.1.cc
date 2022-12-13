#include <stack>
#include <iostream>

using namespace std;

int main()
{
    stack<int> stk;
    int n,k;
    while(cin >> n >> k)
    {
        while(n)
        {
            stk.push(n % k);
            n /= k;
        }

        while(!stk.empty())
        {
            cout << stk.top();
            stk.pop();
        }
        cout << endl;
    }
    return 0;
}
