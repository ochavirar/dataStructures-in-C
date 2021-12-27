/**
 * @file stack.h
 * @author Omar Chavira (ochavirar@outlook.com)
 * @brief 
 * Stack node and functions declaration.
 * @version 0.1
 * @date 2021-12-26
 * 
 * @copyright OCR Copyright (c) 2021
 * 
 */
#include "datatypes.h"

#ifndef STACK_H_
#define STACK_H_

/**
 * @brief 
 * Main node for the stack.
 */
struct STRSTACK
{
    NODE top;
    int size;    
};

typedef struct STRSTACK *STACK; // Stack primitive 

/**
 * @brief 
 * Stack core functions declaration
 */

STACK stack_create();
void stack_push(TYPE, STACK);
void stack_destroy(STACK);
TYPE stack_pop(STACK);
BOOL stack_isEmpty(STACK);
#endif //STACK_H_