#include <stdlib.h>

#include "list.h"
#include "queue.h"

/*------------------------------------------------------------------------------
 *name:         enQueue()
 *arguments:    Queue *queue, const void *data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    队尾入队
 -----------------------------------------------------------------------------*/
int enQueue(Queue *queue, const void *data)
{
	return insertListElmtNext(queue, queue->tail, data);
}

/*------------------------------------------------------------------------------
 *name:         deQueue()
 *arguments:    Queue *queue, void **data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    队头出队
 -----------------------------------------------------------------------------*/
int deQueue(Queue *queue, void **data)
{
	return removeListElmtNext(queue, NULL, data);
}