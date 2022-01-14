/**
 * @file DLList.h
 * @author Omar Chavira (ochavirar@outlook.com)
 * @brief 
 * This file contains the functions declaration for the data structure, as well as the list structure itself
 * @version 0.1
 * @date 2022-01-14
 * 
 * @copyright Copyright (c) 2022
 * 
 **/
#include "datatypes.h"

#ifndef DLLLIST_H_
#define DLLLIST_H_

/**
 * @brief 
 * Struct declaration, stores size and a pointer to the head of the list
 */
struct STRDOUBLYLINKEDLIST
{
    int size;
    DLLISTNODE head;
};

/**
 * @brief 
 * Primitive type of the list using a pointer
 */
typedef struct STRDOUBLYLINKEDLIST *DLLIST;

DLLIST DLList_create(); 
void DLList_insertAtHead(DLLIST list, TYPE data); 
void DLList_insertAtTail(DLLIST list, TYPE data);
void DLList_insertBefore(DLLIST list, int (*comparisonFunction)(TYPE a, TYPE b), TYPE data, TYPE ref);
void DLList_insertAfter(DLLIST list, int (*comparisonFunction)(TYPE a, TYPE b), TYPE data, TYPE ref);
void DLList_deleteHead(DLLIST list);
void DLList_deleteTail(DLLIST list);
void DLList_deleteList(DLLIST list);
void DLList_deleteData(DLLIST list, int (*comparisonFunction)(TYPE a, TYPE b), TYPE ref);
void DLList_deleteDataByIndex(DLLIST list, int index);
void DLList_replaceDataByIndex(DLLIST list, int index, TYPE data);
TYPE DLList_getHead(DLLIST list);
TYPE DLList_getTail(DLLIST list);
TYPE DLList_getDataByIndex(DLLIST list, int index);
BOOL DLList_isDataInList(DLLIST list, int(*comparisonFunction)(TYPE a, TYPE b), TYPE ref);
int DLList_getSize(DLLIST list);
#endif //DLLIST_H_