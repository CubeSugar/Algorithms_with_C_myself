#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#include "list.h"

tpyedef List 	 Stack;
tpyedef ListElmt StackElmt;

//public interface
/*name:		iniStack()
 *input:	Stack *stack, void (*destroy)(void *data)
 *return:	none
 *function:	init stack
 */
#define initStack initList

/*name:		destroyStack()
 *input:	Stack *stack
 *return:	none
 *function:	destroy stack
 */
#define destroyStack destroyList

/*name:		pushStack()
 *input:	Stack *stack, const void *data
 *return:	success 0, false -1
 *function:	insert StackElmt at Stack top
 */
int pushStack(Stack *stack, const void *data);

/*name:		popStack()
 *input:	Stack *stack, void **data
 *return:	success 0, false -1
 *function:	return Stack top StackElmt
 */
int popStack(Stack *stack, void **data);

#endif
