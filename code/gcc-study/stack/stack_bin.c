#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    struct STACK stack;
    int num = atoi(argv[1]), base = atoi(argv[2]);
    char *pop,mod;
    
    printf("%d\n",num);
    init_stack(&stack,100,sizeof(char));
    do{
        if(num % base < 10)
             mod =( num % base) +'0';
        else
            mod = (num % base) + 55;
        num =( int)(num / base);
        push_stack(&stack,&mod);
    }while(num!=0);
    while(!empty_stack(&stack)){
        pop =  pop_stack(&stack);
        printf("%c",*pop);
    }
    printf("\n");
    return 0;
}
