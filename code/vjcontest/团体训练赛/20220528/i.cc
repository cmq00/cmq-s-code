#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
#define inf 1e8
const int N=1e9;
#define endl "\n"
string s;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    cin>>s;
    s='1'+s;
    while(q--)
    {
        int l,r,flag=1;
        cin>>l>>r;
        int i=l,j=r;
        while(i<=j)
        {
            if(s[i]!=s[j]){
                flag=0;
                break;
            }
            i++,j--;
        }
        if(!flag){
            if((l-r+1)&1){
                cout<<"Putata"<<endl;
            }
            else{
                cout<<"Budada"<<endl;
            }
        }
        else{
            cout<<"Budada"<<endl;
        }
    }
    return 0;
}