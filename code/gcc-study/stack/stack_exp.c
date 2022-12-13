#include <stdio.h>
#include <string.h>

void push(char *stack, char op);
char pop(char *stack);


void push(char *stack, char op)
{
    stack[strlen(stack)] = op;
}

char pop(char *stack)
{

    char op = '/';
    if (stack[0] != '\0') {
        op = stack[strlen(stack) - 1];
        stack[strlen(stack) - 1] = '\0';
    }

    return op;

}


int main()
{   
    char stack[10] = {0};
    char exp[100] = "((1+2) * 3";

    int len = strlen(exp);
    int seq;

    char op;
    printf("%s\n",exp);
    for (seq = 0; seq < len; seq ++) {
        if (exp[seq] == '(') {
            push(stack, '(');
        } else if (exp[seq] == ')') {
            op = pop(stack);
            if (op == '/') { 
                printf("error ')'.\n");
            }
        }
    }
    if (strlen(stack) > 0) {
        printf("error '('.\n");
    } else {
        printf("ok.\n");
    }
}    
