#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 4;// N = 串的数量 + 串的长度

int nex[N][26],cnt;//nex[i][j]表示结点i指向的下一个结点，cnt表示结点的数量
int exi[N];//记录一个字符串的结束

void putin(char* s)
{
    int len = strlen(s),p = 0;//p表示当前结点
    for(int i = 0;i < len;++i){
        int c = s[i] - 'a';
        if(!nex[p][c]) nex[p][c] = ++cnt;//如果没有该字符，创建一个新结点
        p = nex[p][c];
    }
    exi[p] = 1;
}

int query(char* s)
{
    int len = strlen(s),p = 0;
    for(int i = 0;i < len;++i){
        int c = s[i] - 'a';
        if(!nex[p][c])  return 0;
        p = nex[p][c];
    }
    if(exi[p] == 1){
        exi[p] = 2;
        //printf("exi[%d]:%d\n",p,exi[p]);
        return 1;
    }
    return exi[p];
}

int main()
{
    int n,m;
    scanf("%d",&n);

    char s[55];
    while(n--){
        scanf("%s",s);
        putin(s);
    }

    scanf("%d",&m);
    while(m--){
        scanf("%s",s);
        int res = query(s);
        //printf("%d\n",res);
        if(res == 0)
            puts("WRONG");
        else if(res == 1)
            puts("OK");
        else    
            puts("REPEAT");
    }
    return 0;
}
