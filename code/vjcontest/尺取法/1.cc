#include<stdio.h>
int main()
{
 int m,n,t,i,j,x;
 int a[1001][800];
 scanf("%d%d",&m,&n);
 int maxx;
 for(i=1;i<=m;i++){
   for(j=1;j<=n;j++){
    scanf("%d",&a[i][j]);
    if(a[i][j] >= maxx) maxx = a[i][j];
   }
 }
 /*t=a[1][1];
  for(i=1;i<=m;i++)
   for(j=1;j<=n;j++)
    if(a[i+1][j]>=a[i][j]&&a[i+1][j]>=a[i+2][j]&&a[i+1][j]>=t)
     t=a[i+1][j];*/

 x=0;
  for(i=1;i<=m;i++)
   for(j=1;j<=n;j++)
    if(a[i][j]==maxx)
     x=x+i+j;
 printf("%d\n",x);
    return 0;
}