#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    vector<string> v;
    v[1] = "16",v[2] = "18",v[3] = "22",v[4] = "26",v[5] = "28",v[6] = "68",v[7] = "88";
    //s8 = "16",s9 = "18",s10 = "22",s11 = "26",s12 = "28",s13 = "68",s14 = "88";
    //char a[][] = {};
    while(t--){
        int n;
        scanf("%d",&n);
        if(n == 2) cout << "1" << endl;
        else if(n == 3) cout << "7" << endl;
        else if(n == 4) cout << "4" << endl;
        else if(n == 5) cout << "2" << endl;
        else if(n == 6) cout << "6" << endl;
        else if(n == 7) cout << "8" << endl;
        else if(n % 7 == 0){
            for(int i = 1;i <= n / 7;++i)
                cout << "8";
            cout << endl;
        }
        else{
            int a = n % 7;
            int b = n / 7;
            cout << v[a];
            for(int i = 1;i <  b;++i)
                cout << "8";
            cout << endl;
        }
    }
    return 0;
}