/**
 * @file queue.c
 * @author Omar Chavira (ochavirar@outlook.com)
 * @brief 
 * Thois files contains the definition of all the related functions to the queue data structure
 * @version 0.1
 * @date 2021-12-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "queue.h"
#include <stdlib.h>

/**
 * @brief 
 * This functions reserves space in memory for a new main node to create a queue
 * @return ** QUEUE 
 */
QUEUE queue_create()
{
    QUEUE temp = malloc(sizeof(struct STRQUEUE));
    temp->first = NULL;
    temp->last = NULL;
    temp->size = 0;
    return temp;
}

/**
 * @brief 
 * This function adds a value to the queue data structure, as well as modifying the "last and "first" parameters.
 * A new node is created, data is stored within the node and finally some changes in parameters are made.
 * If the queue is empty, the "first" parameter is modified. Otherwise, the parameter "last" is used to add a node at the end of the queue.
 * Finally, the size gets increased.
 * @param queue 
 * @param data 
 * @return ** void 
 */
void queue_offer(QUEUE queue, TYPE data)
{
    QUEUENODE newNode = malloc(sizeof(struct STRQUEUENODE)); 
    newNode->next = NULL;
    newNode->data = data; //Obtain data
    if(queue->first == NULL)
        queue->first = newNode;
    else
        queue->last->next = newNode;
    
    queue->last = newNode;
    queue->size++;
}

/**
 * @brief 
 * A queue is received to obtain the data stored in it, as well as deleting that node itself from the queue.
 * A support node is used to eliminate the node from which the content is obtained.
 * Finally, the size gets decreased.
 * @param queue 
 * @return ** TYPE 
 */
TYPE queue_poll(QUEUE queue)
{
    TYPE retval;
    QUEUENODE supportNode = malloc(sizeof(struct STRQUEUENODE));
    supportNode = queue->first;
    if(supportNode != NULL)
    {
        retval = queue->first->data;
        queue->first = queue->first->next;
        queue->size--;
        free(supportNode);

        if(queue->first == NULL)
            queue->last = NULL;
    }
    
    return retval;
}

/**
 * @brief 
 * Shortcutu funtion to access the size parameter that is contained within the queue node
 * @param queue 
 * @return ** int 
 */
int queue_size(QUEUE queue)
{
    return queue->size;
}

/**
 * @brief 
 * Boolean value to check if the queue has any value stored
 * @param queue 
 * @return ** BOOL 
 */
BOOL queue_isEmpty(QUEUE queue)
{
    return(queue->size == 0);
}

/**
 * @brief 
 * Function to get the data withing the first node without deleting it
 * @param queue 
 * @return ** TYPE 
 */
TYPE queue_peek(QUEUE queue)
{
    TYPE retval = queue->first->data;
    return retval;
}

/**
 * @brief 
 * Use of poll function to delete every node.
 * Finally, main node "queue" gets deleted.
 * @param queue 
 * @return ** void 
 */
void queue_destroy(QUEUE queue)
{
    while(queue->first != NULL)
    {
        queue_poll(queue);
    }
    free(queue);
}