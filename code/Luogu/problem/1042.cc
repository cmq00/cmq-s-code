#include <bits/stdc++.h>

using namespace std;

int main()
{
    char arr[62510];
    while(~scanf("%s",arr)){
    int a = 0,b = 0,cont = 0;
    for(int i = 0;arr[i] != 'E';++i){
        if(arr[i] == 'W') a++;
        else if(arr[i] == 'L') b++;
        cont++;
        if((a >= 11 || b >= 11) && (a - b) >= 2 || (b - a) >= 2){
            printf("%d:%d\n",a,b);
            cont = 0;
            a = 0,b = 0;
        }
        if(arr[i + 1] == 'E'){
            printf("%d:%d\n",a,b);
            cont = 0;
            a = 0,b = 0;
        }
    }
    printf("\n");
    for(int i = 0;arr[i] != 'E';++i){
        if(arr[i] == 'W') a++;
        else if(arr[i] == 'L') b++;
        cont++;
        if((a >= 21 || b >= 21) && (a - b) >= 2 || (b - a) >= 2){
            printf("%d:%d\n",a,b);
            cont = 0;
            a = 0,b = 0;
        }
        if(arr[i + 1] == 'E'){
            printf("%d:%d\n",a,b);
            cont = 0;
            a = 0,b = 0;
        }
    }
    }
    return 0;
}