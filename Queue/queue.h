/**
 * @file queue.h
 * @author Omar Chavira (ochavirar@outlook.com)
 * @brief 
 * This file contains the strcuture of the main node "queue" and the declaration of all the related functions
 * @version 0.1
 * @date 2021-12-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "datatypes.h"
#include <stdio.h>

#ifndef STACK_H_
#define STACK_H_

/**
 * @brief 
 * Main node structure for the queue
 */
struct STRQUEUE
{
    QUEUENODE first, last;
    int size;
};

typedef struct STRQUEUE *QUEUE;

/**
 * @brief 
 * 
 * Fucntions declaration 
 */
QUEUE queue_create();
void queue_offer(QUEUE, TYPE);
TYPE queue_poll(QUEUE);
int queue_size(QUEUE);
BOOL queue_isEmpty(QUEUE);
TYPE queue_peek(QUEUE);
void queue_destroy(QUEUE);
#endif //STACK_H_