/**
 * @file DLList.c
 * @author Omar Chavira (ochavirar@outlook.com)
 * @brief 
 * This file contains all of the functions defeinitions for a doubly linked list
 * @version 0.1
 * @date 2022-01-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include"DLList.h"
#include"datatypes.h"
#include<stdio.h>
#include<stdlib.h>

/**
 * @brief 
 * Creates a list without nodes, and a size 0. 
 * @return ** DLLIST 
 */
DLLIST DLList_create()
{
    DLLIST temp = malloc(sizeof(struct STRDOUBLYLINKEDLIST)); //Memory allocation
    temp->head = NULL;
    temp->size = 0;
    return temp;
}

/**
 * @brief 
 * This functions insert a node with certain given data at the head of the 
 * doubly linked list, taking into consideration if the list is empty or not.
 * @param list 
 * @param data 
 * @return ** void 
 */
void DLList_insertAtHead(DLLIST list, TYPE data)
{
    DLLISTNODE newNode = malloc(sizeof(struct STRDOUBLYLINKEDLISTNODE)); //Memory allocation
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if(list->head != NULL) //If list is not empty
    {
        DLLISTNODE tmp = list->head;
        list->head = newNode;
        newNode->next = tmp;
        tmp->prev = newNode;
        list->size++;
    } 
    else 
    {
        list->head = newNode;
        list->size++;
    }
}

/**
 * @brief 
 * This function inserts a node with any given data to the list.
 * Taking into consideration if the list is empty or not.
 * @param list 
 * @param data 
 * @return ** void 
 */
void DLList_insertAtTail(DLLIST list, TYPE data)
{
    DLLISTNODE newNode = malloc(sizeof(struct STRDOUBLYLINKEDLISTNODE)); //Memory allocation
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(list->head != NULL) //If list is not empty
    {
        DLLISTNODE tmp = list->head;
        while(tmp->next != NULL) //Go thorugh the list
        {
            tmp = tmp->next;
        }
        newNode->prev = tmp;
        tmp->next = newNode;
        list->size++;
    } 
    else
    {
        list->head = newNode;
        list->size++;
    } 
}

/**
 * @brief 
 * This function inserts any node with a given data before a reference value.
 * Taking into account that the data can be inserted between nodes, at the beginning,
 * but never at the end.
 * @param list 
 * @param cmpFunc 
 * @param data 
 * @param ref 
 * @return ** void 
 */
void DLList_insertBefore(DLLIST list, int (*cmpFunc)(TYPE, TYPE), TYPE data, TYPE ref)
{
    DLLISTNODE tmp = list->head; //Guide node
    if(tmp != NULL) //If list is not empty
    {
        while (cmpFunc(tmp->data, ref) != 0 && tmp != NULL) //Go through the list
        {
            tmp = tmp->next;
        }

        if(tmp == list->head) //If the node must be inserted before head node
        {
            DLList_insertAtHead(list, data);
        } 
        else if(tmp == NULL) //If the guide node goes to the end (value not found)
        {
            printf("ERROR!\n");
        }
        else
        {
            DLLISTNODE newNode = malloc(sizeof(struct STRDOUBLYLINKEDLISTNODE)); //Memory allocation
            newNode->data = data;
            tmp->prev->next = newNode;
            newNode->prev = tmp->prev;
            tmp->prev = newNode;
            newNode->next = tmp;
            list->size++;
        }
    } 
    else
    {
        DLList_insertAtHead(list, data);
    }
}

/**
 * @brief 
 * This function inserts any node with a given data after a reference value.
 * Taking into account that the data can be inserted between nodes, at the beginning,
 * but never at the end.
 * @param list 
 * @param cmpFunc 
 * @param data 
 * @param ref 
 * @return ** void 
 */
void DLList_insertAfter(DLLIST list, int(*cmpFunc)(TYPE, TYPE), TYPE data, TYPE ref)
{
    DLLISTNODE tmp = list->head; //Guide node
    if(tmp != NULL) //If list is not empty
    {
        while (cmpFunc(tmp->data, ref) != 0 && tmp != NULL) //Go through the list
        {
            tmp = tmp->next;
        }

        if(tmp == NULL) //If node goes to the end (value not found)
        {
            printf("ERROR!\n");
        }
        else if(tmp->next == NULL) //If the new node must be inserted after the tail
        {
            DLList_insertAtTail(list, data);
        }
        else
        {
            DLLISTNODE newNode = malloc(sizeof(struct STRDOUBLYLINKEDLISTNODE)); //Memory allocation
            newNode->data = data;
            tmp->next->prev = newNode;
            newNode->next = tmp->next;
            newNode->prev = tmp;
            tmp->next = newNode;
            list->size++;
        }
    }
    else
    {
        DLList_insertAtHead(list, data);
    }
}

/**
 * @brief 
 * This function deletes the head node in the list.
 * @param list 
 * @return ** void 
 */
void DLList_deleteHead(DLLIST list)
{
    DLLISTNODE tmp = list->head; //Guide node
    if(tmp != NULL) //If list is not empty
    {
        if(tmp->next != NULL) //If the head node is the only node
        {
            tmp->next->prev = NULL;
            list->head = tmp->next;
            free(tmp);
            list->size--;
        }
        else
        {
            list->head = NULL;
            free(tmp);
            list->size--;
        }
    }
    else
    {
        printf("No head to delete!\n");
    }
}

/**
 * @brief 
 * This function deletes the tail of the list, taking into consideration 
 * if the list has one, many or no elements.
 * @param list 
 * @return ** void 
 */
void DLList_deleteTail(DLLIST list)
{
    DLLISTNODE tmp = list->head; //Guide node
    if(tmp != NULL) //If list is not empty
    {
        if(tmp->next == NULL) //if head is the only node
        {
            DLList_deleteHead(list);
        }
        else
        {
            while (tmp->next != NULL) //Go through the list
            {
                tmp = tmp->next;
            }
            tmp->prev->next = NULL;
            free(tmp);
            list->size--;
        }
    }
}

/**
 * @brief 
 * This function deletes every node in the list, as well as the list pointer to head and the size value
 * @param list 
 * @return ** void 
 */
void DLList_deleteList(DLLIST list)
{
    DLLISTNODE tmp = list->head; //Guide node
    while (tmp != NULL) //Go through the list
    {
        tmp = tmp->next;
        DLList_deleteHead(list);
    }
    free(list); //Delete list structure
}

/**
 * @brief 
 * This function deletes a node with a certain data. 
 * If repetitions are present, the first found element with the reference data will be 
 * the deleted node.
 * @param list 
 * @param cmpFunc 
 * @param ref 
 * @return ** void 
 */
void DLList_deleteData(DLLIST list, int (*cmpFunc)(TYPE a, TYPE b), TYPE ref)
{
    DLLISTNODE tmp = list->head; //Guide node
    if(tmp != NULL) //If list is not empty
    {
        while (cmpFunc(tmp->data, ref) != 0 && tmp != NULL) //Go through the list
        {
            tmp = tmp->next;
        }

        if(tmp->next == NULL) //If the last node must be deleted
        {
            tmp->prev->next = NULL;
            free(tmp);
            list->size--;
        }
        else if(tmp->prev == NULL) //if the first node must be deleted
        {
            list->head = tmp->next;
            tmp->next->prev = NULL;
            free(tmp);
            list->size--;
        }
        else if (tmp != NULL) //If a middle node must be deleted
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
            list->size--;
        }
        else
        {
            printf("Deletion data not found!\n");
        }
    } 
    else
    {
        printf("No data was found!\n");
    }
}

/**
 * @brief 
 * Returns the head data in a list
 * @param list 
 * @return ** TYPE 
 */
TYPE DLList_getHead(DLLIST list)
{
    return list->head->data;
}

TYPE DLList_getTail(DLLIST list)
{
    DLLISTNODE tmp = list->head;
    if(tmp != NULL)
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        return tmp->data;
    }
    else
    {
        return NULL;
    }
}

/**
 * @brief 
 * This function returns the data within a node
 * The node's data will be acquired based on an index.
 * @param list 
 * @param index 
 * @return ** TYPE 
 */
TYPE DLList_getDataByIndex(DLLIST list, int index)
{
    DLLISTNODE tmp = list->head;
    if(index < DLList_getSize(list) && index >= 0)
    {
        for(int i=0;i<index;i++)
        {
            tmp = tmp->next;
        }
        return tmp->data;
    }
    else
    {
        printf("Out of bounds!\n");
        return NULL;
    }
}

/**
 * @brief 
 * This function checks the list for a reference value.
 * Returns true if the value is found and false if not.
 * @param list 
 * @param cmpFunc 
 * @param ref 
 * @return ** BOOL 
 */
BOOL DLList_isDataInList(DLLIST list, int(*cmpFunc)(TYPE, TYPE), TYPE ref)
{
    DLLISTNODE tmp = list->head;
    BOOL bRet = FALSE;
    if(tmp != NULL)
    {
        while (bRet == FALSE && tmp != NULL)
        {
            if(cmpFunc(tmp->data, ref) == 0)
            {
                bRet = TRUE;
            }
            tmp = tmp->next;
        }
        return bRet;
    }
    return bRet;
}

/**
 * @brief 
 * This function deletes the data and the node with a given index
 * @param list 
 * @param index 
 * @return ** void 
 */
void DLList_deleteDataByIndex(DLLIST list, int index)
{
    DLLISTNODE tmp = list->head;
    if(index < DLList_getSize(list) && index >= 0)
    {
        for (int i=0;i<index;i++)
        {
            tmp = tmp->next;
        }

        if(tmp == list->head)
        {
            DLList_deleteHead(list);
        }
        else if(tmp->next == NULL)
        {
            tmp->prev->next = NULL;
            free(tmp);
            list->size--;
        }
        else
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
            list->size--;
        }
    }
    else
    {
        printf("Out of bounds!\n");
    }
}

/**
 * @brief 
 * This node replaces the data in a given index, but without deleting the node itself 
 * @param list 
 * @param index 
 * @param data 
 * @return ** void 
 */
void DLList_replaceDataByIndex(DLLIST list, int index, TYPE data)
{
    DLLISTNODE tmp = list->head;
    if(index < DLList_getSize(list) && index >= 0)
    {
        for (int i=0;i<index;i++)
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
 * Returns the list size
 * @param list 
 * @return ** int 
 */
int DLList_getSize(DLLIST list)
{
    return list->size;
}
