#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e4 + 4;
bool isPrime[N];

void aiPrime(int n)
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[1] = isPrime[0] = false;
    for(ll i = 2;i <= n;++i){
        if(isPrime[i]){
            for(ll j = i;j * i <= n;++j)
                isPrime[j * i] = false;
        }
    }
}

int main()
{
    int t,n;
    scanf("%d",&t);
    aiPrime(N - 2);
    /*bool isPrime[N];
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2;i < N;++i){
        if(isPrime[i]){
            for(ll j = i * i;j < N;j += i){
                isPrime[i * j] = false;
            }
        }
    }*/
    while(t--){
        scanf("%d",&n);
        if(isPrime[n])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}