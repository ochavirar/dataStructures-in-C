#include "datatypes.h"

#ifndef STACK_H_
#define STACK_H_

typedef void *TYPE;

struct STRSTACK
{
    NODE top;
    int size;    
};

typedef struct STRSTACK *STACK;

STACK stack_create();
void stack_push(TYPE, STACK);
TYPE stack_pop(STACK);
BOOL stack_isEmpty(STACK);
void stack_destroy(STACK);
#endif //STACK_H_