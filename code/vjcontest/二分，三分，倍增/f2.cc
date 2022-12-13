/*
 * @author: arc
 * @date: 2020-08-15 18:56:28
 */
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 5e4+5;

int stmax[maxn][20], stmin[maxn][20];

void build(int n) {
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);
            stmin[i][j] = min(stmin[i][j - 1], stmin[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) {
    int k = log2(r - l + 1);
    return (max(stmax[l][k], stmax[r - (1 << k) + 1][k]) - min(stmin[l][k], stmin[r - (1 << k) + 1][k]));
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &stmax[i][0]);
        stmin[i][0] = stmax[i][0];
    }
    build(n);
    int l, r;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }
    return 0;
}