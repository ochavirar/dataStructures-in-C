#include "stack.h"
#include <stdlib.h>

/**
 * @brief 
 * Creates the stack's main node using dynamic memory
 * @return ** STACK 
 */
STACK stack_create()
{
    STACK temp = malloc(sizeof(struct STRSTACK));
    temp->top = NULL;
    temp->size = 0;
    return temp;
}

/**
 * @brief 
 * Inserts an element to the stack, as well as increasing the stack's size
 * @param data 
 * @param stack 
 * @return ** void 
 */
void stack_push(TYPE data, STACK stack)
{
    NODE newNode = malloc(sizeof(struct STRSTACKNODE));
    newNode->data = data;
    newNode->prev = stack->top;
    stack->top = newNode;
    stack->size++;
}

/**
 * @brief 
 * Returns the top value in the stack as a value, as well as deleting that returned value from the stack
 * @param stack 
 * @return ** TYPE 
 */
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

/**
 * @brief 
 * Returns a true or false value according to the stack (if it is empty or not)
 * @param stack 
 * @return ** BOOL 
 */
BOOL stack_isEmpty(STACK stack)
{
    return(stack->top == NULL);
}

/**
 * @brief 
 * Uses other functions to destroy every element in the stack, as well as deleting the main contorl node
 * @param stack 
 * @return ** void 
 */
void stack_destroy(STACK stack)
{
    while (!stack_isEmpty(stack))
        stack_pop(stack);
    
    free(stack);
}


