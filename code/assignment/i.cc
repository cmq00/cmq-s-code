#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--){
    int m,n;
    cin>>m>>n;
    int s[105][105],f[105];
    memset(s,0,sizeof(s)); 
  for(int i=1;i<=m;i++)
  {
   int c;
   cin>>c;
   s[i][c]=1;
   f[i]=c;
  }
  for(int b=1;b<=n;b++)
  {
  int x1,x2,y1,y2;
  cin>>x1>>y1>>x2>>y2;
  int t;
  t=0;
  for(int j=y1;j<=y2;j++)
  {
   for(int n=x1;n<=x2;n++)
   {
    if(s[n][j]==1)
    {
     //for(int l=x1;l<=x2;l++)
     //{
     // s[l][n]=0; 
   t++;
   break;
     //}
    }
   }
  }
  cout<<t<<endl; 
  //for(int i=1;i<=m;i++)
  //{
   //s[i][f[i]]=1;
  //}
 }
}
}