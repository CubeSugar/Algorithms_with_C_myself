#include <stdlib.h>

#include "list.h"
#include "stack.h"

/*name:		pushStack()
 *input:	Stack *stack, const void *data
 *return:	success 0, false -1
 *function:	insert StackElmt at Stack top
 */
int pushStack(Stack *stack, const void *data)
{
	return insertListElmtNext(stack, NULL, data);
}

/*name:		popStack()
 *input:	Stack *stack, void **data
 *return:	success 0, false -1
 *function:	return Stack top StackElmt
 */
int popStack(Stack *stack, void **data)
{
	return removeListElmtNext(stack, NULL, data);
}