#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#include "list.h"

tpyedef List 	 Stack;
tpyedef ListElmt StackElmt;

//public interface
/*------------------------------------------------------------------------------
 *name:         initStack()
 *arguments:    Stack *stack, void (*destroy)(void *data)
 *return:       void
 *exception:
 *functions:    初始化栈
 -----------------------------------------------------------------------------*/
#define initStack initList


/*------------------------------------------------------------------------------
 *name:         destroyStack()
 *arguments:    Stack *stack
 *return:       void
 *exception:
 *functions:    销毁栈
 -----------------------------------------------------------------------------*/
#define destroyStack destroyList

/*------------------------------------------------------------------------------
 *name:         pushStackElmt()
 *arguments:    Stack *stack, const void *data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    将元素压栈
 -----------------------------------------------------------------------------*/
int pushStackElmt(Stack *stack, const void *data);


/*------------------------------------------------------------------------------
 *name:         popStackElmt()
 *arguments:    Stack *stack, void **data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    将元素弹栈
 -----------------------------------------------------------------------------*/
int popStackElmt(Stack *stack, void **data);

#endif
