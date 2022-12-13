#include <bits/stdc++.h>

using namespace std;

char s1[1004];
char s2[1004];
int len[1004][1004];

int main()
{
    scanf("%s",s1);
    scanf("%s",s2);
    int l1 = strlen(s1);
    int l2 = strlen(s2);

    for(int i = 0;i < l1;++i)
        len[i][0] = 0;
    for(int i = 0;i < l2;++i)
        len[0][i] = 0;
    
    int e1,e2,ll;
    for(int i = 1;i <= l1;++i){
        for(int j = 1;j <= l2;++j){
            if(s1[i - 1] == s2[j - 1]){
                len[i][j] = len[i - 1][j - 1] + 1;
                e1 = i;
                e2 = j;
                ll = len[i][j];
            }
            else{
                len[i][j] = max(len[i - 1][j],len[i][j - 1]);
                e1 = i;
                e2 = j;
                ll = len[i][j];
            }
        }
    }
    //printf("e1: %d e2: %d\n",e1,e2);
    char ans[1004];
    int i = 0;
    while(e1 >= 1 && e2 >= 1){
        if(s1[e1 - 1] == s2[e2 - 1]){
            ans[i++] = s1[e1 - 1];
            //cout << s1[e1 - 1] << " "; 
            e1--;
            e2--;
        }
        else{
            if(len[e1 - 1][e2] > len[e1][e2 - 1])
                e1 -= 1;
            else
                e2 -= 1;
        }
    }
    //for(int j = 0;ans[j] != '\0';++j)
        //cout << ans[j];
    for(int j = ll - 1;j >= 0;--j)
        printf("%c",ans[j]);
    printf("\n");
    return 0;
}