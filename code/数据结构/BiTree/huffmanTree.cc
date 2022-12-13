#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

typedef char TElemType;
typedef int Status;

typedef struct huffmanTree
{
    int weight;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;

typedef char **HuffmanCode;

void Select(HuffmanTree &HT,int n,int &s1,int &s2)
{
    int pos;
    int inf = 0x3fffffff;
    for(int i = 1;i <= n;++i){
        if(HT[i].parent == 0 && HT[i].weight < inf){
            pos = i;
            inf = HT[i].weight;
        }
    }
    s1 = pos;
    inf = 0x3fffffff;
    for(int i = 1;i <= n;++i){
        if(HT[i].parent == 0 && HT[i].weight < inf && i != s1){
            pos = i;
            inf = HT[i].weight;
        }
    }
    s2 = pos;
}

void CreatHuff(HuffmanTree &HT,int *w,int n)
{
    int m = 2 * n - 1;//总结点数；
    HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
    for(int i = 1;i <= n;++i){
        HT[i].weight = w[i - 1];
    }
    for(int i = n + 1;i <= m;++i){
        int s1,s2;
        Select(HT,i - 1,s1,s2);
        //cout << s1 << " " << s2 << endl;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
    }
}

void HuffCoding(HuffmanTree &HT,HuffmanCode &HC,int n)
{
    HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
    char *cd = (char*)malloc(n * sizeof(char*));
    cd[n - 1] = '\0';
    for(int i = 1;i <= n;++i){
        int start = n - 1;
        for(int c = i,f = HT[i].parent;f != 0;c = f,f = HT[f].parent){
            if(HT[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        HC[i] = (char*)malloc((n - start) * sizeof(char));
        strcpy(HC[i],&cd[start]);
    }
    free(cd);
}   

int main()
{
    int n;
    puts("输入数据个数:");
    cin >> n;
    int *w = (int*)malloc(n * sizeof(int));
    puts("输入数据:");
    for(int i = 0;i < n;++i){
        cin >> w[i];
    }
    puts("");
    HuffmanTree HT;
    CreatHuff(HT,w,n);

    HuffmanCode HC;
    HuffCoding(HT,HC,n);

    for(int i = 1;i <= n;++i){
        printf("%d的编码为: %s\n",HT[i].weight,HC[i]);
    }
    return 0;
}