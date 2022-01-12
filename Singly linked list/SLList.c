#include "SLList.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief 
 * Allocates memory for the main SLList pointer and initializes it's parameters.
 * @return ** SLLIST primitive type (more details in SLList.h)
 */
SLLIST SLList_create()
{
    SLLIST temp = malloc(sizeof(struct STRSINGLYLINKEDLIST)); //Memory allocation
    temp->head = NULL;
    temp->size = 0;
    return temp;
}

/**
 * @brief 
 * Creates a new node and inserts it in the head of the singly linked list
 * @param list 
 * @param data 
 * @return ** void 
 */
void SLList_insertAtHead(SLLIST list, TYPE data)
{
    SLLISTNODE newNode = malloc(sizeof(struct STRSINGLYLINKEDLISTNODE));
    newNode->data = data;
    newNode->next = NULL;
    if(list->head == NULL) // If list is empty
        list->head = newNode;
    else 
    {
        SLLISTNODE temp = list->head;
        list->head = newNode;
        newNode->next = temp;
    }
    list->size++;
}

/**
 * @brief 
 * Returns value in the head of the SLList, without deleting the node itself
 * @param list 
 * @return ** TYPE 
 */
TYPE SLList_getHead(SLLIST list)
{
    return list->head->data;
}

/**
 * @brief 
 * Creates a new node and inserts it in the end of the singly linked list
 * @param list 
 * @param data 
 * @return ** void 
 */
void SLList_inserAtTail(SLLIST list, TYPE data)
{
    SLLISTNODE newNode = malloc(sizeof(struct STRSINGLYLINKEDLISTNODE)); //Memory allocation
    SLLISTNODE temp = list->head;
    newNode->data = data;
    newNode->next = NULL;
    if(temp == NULL) //If list is empty
        list->head = newNode;
    else
    {
        while (temp->next != NULL) //Go through the list
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

/**
 * @brief 
 * Gets a value, looks for it in the list and inserts the new node at the next position from the reference value
 * @param list 
 * @param data 
 * @param cmpFunc Comparison function defined by user according to the type (a zero means that both contents are the same)
 * @param ref The data used as reference to insert a node after a certain content
 * @return ** void 
 */
void SLList_insertAfter(SLLIST list, TYPE data, int (*cmpFunc) (TYPE, TYPE), TYPE ref)
{
    SLLISTNODE trav1, trav2;
    trav1 = list->head;
    trav2 = list->head->next;
    while ( (cmpFunc(ref, trav1->data)!=0) && !(trav2 == NULL) ) //Go through the list while doing comparisons
    {
        trav1 = trav1->next;
        trav2 = trav2->next;
    }
    if(!(trav2 == NULL)) //If the reference value is found
    {
        SLLISTNODE newNode = malloc(sizeof(struct STRSINGLYLINKEDLISTNODE)); //Memory allocation
        newNode->data = data;
        newNode->next = trav2;
        trav1->next = newNode;
        list->size++;
    }
    else
    {
        printf("Not added after!\n");
    }
}

/**
 * @brief 
 * Gets a value, looks for it in the list and inserts the new node at the previous position from the reference value
 * @param list 
 * @param data 
 * @param cmpFunc Comparison function defined by user according to the type (a zero means that both contents are the same)
 * @param ref The data used as reference to insert a node before a certain content
 * @return ** void 
 */
void SLList_insertBefore(SLLIST list, TYPE data, int (*cmpFunc) (TYPE, TYPE), TYPE ref)
{
    SLLISTNODE trav1, trav2;
    trav1 = list->head;
    trav2 = list->head->next;
    while ( (cmpFunc(ref, trav2->data)!=0) && (trav2->next != NULL) ) //Go through the list while doing comparisons
    {
        trav1 = trav1->next;
        trav2 = trav2->next;
    }
    if(trav2->next != NULL) //If the reference value is found
    {
        SLLISTNODE newNode = malloc(sizeof(struct STRSINGLYLINKEDLISTNODE)); //Memory allocation
        newNode->data = data;
        trav1->next = newNode;
        newNode->next = trav2;
        list->size++;
    }
    else
    {
        printf("Not added before!\n");
    }
}

/**
 * @brief 
 * Deletes the head value (non-returning function)
 * @param list 
 * @return ** void 
 */
void SLList_deleteHead(SLLIST list)
{
    if(list->head != NULL) //If list is not empty
    {
        SLLISTNODE tmpNode;
        tmpNode = list->head;
        list->head = list->head->next;
        free(tmpNode);
        list->size--;
    }
}

/**
 * @brief 
 * Deletes the last value (non-returning function)
 * @param list 
 * @return ** void 
 */
void SLList_deleteTail(SLLIST list)
{
    SLLISTNODE trav1, trav2;
    trav1 = list->head;
    trav2 = list->head->next;
    while(trav2->next != NULL && trav2 != NULL) //Go through the list
    {
        trav1 = trav1->next;
        trav2 = trav2->next;
    }
    trav1->next = trav2->next;
    free(trav2); //Memory release
    list->size--;
}

/**
 * @brief 
 * Returns the last value in the list (without deleting it)
 * @param list 
 * @return ** TYPE 
 */
TYPE SLList_getTail(SLLIST list)
{
    SLLISTNODE tmp = list->head;
    while (tmp->next != NULL && tmp != NULL) //Go through the list
    {
        tmp = tmp->next;
    }

    return tmp->data;
}

/**
 * @brief 
 * Deletes a specific number in the list.
 * @param list 
 * @param cmpFunc Comparison function defined by user according to the used data type
 * @param ref Reference value to delete
 * @return ** void 
 */
void SLList_deleteData(SLLIST list, int (*cmpFunc) (TYPE, TYPE), TYPE ref)
{
    SLLISTNODE trav1, trav2;
    trav1 = list->head;
    trav2 = list->head->next;
    while ( (cmpFunc(ref, trav2->data)!= 0) && (trav2->next != NULL) ) //Go through the list and doing comparisons to the reference value
    {
        trav1 = trav1->next;
        trav2 = trav2->next;
    }
    
    if(trav2->next != NULL) //If reference value is found
    {
        trav1->next = trav2->next;
        free(trav2);
        list->size--;
    }
    else
    {
        printf("Data not deleted (not found in list)\n");
    }
}

/**
 * @brief 
 * Deletes the whole data structure, including the initial pointer.
 * @param list 
 * @return ** void 
 */
void SLList_delete(SLLIST list)
{
    while (list->head != NULL) //Go through the list 
    {
        SLList_deleteHead(list);
    }
    free(list); //Memory release
}

/**
 * @brief 
 * Returns size parameter
 * @param list 
 * @return ** int 
 */
int SLList_getSize(SLLIST list)
{
    return list->size; //Parameter return
}

/**
 * @brief 
 * Looks for data in the list and returns TRUE if it is found, and FALSE if not.
 * @param list 
 * @param cmpFunc 
 * @param ref 
 * @return ** BOOL 
 */
BOOL SLList_isDataInList(SLLIST list, int (*cmpFunc) (TYPE, TYPE), TYPE ref)
{
    BOOL isInList = FALSE;
    SLLISTNODE tmp = list->head;
    while(tmp->next != NULL && tmp != NULL) //Go through the list
    {
        if(cmpFunc(ref, tmp->data)==0) //Reference value is found?
        {
            isInList = TRUE; 
            break; //Cancel loop
        }
        tmp = tmp->next;
    }
    return isInList;
}

/**
 * @brief 
 * This function returns the data in a simply linked list node. Returns NULL if the index does not exist.
 * @param list 
 * @param index 
 * @return ** TYPE 
 */
TYPE SLList_getDataByIndex(SLLIST list, int index)
{
    SLLISTNODE tmp = list->head;
    if(index <= SLList_getSize(list) && index >= 0) //If index exists
    {
        for(int i=0;i<index;i++) //Go through the list
        {
            tmp = tmp->next;
        }
        return tmp->data; 
    }
    else
    {
        printf("Out of bounds!\n"); // If the index does not exist
        return NULL;
    }
}

/**
 * @brief 
 * This function replaces the data within a node for a new data given by the user, as well as replacing it in the node 
 * which is located in the provided index
 * @param list 
 * @param index 
 * @param data 
 * @return ** void 
 */
void SLList_replaceDataByIndex(SLLIST list, int index, TYPE data)
{
    SLLISTNODE tmp = list->head;
    if(index < SLList_getSize(list) && index >= 0)
    {
        for(int i=0;i<index;i++)
        {
            tmp = tmp->next;
        }
        tmp->data = data;
    }
    else
    {
        printf("Out of bounds!\n");
    }
}

/**
 * @brief 
 * This function deletes a node based on an index which was provided by the user
 * @param list 
 * @param index 
 * @return ** void 
 */
void SLList_deleteNodeByIndex(SLLIST list, int index)
{
    SLLISTNODE tmp = list->head;
    SLLISTNODE tmp2;
    if(index < SLList_getSize(list) && index >= 0)
    {
        index--;
        for(int i=0;i<index;i++)
        {
            tmp = tmp->next;
        }
        tmp2 = tmp->next;
        tmp->next = tmp2->next;
        free(tmp2);
        list->size--;
    } 
    else
    {
        printf("Out of bounds!\n");
    }
}
