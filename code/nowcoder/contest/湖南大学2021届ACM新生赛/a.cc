#include <bits/stdc++.h>

using namespace std;

int coin[41];
string result;
int Left[4][14] = {1,2,7,8,13,14,19,20,25,26,31,32,37,38,
                0,3,6,11,13,14,16,21,24,29,31,32,34,39,
                5,7,9,11,13,14,16,18,20,22,33,35,37,39,
                0,15,17,19,21,23,25,27,29,31,33,35,37,39};

int Right[4][14] = {0,4,5,10,11,16,17,22,23,28,29,34,35,40,
                    2,4,5,7,12,15,20,22,23,25,30,33,38,40,
                    0,6,8,10,12,15,17,19,21,32,34,36,38,40,
                    14,16,18,20,22,24,26,28,30,32,34,36,38,40};

bool balance()
{
    int l,r,i,k;
    for(i = 0;i < 4;++i){
        l = r = 0;
        for(k = 0;k < 14;++k){
            l += coin[Left[i][k]];
            r += coin[Right[i][k]];
        }
        if(l > r && result[i] != '>')
            return 0;
        if(l == r && result[i] != '=')
            return 0;
        if(l < r && result[i] != '<')
            return 0;
    }
    return 1;
}

int main()
{
    while(cin >> result){
        int i;
        for(i = 0;i < 41;++i){
            coin[i] = 0;
        }
        for(i = 1;i < 41;++i){
            coin[i] = 1;
            if(balance())
                break;
            coin[i] = -1;
            if(balance())
                break;
            coin[i] = 0;
        }
        printf("%d %s\n",i,coin[i] > 0 ? "heavy":"light");
    }
    return 0;
   
}