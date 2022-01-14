/**
 * @file CDLList.h
 * @author Omar Chavira (ochavirar@outlook.com)
 * @brief 
 * This file contains all the functions declarations that the data structure will get.
 * Also, the declaration of a circular doubly linked list data structure will be present to store 
 * information like size and the head of the list.
 * @version 0.1
 * @date 2022-01-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "datatypes.h"

#ifndef CDDLIST_H_
#define CDDLIST_H_

/**
 * @brief 
 * Structure declaration for the list node.
 */
struct STRCIRCULARDOUBLYLINKEDLIST
{
    int size;
    CDLLISTNODE head;
};

/**
 * @brief 
 * Primitive type for the ciruclar doubly linked list
 */
typedef struct STRCIRCULARDOUBLYLINKEDLIST *CDLLIST;

#endif //CDDLIST_H_