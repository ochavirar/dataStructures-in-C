#include <stdlib.h>
#include <string.h>
#include "datatypes.h"

TYPE int_create(int n)
{
    int *ptr = malloc(sizeof(int));
    *ptr = n;
    return ptr;
}

TYPE float_create(float n)
{
    float *ptr = malloc(sizeof(float));
    *ptr = n;
    return ptr;
}

TYPE double_create(double n)
{
    double *ptr = malloc(sizeof(double));
    *ptr = n;
    return ptr;
}

TYPE char_create(char n)
{
    char *ptr = malloc(sizeof(char));
    *ptr = n;
    return ptr;
}

TYPE string_create(char *s)
{
    int str_length = strlen(s);
    char *ptr = malloc(str_length);
    strcpy(ptr, s);
    return ptr;
}
