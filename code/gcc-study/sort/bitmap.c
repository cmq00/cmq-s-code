#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/time.h>



int main()
{
    int *num;
    int i,j, k = 0;
    int max = 2000000;
    struct timeval begin, end;

    int count = 20, elm = max / 32 + 1;

    num = calloc(count, 4);
    for(i = 0; i < count; i++){
        num[i] = max - i;
    }

    unsigned int *bitmap = calloc(elm, 4);
    memset(bitmap, 0, elm * 4);

    gettimeofday(&begin, NULL);    
    for(i = 0; i < count; i++){
        bitmap[num[i] / 32] |= (1 << (num[i] % 32));
    }
    for (i = 1999981; i <= 2000000; i++){

            if((bitmap[i / 32] & (1 << (i % 32)))) {
                printf("%d ",i);

            }
    }
    gettimeofday(&end, NULL);    
    printf("\n%ld,%d\n", end.tv_sec - begin.tv_sec, end.tv_usec - begin.tv_usec);
        

    return 0;
}
