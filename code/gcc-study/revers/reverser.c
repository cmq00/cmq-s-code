#include <stdio.h>
#include <string.h>

int main(void) {

    char buf[100] = "ABCDEF";
    char tmp;
    int i;
    
    int len = strlen(buf);

    printf("old:%s\n", buf);

    for (i = 0; i < len/2;i++){
        tmp  = buf[i]; 
        buf[i] = buf[len - i - 1];
        buf[len - i - 1] = tmp;

        printf("%d->%d, %s\n", i, len -i - 1, buf);
    }

    printf("%s\n",buf);
    return 0;

}
