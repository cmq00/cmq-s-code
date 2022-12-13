#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    int n;
    cin >> n;
   
    int m = n;
    char s1[1004],s2[1004];
    scanf("%s",s1 + 1);
    scanf("%s",s2 + 1);
     if(n == 1){
        if(s1[1] == s2[1])
            puts("0");
        else
            puts("1 1");
        return ;
    }
    // cout << s1 << endl;
    // cout << s2 << endl;
    vector<int> v;
    int cnt = 0;
    for(int i = n;i >= 1;--i){
        // cout << "i: " << i << endl;
        // cout << s1[i] << " " << s2[i] << endl;
        if(s1[i] == s2[i])
            continue;
        else{
            //cout << s1[0] << " " << s2[0] << endl;
            if(s1[1] == s2[i]){ 
                cnt += 2;
                v.push_back(1);
                if(s1[1] == '0')
                    s1[1] = '1';
                else
                    s1[1] = '0';
                v.push_back(i);
                for(int j = 1,k = i;j <= k;++j,--k){
                    if(s1[j] == s1[k]){
                        if(s1[j] == '0')
                            s1[j] = '1',s1[k] = '1';
                        else    
                            s1[j] = '0',s1[k] = '0';     
                    }
                }
                //cout << s1 << endl;
            }
            else{
                cnt++;
                v.push_back(i);
                for(int j = 1,k = i;j <= k;++j,--k){
                    if(s1[j] == s1[k]){
                        if(s1[j] == '0')
                            s1[j] = '1',s1[k] = '1';
                        else    
                            s1[j] = '0',s1[k] = '0';    
                    } 
                }
            }
             //cout << s1 << endl;      
        }
    }
    // if(s1[1] != s2[1]){
    //     v.push_back(1);
    //     cnt++;
    // }
    cout << cnt << " ";
    for(int i = 0;i < v.size();++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}