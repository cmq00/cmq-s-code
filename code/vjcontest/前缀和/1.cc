#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int r,y,d=0,B=0,A=0;
int x=0,n=0,s=0;
int ct[1000];
int nd[1000][10];
int asn[10];

struct minx
    {  int tis;
       int minx;
    }  stu[1000];

int cmp(const minx &x1,const minx &x2)
{   
    return x1.minx<x2.minx;
}
int main()
{   int T=0;
    scanf("%d",&T);
    int G=T;
    while(T--){
    scanf("%d",&s);
    int d=0;
    for(;d<s;d++)
    {
        scanf("%d",&ct[d]);
        for(int i=0;i<ct[d];i++)
        scanf("%d",&nd[d][i]);
    }
    for(int y=0;y<s;y++)
    {
        r=ct[y];
        x=nd[y][0]+1;
        A=x;
        for(int j=1;j<r;j++)
        {
            while(A<nd[y][j]){x++;A++;}
            A++;
        }
        stu[y].tis=r;
        stu[y].minx=x;
    }
        sort(stu,stu+s,cmp);
        x=stu[0].minx;
        B=x+stu[0].tis;
        for(int j=1;j<s;j++)
        {   
            while(B<stu[j].minx){x++;B++;}
            B=B+stu[j].tis;
        }
        asn[T]=x;
    }
       for(int i=G-1;i>=0;i--)
       printf("%d\n",asn[i]);
    return 0;
}