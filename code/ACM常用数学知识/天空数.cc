/*Description
曾经有一位学长非常喜欢打acm，而且很擅长数学。
传说有一天他发现了一种神奇的数对，即这两个数的乘积是一个完全平方数，于是把这样的两个数命名为一对天空数。
即对于任意的正整数x,y，如果x*y是一个完全平方数，那么称x,y是一对天空数。
现在这个学长给大家留下了一个问题：一个给定的序列中存在多少对天空数？
Input
第一行输入一个正整数T，表示输入数据的组数。
对于每组数据，第一行一个正整数n
接下来一行n个用空格隔开的正整数，表示序列。第
个数表示ai
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 4;
int a[N + 4],v[N + 4],p[N + 4],c[N + 4];

/*struct Node
{
    int pow;
};*/

vector<int> num[N];

void init()
{   
    int m = 0;
    for(int i = 2;i <= N;++i){
        if(v[i] == 0){
            v[i] = i;
            p[++m] = i;
            num[i][i] = 1;
        }
        for(int j = 1;j <= m;++j){
            if(p[j] > v[i] || p[j] > N / i) break;
            v[i * p[j]] = p[j];
            if(v[i] == p[j])
                num[i * p[j]][i] = num[i][p[j]] + 1;
            else{
                num[i * p[j]][i] = num[p[j]][p[j]];
                num[i * p[j]][p[j]] = num[p[j]][p[j]];
            }
        }
    }
}

int main()
{

    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;++i){
        scanf("%d",&a[i]);
    init();


}



