#include <stdio.h>

int main()
{
    int a,b,c;
    c = 1000 - a - b;
    for(a = 1;a <= 998;a++){
        for(b = 1;b <= 1000;b++){
            c = 1000 - a - b;
            if( a * a + b * b == c * c)
                printf("%d,%d,%d\n",a,b,c);
        }
    }

    printf("\n");
    return 0;
}
