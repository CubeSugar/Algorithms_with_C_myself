#ifndef QUENE_H
#define QUENE_H

#include <stdlib.h>

#include "list.h"

typedef List 	 Queue;
typedef ListElmt QueueElmt;

//public interface
/*------------------------------------------------------------------------------
 *name:         initQueue()
 *arguments:    Queue *queue, void (*destroy)(void *data)
 *return:       void
 *exception:
 *functions:    初始化队列
 -----------------------------------------------------------------------------*/
#define initQueue initList


/*------------------------------------------------------------------------------
 *name:         destroyQueue()
 *arguments:    Queue *queue
 *return:       void
 *exception:
 *functions:    销毁队列
 -----------------------------------------------------------------------------*/
#define destroyQueue destroyList


/*------------------------------------------------------------------------------
 *name:         enQueue()
 *arguments:    Queue *queue, const void *data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    队尾入队
 -----------------------------------------------------------------------------*/
int enQueue(Queue *queue, const void *data);


/*------------------------------------------------------------------------------
 *name:         deQueue()
 *arguments:    Queue *queue, void **data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    队头出队
 -----------------------------------------------------------------------------*/
int deQueue(Queue *queue, void **data);

#endif