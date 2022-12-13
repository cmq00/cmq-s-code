#include <stdio.h>

struct STACK {
    
    int cur;
    int max;

    int width;
    void *node;
};


void  init_stack(struct STACK * stack, size_t elm, size_t width); 
void push_stack(struct STACK * stack, void *node);
void * pop_stack(struct STACK * stack);

void * top_stack(struct STACK * stack);

int empty_stack(struct STACK * stack);


