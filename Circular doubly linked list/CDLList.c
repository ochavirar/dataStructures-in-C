/**
 * @file CDLList.c
 * @author Omar Chavira (ochavirar@outlook.com)
 * @brief 
 * This file contains all the functions definitions for the datar structure
 * @version 0.1
 * @date 2022-01-14
 * 
 * @copyright Copyright (c) 2022
 * 
 **/
#include "CDLList.h"
#include <stdlib.h>

#define UNARYLIST 1
#define EQUAL 0

/**
 * @brief 
 * Allocates memory space for a new list pointer structure
 * @return ** CDLLIST 
 */
CDLLIST Cdllist_create()
{
    CDLLIST tmp = malloc(sizeof(struct STRCIRCULARDOUBLYLINKEDLIST));
    tmp->head = NULL;
    tmp->size = 0;
    return tmp;
}

/**
 * @brief 
 * This functions inserts a new node at the head of the list
 * 
 * This is done as a function to be used later in other specific scenarios as inserting an element in an empty list
 * @param list 
 * @param data 
 * @return ** void 
 */
void Cdllist_insertAtHead(CDLLIST list, TYPE data)
{
    CDLLISTNODE newNode = malloc(sizeof(struct STRCIRCULARDOUBLYLINKEDLISTNODE));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(Cdllist_isEmpty(list))
    {
        list->head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else 
    {
        CDLLISTNODE tmp = list->head;
        list->head->prev = tmp->prev;
        list->head->next = tmp;
        tmp->prev = list->head;
    } 
    list->size++;
}

/**
 * @brief 
 * This functions inserts a node at the tail of the list, if the list is empty, the node will be inserted at head
 * @param list 
 * @param data 
 * @return ** void 
 */
void Cdllist_insertAtTail(CDLLIST list, TYPE data)
{
    CDLLISTNODE newNode = malloc(sizeof(struct STRCIRCULARDOUBLYLINKEDLISTNODE));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(Cdllist_isEmpty(list))
    {
        Cdllist_insertAtHead(list, data);
    } 
    else 
    {
        list->head->prev->next = newNode;
        newNode->prev = list->head->prev;
        newNode->next = list->head;
        list->head->prev = newNode;
    }
    list->size++;
}

/**
 * @brief 
 * This functions does comparisons by a pointer function to determine if a node contains the reference data
 * Once the reference data is found, the new node will be inserted, if not, memory will be released
 * @param list 
 * @param cmpFunc 
 * @param data 
 * @param ref 
 * @return ** void 
 */
void Cdllist_insertBefore(CDLLIST list, BOOL (*cmpFunc)(TYPE, TYPE), TYPE data, TYPE ref)
{
    CDLLISTNODE tmp = list->head;
    
    if(!Cdllist_isEmpty(list))
    {
        do
        {
            if(cmpFunc(tmp->data, ref) == EQUAL)
            {
                CDLLISTNODE newNode = malloc(sizeof(struct STRCIRCULARDOUBLYLINKEDLIST));
                newNode->data = data;
                if(tmp == list->head)
                {
                    Cdllist_insertAtHead(list, data);
                }
                else if(tmp == list->head->prev)
                {
                    Cdllist_insertAtTail(list, data);
                }
                else 
                {
                    tmp->prev->next = newNode;
                    newNode->prev = tmp->prev;
                    newNode->next = tmp;
                    tmp->prev = newNode;
                    list->size++;
                }
            }
            else 
            {
                tmp = tmp->next;
            }
        }while(tmp->next != list->head);
        
            
    } 
    else 
    {
        printf("\nList is empty");
    }
}

/**
 * @brief 
 * Same function as before, but inserts new node after the node with the desired value 
 * @param list 
 * @param cmpFunc 
 * @param data 
 * @param ref 
 * @return ** void 
 */
void Cdllist_insertAfter(CDLLIST list, BOOL (*cmpFunc)(TYPE, TYPE), TYPE data, TYPE ref)
{
    CDLLISTNODE tmp = list->head;
    
    if(!Cdllist_isEmpty(list))
    {
        do
        {
            if(cmpFunc(tmp->data, ref) == EQUAL)
            {
                CDLLISTNODE newNode = malloc(sizeof(struct STRCIRCULARDOUBLYLINKEDLIST));
                newNode->data = data;
                if(tmp == list->head)
                {
                    Cdllist_insertAtHead(list, data);
                }
                else if(tmp == list->head->prev)
                {
                    Cdllist_insertAtTail(list, data);
                }
                else 
                {
                    tmp->next->prev = newNode;
                    newNode->prev = tmp;
                    newNode->next = tmp->next;
                    tmp->next = newNode;
                    list->size++;
                }
            }
            else 
            {
                tmp = tmp->next;
            }
        }while(tmp->next != list->head);
        
    } 
    else 
    {
        printf("\nList is empty");
    }
}

/**
 * @brief 
 * This function inserts a node ina  given index within the list.
 * If the index that was provided does not exists an error message will be displayed.
 * If the index is within the limits, the function will take two paths, from start to finish or from finish to start.
 * If the list is too big, the first half will be analyzed from finish to start because it will perform better.
 * If the first half is where the index is located, the analysis will be from start to finish.
 * @param list 
 * @param data 
 * @param index 
 * @return ** void 
 */
void Cdllist_insertNodeByIndex(CDLLIST list, TYPE data, int index)
{
    int listSize = Cdllist_getSize(list);
    if(index <= listSize-1)
    {
        if(index == 1)
        {
            Cdllist_insertAtHead(list, data); // Reuse of functions
        } 
        else if (index == listSize-1)
        {
            Cdllist_insertAtTail(list, data); //Reuse of function
        }
        else 
        {
            CDLLISTNODE newNode = malloc(sizeof(struct STRCIRCULARDOUBLYLINKEDLIST)); //Node to store in memory
            CDLLISTNODE tmp; //Guide node 
            if(index >= listSize-1*0.5)
            {
                tmp = list->head->prev;
                for(int i=0;i<listSize-1-index;i++)
                {
                    tmp = tmp->prev; //Reverse
                }
                newNode->prev = tmp->prev;
                tmp->prev->next = newNode;
                tmp->prev = newNode;
                newNode->next = tmp;
            } 
            else 
            {
                newNode = list->head;
                for(int i=0;i<index;i++)
                {
                    tmp = tmp->next; //Straight direction 
                }
                newNode->prev = tmp->prev;
                tmp->prev->next = newNode;
                tmp->prev = newNode;
                newNode->next = tmp;
            }
        }
        list->size++;
    } 
    else 
    {
        printf("There is no position to add this node");
    }
}

/**
 * @brief 
 * This functions deletes the head node, this includes releasing memory
 * @param list 
 * @return ** void 
 */
void Cdllist_deleteHead(CDLLIST list)
{
    CDLLISTNODE tmp = list->head;
    if(!Cdllist_isEmpty(list))
    {
        if(Cdllist_getSize(list) == UNARYLIST)
        {
            Cdllist_deleteNode(tmp);
            list->head = NULL;
        }
        else 
        {
            list->head->next->prev = list->head->next;
            list->head->prev->next = list->head->next;
            list->head = list->head->next;
        }
    }
    else 
    {
        printf("\nList is empty");
    }
    
}

/**
 * @brief 
 * This functions deletes the tail node, this includes releasing memory
 * @param list 
 * @return ** void 
 */
void Cdllist_deleteTail(CDLLIST list)
{
    CDLLISTNODE tmp = list->head->prev;
    if(!Cdllist_isEmpty(list))
    {
        if(Cdllist_getSize(list) == UNARYLIST)
        {
            Cdllist_deleteHead(list);
        }
        else 
        {
            list->head->prev = tmp->prev;
            tmp->prev->next = list->head;
            Cdllist_deleteNode(tmp);
        }
    }
    else
    {
        printf("\nList is empty");
    }
}

/**
 * @brief 
 * Deletes a node by the use of a reference value and a comparison function
 * @param list 
 * @param cmpFunc 
 * @param data 
 * @param ref 
 * @return ** void 
 */
void Cdllist_deleteNodeByReferenceValue(CDLLIST list, BOOL (*cmpFunc)(TYPE, TYPE), TYPE data, TYPE ref)
{
    CDLLISTNODE tmp = list->head;
    if(!Cdllist_isEmpty(list))
    {
        do
        {
            if(cmpFunc(tmp->data, ref) == EQUAL)
            {
                if(tmp == list->head)
                {
                    Cdllist_deleteHead(list);
                } 
                else if (tmp == list->head->prev)
                {
                    Cdllist_deleteTail(list);
                } 
                else
                {
                    tmp->prev->next = tmp->next; 
                    tmp->next->prev = tmp->prev;
                    Cdllist_deleteNode(tmp);
                } 
            }
        }while(tmp != list->head);
    }
    else
    {
        printf("\nList is empty");
    }
}

void Cdllist_deleteNodeByIndex(CDLLIST list, int index)
{
    int listSize = Cdllist_getSize(list);
    CDLLISTNODE tmp = list->head;
    
    if(index <= listSize-1)
    {
        if(index == 0)
        {
            Cdllist_deleteHead(list);
        } 
        else if (index == listSize)
        {
            Cdllist_deleteTail(list);
        }
        else 
        {
            if(index > listSize*0.5)
            {
                tmp = list->head->prev;
                for(int i=0;i<listSize-1-index;i++)
                {
                    tmp = tmp->prev;
                }
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                Cdllist_deleteNode(tmp);

            } 
            else 
            {
                for (int i=0; i<=index; i++)
                {
                    tmp = tmp->next;
                }
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev; 
                Cdllist_deleteNode(tmp);
            }
            list->size++;
        }
    }
    else 
    {
        printf("No se puede insertar");
    }
}

/**
 * @brief 
 * This function deletes a specific node, deletes relations and releases memory
 * @param toDelete 
 * @return ** void 
 */
void Cdllist_deleteNode(CDLLISTNODE toDelete)
{
    free(toDelete);
}

/**
 * @brief 
 * Returns size property of the list structure
 * @param list 
 * @return ** int 
 */
int Cdllist_getSize(CDLLIST list)
{
    return list->size;
}

/**
 * @brief 
 * True if list is empty and false if the head is not null (which means that there is at least one node in the list)
 * @param list 
 * @return ** BOOL 
 */
BOOL Cdllist_isEmpty(CDLLIST list)
{
    return list->head == NULL;
}

/**
 * @brief 
 * Destroys the full list by deleting the head node until the list is empty. In the end, the list pointer will be deleted too
 * @param list 
 * @return ** void 
 */
void Cdllist_destroy(CDLLIST list)
{
    while (!Cdllist_isEmpty(list))
    {
        Cdllist_deleteHead(list);
    }
    free(list);
}