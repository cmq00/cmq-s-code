#include <stdio.h>
#include <string.h>
#include "stack.h"


int main()
{   
    struct STACK stack;
    char exp[100] = "((1+2) * 3";

    int len = strlen(exp);
    int seq;
    char *op;

    init_stack(&stack,100,sizeof(char));
    printf("%s\n",exp);
    for (seq = 0; seq < len; seq ++) {
        if (exp[seq] == '(') {
            push_stack(&stack,exp+seq);
        } else if (exp[seq] == ')') {
            if (empty_stack(&stack)) { 
                printf("error ')'.\n");
            }else{
                op = pop_stack(&stack);
            }
        }
    }
    if (!empty_stack(&stack)) {
        printf("error '('.\n");
    } else {
        printf("ok.\n");
    }
}    
