#include <stdio.h>
#include "stack.h"

int main(void)
{
    STACK newStack = stack_create();
    int num = 10;
    TYPE e;
    
    for(int i=0;i<100;i++)
    {
        e = int_create(i);
        stack_push(e, newStack);
    }

    printf("Stack size is %d\n", newStack->size);

    while (!stack_isEmpty(newStack))
    {
        e = stack_pop(newStack);
        printf("%d\n", int_val(e));
    }
    
    printf("After deletion, size is %d", newStack->size);

    stack_destroy(newStack);

    return 0;
}