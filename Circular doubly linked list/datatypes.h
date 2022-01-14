/**
 * @file datatypes.h
 * @author Omar Chavira (ochavirar@outlook.com)
 * @brief 
 * This function contains all the primitive types that will be used throughout the development of
 * the data structure. From the BOOl and TYPE types to the nodes declaration. 
 * Also, this file will get the necessary functions to allocate every primitive type with the use of void pointers.
 * @version 0.1
 * @date 2022-01-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef DATATYPES_H_
#define DATATYPES_H_

/**
 * @brief 
 * Bool primitive type declaration using an enum and treating it as some int value.
 */
typedef enum {FALSE=0, TRUE} BOOL;

/**
 * @brief 
 * Void pointer use for a generic TYPE type variable.
 */
typedef void *TYPE;

/**
 * @brief 
 * Structure declaration for a doubly circular linked list.
 * Contains a previous and a next pointer for every node, as well as the value that will be stored
 */
struct STRCIRCULARDOUBLYLINKEDLISTNODE
{
    TYPE data;
    struct STRCIRCULARDOUBLYLINKEDLISTNODE *next;
    struct STRCIRCULARDOUBLYLINKEDLISTNODE *prev;
};

/**
 * @brief 
 * Circular doubly linked list type using a pointer.
 */
typedef struct STRCIRCULARDOUBLYLINKEDLISTNODE *CDLLISTNODE;

TYPE int_create(int i); //Int primitive
TYPE double_create(double d); //Double primitive
TYPE float_create(float f); //Float primitive
TYPE char_create(char c); //Char primitive
TYPE string_create(char *s); //String primitive

/**
 * @brief 
 * Primitive types macros to ptint
 */
#define int_val(e) (*((int*) e))
#define float_val(e) (*((float*) e))
#define double_val(e) (*((double*) e))
#define char_val(e) (*((char *) e))
#define str_val(e) ((*e))

#endif //DATATYPES_H_