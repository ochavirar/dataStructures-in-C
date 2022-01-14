/**
 * @file datatypes.c
 * @author Omar Chavira (ochavirar@outlook.com)
 * @brief 
 * This file contains all the functions definition to store a value using pointers adn returning
 * it to a void pointer type
 * @version 0.1
 * @date 2022-01-14
 * 
 * @copyright Copyright (c) 2022
 * 
 **/

#include "datatypes.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief 
 * Memory allcoation for an integer.
 * @param n 
 * @return ** TYPE 
 */
TYPE int_create(int n)
{
    int *ptr = malloc(sizeof(int));
    *ptr = n;
    return ptr;
}

/**
 * @brief 
 * Memory allcoation for a float.
 * @param n 
 * @return ** TYPE 
 */
TYPE float_create(float n)
{
    float *ptr = malloc(sizeof(float));
    *ptr = n;
    return ptr;
}

/**
 * @brief 
 * Memory allcoation for a double.
 * @param n 
 * @return ** TYPE 
 */
TYPE double_create(double n)
{
    double *ptr = malloc(sizeof(double));
    *ptr = n;
    return ptr;
}

/**
 * @brief 
 * Memory allcoation for a character.
 * @param n 
 * @return ** TYPE 
 */
TYPE char_create(char n)
{
    char *ptr = malloc(sizeof(char));
    *ptr = n;
    return ptr;
}

/**
 * @brief 
 * Memory allcoation for a string.
 * @param n 
 * @return ** TYPE 
 */
TYPE str_create(char *s)
{
    int str_len = strlen(s);
    char *str = malloc(str_len);
    strcpy(str, s);
    return str;
}
