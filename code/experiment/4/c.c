#include <stdio.h>

int check(int a,int b,int c)
{
    int ans;
    if(a + b > c && a + c > b && b + c > a){
        if(a == b && b == c)
            ans = 3;
        else if(((a == b) && (b != c)) || ((b == c) && (c != a)) || ((a == c) && (c != b)))
            ans = 2;
        else
            ans = 1;
    }
    else
        ans = 0;
    return ans;
}

int main()
{
    int a,b,c,ans;
    scanf("%d %d %d",&a,&b,&c);
    ans = check(a,b,c);
    //printf("Input a,b,c:\n");
    printf("a=%d,b=%d,c=%d\n",a,b,c);
    printf("The shape:%d\n",ans);
    return 0;
}
    
        
            
    
