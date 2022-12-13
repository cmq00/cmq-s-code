#include <stdio.h>
#include <string.h>


struct Node {
    char op;
    int cur;
};


int push(struct Node *stack, int cur, char op, int pos);
struct Node pop(struct Node *stack, int cur);


int push(struct Node  *stack, int cur,char op,int pos)
{
    stack[cur].op = op;
    stack[cur].cur = pos;

    return ++cur;
}

struct Node pop(struct Node *stack,int cur)
{

    struct Node op;
    op.op = '/';

    if (cur == 0) {
        return op;
    }
    op.op = stack[cur].op;
    op.cur = stack[cur].cur;


    return op;

}


int main()
{   
    struct Node stack[10];
    int cur = 0;
    char exp[100] = "((1+2) * 3";

    int len = strlen(exp);
    int seq;

    struct Node op;
    printf("%s\n",exp);
    for (seq = 0; seq < len; seq ++) {
        if (exp[seq] == '(') {
            cur = push(stack, cur, '(', seq);
        } else if (exp[seq] == ')') {
            op = pop(stack, cur);
            if (op.op == '/') { 
                printf("error ')' %d.\n", op.cur);
            }
        }
    }
    if (cur > 0) {
        printf("error '(' %d.\n", stack[cur].cur);
    } else {
        printf("ok.\n");
    }
}    
