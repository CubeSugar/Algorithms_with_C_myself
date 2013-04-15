#include <stdlib.h>

#include "list.h"
#include "stack.h"

/*------------------------------------------------------------------------------
 *name:         pushStackElmt()
 *arguments:    Stack *stack, const void *data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    将元素压栈
 *----------------------------------------------------------------------------*/
int pushStackElmt(Stack *stack, const void *data)
{
	return insertListElmtNext(stack, NULL, data);
}

/*------------------------------------------------------------------------------
 *name:         popStackElmt()
 *arguments:    Stack *stack, void **data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    将元素弹栈
 *----------------------------------------------------------------------------*/
int popStackElmt(Stack *stack, void **data)
{
	return removeListElmtNext(stack, NULL, data);
}