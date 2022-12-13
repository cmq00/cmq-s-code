#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
    if(n % 7 == 0)
        cout << n << endl;
    else{
        if(n < 100){
            int a = n / 10,b = n % 10;
            for(int i = 1;i <= 9;++i){
                if((i * 10 + b) % 7 == 0)
                    {cout << i * 10 + b << endl;break;}
                if((a * 10 + i) % 7 == 0)
                    {cout << a * 10 + i << endl;break;}
            }
        }
        if(n >= 100){
            int a = n / 100,b = n / 10 % 10,c = n % 10;
            for(int i = 1;i <= 9;++i){
                if((i * 100 + b * 10 + c) % 7 ==0)
                    {cout << i * 100 + b * 10 + c << endl;break;}
                if((a * 100 + i * 10 + c) % 7 == 0)
                    {cout << a * 100 + i * 10 + c << endl;break;}
                if((a * 100 + b * 10 + i) % 7 == 0)
                     {cout << a * 100 + b * 10 + i << endl;break;}
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}