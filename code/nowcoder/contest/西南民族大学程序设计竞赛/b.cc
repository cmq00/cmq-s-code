#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 1e5 + 10;
int t,i,j;
int n,m;
ll u,v,w;
ll dis[maxn];

struct node
{
    ll v,w;
    bool operator < (const node &a) const {
        return a.w < w;
    }
};


