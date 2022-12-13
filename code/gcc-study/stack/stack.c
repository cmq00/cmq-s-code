#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"


void  init_stack(struct STACK * stack, size_t elm, size_t width) 
{
    /*
        stack->node 分配内存： elm * width
        stack->max = elm
        stack->cur = 0

        stack->width = width
    */

   stack->node = malloc(elm*width);
   stack->max = elm;
   stack->cur =  0;
   stack->width = width;

}

void push_stack(struct STACK * stack, void *node)
{
    memcpy(stack->node +stack->cur* stack->width,node,stack->width);
    stack->cur++;
}

void * pop_stack(struct STACK * stack)
{
    stack->cur--;
    return stack->node+stack->cur*stack->width;
}

void * top_stack(struct STACK * stack)
{
    return stack->node+(stack->cur-1)*stack->width;
}

int empty_stack(struct STACK * stack)
{
    return stack->cur == 0;
}
