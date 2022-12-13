#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e6 + 4;
bool vis[N];

void solve()
{
    int n;
    cin >> n;
    if(n == 1){
        cout << "1" << endl;
        return ;
    }
    if(n == 2){
        cout << "1 2" << endl;
        return ;
    }
    if(n == 3){
        cout << "1 3 2" << endl;
        return ;
    }
    
    if(n % 2 == 0){
        cout << "1" << " " << n / 2 + 1 << " ";
        for(int i = n;;--i){
            cout << i << " ";
            int x = n - i + 2;
            cout << x << " ";
            if(x == n / 2)
                break;
        }
        cout << endl;
    }
    else{
        n -= 1;
        cout << "1" << " " << n / 2 + 1 << " ";
        int cnt = 2;
        for(int i = n;;--i){
            
            cout << i << " ";
            cnt++;
            if(cnt == n / 2)
                cout << n + 1 << " ";
            int x = n - i + 2;
            cout << x << " ";
            cnt++;
            if(cnt == n / 2)
                cout << n + 1 << " ";
            if(x == n / 2)
                break;
            
        }
        cout << endl;
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}