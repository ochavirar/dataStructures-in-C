#include "stack.h"
#include <stdlib.h>

STACK stack_create()
{
    STACK temp = malloc(sizeof(struct STRSTACK));
    temp->top = NULL;
    temp->size = 0;
    return temp;
}

void stack_push(TYPE data, STACK stack)
{
    NODE newNode = malloc(sizeof(struct STRSTACKNODE));
    newNode->data = data;
    newNode->prev = stack->top;
    stack->top = newNode;
    stack->size++;
}

TYPE stack_pop(STACK stack)
{
    NODE temporalNode = stack->top;
    TYPE returnValue = NULL;
    if(temporalNode != NULL)
    {
        returnValue = temporalNode->data;
        stack->top = temporalNode->prev;
        free(temporalNode);
        stack->size--;
    }
    return returnValue;
}

BOOL stack_isEmpty(STACK stack)
{
    return(stack->top == NULL);
}

void stack_destroy(STACK stack)
{
    while (!stack_isEmpty(stack))
        stack_pop(stack);
    
    free(stack);
}


