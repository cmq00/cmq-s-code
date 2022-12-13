#include <stdio.h>

int main()
{
    int i = 0;
    i = i | (1 << 15);
    i = i | (1 << 16);
    printf("%d\n",i);
    printf("%d\n",i & (1 << 17));
    return 0;
}
