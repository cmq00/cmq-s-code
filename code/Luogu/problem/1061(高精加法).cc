#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[10000],b[100000],c[100000];
    char aa[100000],bb[100000];
    
    scanf("%s",aa);
    scanf("%s",bb);
    int la = strlen(aa) - 1,lb = strlen(bb) - 1;
    //printf("la:%d lb:%d\n",la,lb);
    
    for(int i = la,k = 0;i >= 0;--i,++k){
        a[k] = aa[i] - '0'; 
        //printf("a[%d]:%d aa[%d]:%d\n",k,a[k],i,aa[i] - '0');
    }

    for(int i = lb,k = 0;i >= 0;--i,k++){
        b[k] = bb[i] - '0';
        //printf("b[%d]:%d bb[%d]:%d\n",k,b[k],i,bb[i] - '0');
    }
    
    int len = max(la,lb),p = 0;;
    for(int i = 0;i <= len;++i){
        c[i] = a[i] + b[i] + p;
        if(c[i] >= 10){
            c[i] = c[i] % 10;
            p = 1;
        }
        else   
            p = 0;
    }
    cout << "p:" << p << endl;\
    c[len + 1] = p;
    if(p != 1)
        len -= 1;
    for(int i = len + 1;i >= 0;--i)
        printf("%d",c[i]);
    printf("\n");
    /*for(int i = 0;i <= la;++i)
        printf("%d",a[i]);
    printf("\n");
      for(int i = 0;i <= lb;++i)
        printf("%d",b[i]);
    printf("\n");*/
    return 0;
}