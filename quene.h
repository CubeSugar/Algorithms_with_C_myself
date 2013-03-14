#ifndef QUENE_H
#define QUENE_H

#include <stdlib.h>

#include "list.h"

typedef List 	 Queue;
typedef ListElmt QueueElmt;

//public interface
/*name:		initQueue
 *input:	Queue *queue, void (*destroy)(void *data)
 *return:	none
 *function:	init Queue
 */
#define initQueue initList

/*name:		destroyQueue
 *input:	Queue *queue
 *return:	none
 *function:	destroy Queue
 */
#define destroyQueue destroyList

/*name:		enQueue()
 *input:	Queue *queue, const void *data
 *return:	success 0, false -1
 *function:	enter QueueElmt at Queue tail
 */
int enQueue(Queue *queue, const void *data);

/*name:		deQueue()
 *input:	Queue *queue, void **data
 *return:	success 0, false -1
 *function:	delete QueueElmt at Queue head
 */
int deQueue(Queue *queue, void **data);

#endif