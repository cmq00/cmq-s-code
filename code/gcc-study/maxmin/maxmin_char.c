#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {

    int i, num;
    char buf[21][5];

    num = sizeof(buf) / sizeof(buf[0]);

    
    for (i = 0; i < num; i ++) {
        sprintf(buf[i], "AB%02d",i);
    }

    for (i = 0; i < num; i ++) {
        printf("%s ", buf[i]);
    }
    printf("\n");
    char max[5], min[5];
    strcpy(max, buf[0]);
    strcpy(min, buf[0]);

    for (i = num % 2; i < num; i+=2)  {

        #ifdef DEBUG
        printf("max:%d->buf[i]:%d, i:%d\n", max, buf[i], i);
        #endif
        if (strcmp(buf[i] ,  buf[i + 1])> 0) {
            if (strcmp(buf[i] , max) > 0)
                strcpy(max , buf[i]);
            if (strcmp(buf[i + 1] , min) <0)
                strcpy(min , buf[i+1]);

        }else {
            if (strcmp(buf[i + 1] , max) > 0)
                strcpy(max , buf[i + 1]);
            if (strcmp(buf[i] , min) < 0)
                strcpy(min , buf[i]);
                
        }
    }
    printf("max=%s, min=%s\n",max,min);
    return 0;
}
