#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

//Define a structure for doubly-linked list elements
typedef struct DListElmt_
{
	//数据域是指针域
	void *data;
	struct DListElmt_ *next;
	struct DListElmt_ *prev;
} DListElmt;

//Define a structure for doubly-linked lists
typedef struct DList_
{
	//
	int size;
	int (*match)(const void *key1, const void *key2);
	//destroy()是释放数据域指针空间的方法
	void (*destroy)(void *data);
	DListElmt *head;
	DListElmt *tail;
} DList;

//public interface
/*------------------------------------------------------------------------------
 *name:         initDList()
 *arguments:    DList *dlist, void (*destroy)(void *data)
 *return:       void
 *exception:
 *functions:    初始化双向链表
 -----------------------------------------------------------------------------*/
void initDList(DList *dlist, void (*destroy)(void *data));


/*------------------------------------------------------------------------------
 *name:         destroyDList()
 *arguments:    DList *dlist
 *return:       void
 *exception:
 *functions:    销毁双向链表 
 -----------------------------------------------------------------------------*/
void destroyDList(DList *dlist);


/*------------------------------------------------------------------------------
 *name:         insertDListELmtNext()
 *arguments:    DList *dlist, DListElmt *delement, const void *data
 *return:       already exists 1, succeeds 0, fails -1
 *exception:
 *functions:    向双向链表中指定元素插入后继
 -----------------------------------------------------------------------------*/
int insertDListElmtNext(DList *dlist, DListElmt *delement, const void *data);


/*------------------------------------------------------------------------------
 *name:         insertDListELmtPrev()
 *arguments:    DList *dlist, DListElmt *delement, const void *data
 *return:       already exists 1, succeeds 0, fails -1
 *exception:
 *functions:    向双向链表中指定元素插入前驱
 -----------------------------------------------------------------------------*/
int insertDListElmtPrev(DList *dlist, DListElmt *delement, const void *data);


/*------------------------------------------------------------------------------
 *name:         removeDListElmt()
 *arguments:    DList *dlist, DListElmt *delement, void **data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    移除指定元素
 -----------------------------------------------------------------------------*/
int removeDListElmt(DList *dlist, DListElmt *delement, void **data);

#endif