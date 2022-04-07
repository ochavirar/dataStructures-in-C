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

#ifndef CDLLIST_H_
#define CDLLIST_H_

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

CDLLIST Cdllist_create(); //Creates a new list
void Cdllist_insertAtHead(CDLLIST, TYPE); //Inserts a new node at head
void Cdllist_insertAtTail(CDLLIST, TYPE); //Inserts a new node at the end of the list
void Cdllist_insertbefore(CDLLIST, BOOL (*cmpFunc)(TYPE, TYPE), TYPE, TYPE); //Inserts a new node before the node with the provided value
void Cdllist_insertAfter(CDLLIST, BOOL (*cmpFunc)(TYPE, TYPE), TYPE, TYPE ); //Inserts a new node before the given valu's first occurance 
void Cdllist_deleteHead(CDLLIST); //Deletes the head node of a given list
void Cdllist_insertNodeAtIndex(CDLLIST, TYPE, int); //Inserts a node in a given index
void Cdllist_deleteTail(CDLLIST); //Deletes the tail node of the list
void Cdllist_deleteNodeByReferenceValue(CDLLIST, BOOL (*cmpFunc)(TYPE, TYPE), TYPE data, TYPE ref); //Deletes a node with a reference value
void Cdllist_deleteNodeByIndex(CDLLIST, int); //Deletes a node in a given position
void Cdllist_deleteNode(CDLLSITNODE); //Frees a node from memory
void Cdllist_destroy(CDLLIST); //Destroys full list
void Cdllist_insertNodeByIndex(CDLLIST, TYPE, int); //Inserts a node in a specific position (if the position does not exists  an error message is returned)
BOOL Cdllist_isEmpty(CDLLIST); //Returns a boolean value that indicates if the list has content or not
int Cdllist_getSize(CDLLIST list); //Returns the list size

#endif //CDLLIST_H_