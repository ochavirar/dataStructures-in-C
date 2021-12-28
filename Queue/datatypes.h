/**
 * @file datatypes.h
 * @author Omar Chavira (ochavirar@outlook.com)
 * @brief 
 * Datatypes to use void pointers as a methdod to store any kind of primitive type within a queue.
 * @version 0.1
 * @date 2021-12-27
 * 
 * @copyright OCR Copyright (c) 2021
 * 
 */
#ifndef DATATYPES_H_
#define DATATYPES_H_

typedef void *TYPE; // void pointer defined as TYPE
typedef enum{FALSE, TRUE} BOOL; // Boolean definition as an enum

struct STRQUEUENODE // Node for a stack
{
    TYPE data; // Void pointer
    struct STRQUEUENODE *next;
};

typedef struct STRQUEUENODE *QUEUENODE; // defined primitive for a queue

/**
 * @brief 
 * Macros to get the value from different primitives based on a TYPE, which is a pointer to void. 
 */

#define int_val(e) (*((int *)e))
#define float_valr(e) (*((float *)e))
#define double_val(e) (*((double *)e))
#define char_val(e) (*((char *)e))
#define str_val(e) ((*e))

/**
 * @brief 
 * Functions that reserve space for a primitive and sotres it in another pointer (starting from a void pointer).
 * @return ** TYPE 
 */
TYPE int_create(int);
TYPE float_create(float);
TYPE double_create(double);
TYPE char_create(char);
TYPE string_create(char *);

#endif //DATATYPES_H_