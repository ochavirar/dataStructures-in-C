#include "datatypes.h"

#ifndef SLLIST_H_
#define SLLIST_H_

/**
 * @brief 
 * Singly linked list structure declaration (base for the nodes)
 */
struct STRSINGLYLINKEDLIST
{
    SLLISTNODE head;
    int size;
};

typedef struct STRSINGLYLINKEDLIST *SLLIST; //Primitive type for the singly linked list

SLLIST SLList_create();//Simple list creation
void SLList_insertAtHead(SLLIST list, TYPE data);//Insertion 
void SLList_inserAtTail(SLLIST list, TYPE data);//Insertion
void SLList_insertAfter(SLLIST list, TYPE data, int (*comparisonFunction) (TYPE a, TYPE b), TYPE ref);//Insertion
void SLList_insertBefore(SLLIST list, TYPE data, int (*comparisonFunction) (TYPE a, TYPE b), TYPE ref);//Insertion
void SLList_deleteHead(SLLIST list);//Deletion
void SLList_deleteTail(SLLIST list);//Deletion
void SLList_deleteData(SLLIST list, int (*comparisonFunction) (TYPE a, TYPE b), TYPE ref);//Deletion
int SLList_getSize(SLLIST list);//Get size
void SLList_delete(SLLIST list);//Deletion
TYPE SLList_getHead(SLLIST list);//Check and get value without deletion
TYPE SLList_getTail(SLLIST list);//Check and get value without deletion
TYPE SLList_getDataByIndex(SLLIST list, int index); //Return data by an index given by the user
BOOL SLList_isDataInList(SLLIST list, int (*comparisonFunction)(TYPE a, TYPE b), TYPE ref);// Check without deletion
#endif //SLLIST_H_