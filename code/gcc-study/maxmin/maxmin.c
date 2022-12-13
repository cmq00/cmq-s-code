#include <stdlib.h>
#include <stdio.h>

int main(void) {

    int i, num, numbers[20];

    num = sizeof(numbers) / sizeof(numbers[0]);
    
    for (i = 0; i < num; i ++) {
        numbers[i] = random() % 100;

    }

    for (i = 0; i < num; i ++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int max, min;
    max = min = numbers[0];
    for (i = 1; i < num; i++)  {

        #ifdef DEBUG
        printf("max:%d->numbers[i]:%d, i:%d\n", max, numbers[i], i);
        #endif
        if (numbers[i] > max)
            max=numbers[i];
        else if(numbers[i] < min)
            min = numbers[i];
    }
    printf("max=%d, min=%d\n",max,min);
    return 0;
}
