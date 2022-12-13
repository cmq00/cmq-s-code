    #include<stdio.h>
#include<string.h>
int main(void)
{
    int n,m,i,h;
    char t[100],s[50],a[100];
    char temp;
    gets(t);
    gets(s);
    scanf("%d",&h);
    m=strlen(s);
    //l=strlen(t);
    //printf("%d\n",m);
    n=h-1;
    for(i=n;t[i]!='\0';i++)
    {
        a[i-n]=t[i];
    }
    printf("%s\n",t);
    for(i=0;i<m;i++)
    {
        t[n]=s[i];
        n++;
    }
    for(i=0;a[i]!='\0';i++)
    {
        t[n+m]=a[i];
        n++;
    }
    printf("%s",t);
    return 0;
}
