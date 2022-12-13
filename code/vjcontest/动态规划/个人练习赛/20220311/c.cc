#include <bits/stdc++.h>
#define ll long long
#define ms(a) memset(a,0,sizeof(a))

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int a,b,q;
        cin >> a >> b >> q;
        if(a == b){
            for(int i = 1; i <= q;++i)
                cout << "0" << " ";
            return 0;
        }
        while(q--){
            int l,r;
            cin >> l >> r;
            if(max(l,r) <= min(a,b)
                cout << "0" << " ";
            else{
                
            }
        }   
    }

}
