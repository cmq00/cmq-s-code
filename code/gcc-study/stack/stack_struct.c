#include <stdio.h>
#include <string.h>
#include "stack.h"


struct Node {
    char op;
    int cur;
};

int main()
{  
    
    struct STACK stack;
    char exp[100] = "((1+2) * 3";

    int len = strlen(exp);
    int seq;

    struct Node op;
    struct Node *pop;
    init_stack(&stack,100,sizeof(struct Node));
    printf("%s\n",exp);
    for (seq = 0; seq < len; seq ++) {
        if (exp[seq] == '(') {
            op.op ='(';
            op.cur = seq;
            push_stack(&stack,(void *)&op);
        } else if (exp[seq] == ')') {
            if (empty_stack(&stack)) { 
                printf("error ')' %d.\n", seq);
            }else{
                pop =  pop_stack(&stack);
            }
        }
    }
    if (!empty_stack(&stack)) {
        pop = top_stack(&stack);
        printf("error '(' %d.\n", pop->cur);
    } else {
        printf("ok.\n");
    }
}    
