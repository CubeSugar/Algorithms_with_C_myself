#include <stdlib.h>

#include "list.h"
#include "queue.h"

/*name:		enQueue()
 *input:	Queue *queue, const void *data
 *return:	success 0, false -1
 *function:	enter QueueElmt at Queue tail
 */
int enQueue(Queue *queue, const void *data)
{
	return insertListElmtNext(queue, queue->tail, data);
}

/*name:		deQueue()
 *input:	Queue *queue, void **data
 *return:	success 0, false -1
 *function:	delete QueueElmt at Queue head
 */
int deQueue(Queue *queue, void **data)
{
	return removeListElmtNext(queue, NULL, data);
}