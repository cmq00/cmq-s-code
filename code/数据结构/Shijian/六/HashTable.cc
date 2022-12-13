#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 1004

typedef struct
{
    int elem[MAXSIZE];
    int cnt;
    int sizeindex;
}HashTable;

void Init(HashTable &H)
{
    memset(H.elem,0,MAXSIZE);
    H.sizeindex = 0;
}

int Hash(int n,int p)
{
    return n % p;
}

int InsertHash(HashTable &H,int key,int p)
{
    int k,d = 0;
    k = Hash(key + d,p);
    while(H.sizeindex != MAXSIZE){
        if(!H.elem[k]){
            H.elem[k] = key;
            H.sizeindex++;
            return 1;
        }
        else{
            d++;
            k = Hash(key + d,p);
        }
    }
    return 0;
}

int FindHash(HashTable H,int key,int p)
{
    int k,d = 0;
    k = Hash(key + d,p);
    while(H.sizeindex){
        if(!H.elem[k])
            return -1;
        else if(H.elem[k] == key)
            return k;
        else{
            d++;
            k = Hash(key + d,p);
        }
    }
    return -1;
}

int main()
{
    HashTable H;
    Init(H);
    int n,p;
    puts("输入数据个数和p：");
    cin >> n >> p;
    puts("输入数据：");
    for(int i = 1;i <= n;++i){
        int x;
        cin >> x;
        InsertHash(H,x,p); 
    }
    puts("输入要查找的数：");
    int x;
    while(~scanf("%d",&x)){
        cout << "该数所在的位置为：";
        cout << FindHash(H,x,p) << endl;
    }
    return 0;
}