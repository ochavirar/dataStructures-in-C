/**
 * @file datatypes.c
 * @author Omar Chavira (ochavirar@outlook.com)
 * @brief 
 * This file contains all of the necessary functions to store the data of any primitive types to a 
 * memory-allocated pointer and returning it to a TYPE, which is able to receive every necessary value due to its
 * generic pointer nature
 * @version 0.1
 * @date 2022-01-14
 * 
 * @copyright Copyright (c) 2022
 * 
 **/
#include "datatypes.h"
#include <string.h>
#include <stdlib.h>

/**
 * @brief 
 * Store the value of an int in a pointer.
 * @param i 
 * @return ** TYPE 
 */
TYPE int_create(int i)
{
    int *ptr = malloc(sizeof(int));
    *ptr = i;
    return ptr;
}

/**
 * @brief 
 * Store the value of an double in a pointer.
 * @param d 
 * @return ** TYPE 
 */
TYPE double_create(double d)
{
    double *ptr = malloc(sizeof(double));
    *ptr = d;
    return ptr;
}

/**
 * @brief 
 * Store the value of an float in a pointer.
 * @param f 
 * @return ** TYPE 
 **/
TYPE float_create(float f)
{
    float *ptr = malloc(sizeof(float));
    *ptr = f;
    return ptr;
}

/**
 * @brief 
 * Store the value of an char in a pointer.
 * @param c 
 * @return ** TYPE 
 */
TYPE char_create(char c)
{
    char *ptr = malloc(sizeof(char));
    *ptr = c;
    return ptr;
}

/**
 * @brief 
 * Store the value of an string in a pointer.
 * @param s 
 * @return ** TYPE 
 */
TYPE string_create(char *s)
{
    int strLength = strlen(s);
    char *ptr = malloc(strLength);
    strcpy(ptr, s);
    return ptr;
}
