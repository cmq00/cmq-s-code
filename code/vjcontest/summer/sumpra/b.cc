#include <bits/stdc++.h>//jkhgvjhjgfjhf
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;
string s;
int cnt,cnt1;
int len;
vector<int> pos;

bool check(int mid)
{
   int k = pos.size();
   int x = k - mid;
   for(int i = 0;i < mid + 1;i++){
        if(pos[i + x - 1] - pos[i] + 1 - x <= mid)
            return 1;
   }
   return 0;
}

void solve()
{
    pos.clear();
    cnt = 0,cnt1 = 0;
    cin >> s;
    len = s.size();
    for(int i = 0;i < len;++i){
        if(s[i] == '0')
            cnt++;
        else{
            cnt1++;
            pos.push_back(i);
        }
    }
    if(cnt == 0 || cnt1 == len || cnt == len){
        puts("0");
        return ;
    }
    int l = 0,r = cnt1,mid;
    while(l < r){
         mid = (r + l) >> 1;
        //cout << l << " " << r << " " << mid << endl;
        if(check(mid)) 
            r = mid;
        else
            l = mid + 1;
    }
    //cout << l << " " << r << " " << mid << endl;
    cout << l << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}