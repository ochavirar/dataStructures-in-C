/**
 * @file datatypes.c
 * @author Omar Chavira (ochavirar@outlook.com)
 * @brief 
 * Functions implementation to attach a value for any primitive and use it in a stack
 * @version 0.1
 * @date 2021-12-26
 * 
 * @copyright OCR Copyright (c) 2021
 * 
 */
#include <stdlib.h>
#include <string.h>
#include "datatypes.h"

/**
 * @brief 
 * Function that uses void pointer to get a integer
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
 * Function that uses void pointer to get a float
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
 * Function that uses void pointer to get a double
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
 * Function that uses void pointer to get a char
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
 * Function that uses void pointer to get a string
 * @param n 
 * @return ** TYPE 
 */
TYPE string_create(char *s)
{
    int str_length = strlen(s);
    char *ptr = malloc(str_length);
    strcpy(ptr, s);
    return ptr;
}
