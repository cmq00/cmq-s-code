#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int day[13] = {0,31,0,31,30,31,30,31,31,30,31,30,31};

bool check(int year)
{
	if((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0))
        return 0;
	else
        return 1;
}

void solve()
{
    int y1,m1,d1;
    int y2,m2,d2;
    cin >> y1 >> m1 >> d1;
    cin >> y2 >> m2 >> d2;
    int ans = 0;
    for(int i = y1;i < y2;++i){
        if(check(i))
            ans += 366;
        else
            ans += 365;
    }
    if(check(y2))
        day[2] = 29;
    else
        day[2] = 28; 
    // for(int i = 1;i <= 12;++i)
    //     cout << day[i] << " ";
    // cout << endl;
    int res1 = 0,res2 = 0;
    for(int i = 1;i < m1;++i)
        res1 += day[i];
    res1 += d1;
    for(int i = 1;i < m2;++i)
        res2 += day[i];
    res2 += d2;
    ans = ans + res2 - res1;
    cout << ans << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}