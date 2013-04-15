#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

//define data type, e.g. int.
typedef int datatype;

//Define a structure for linked list elements.
typedef struct ListElmt_
{
	/* data */
	void *data;
	struct ListElmt_ *next;
} ListElmt;

//Define a structure for linked lists.
typedef struct List_
{
	int size;
	//判断2个成员是否匹配，若匹配返回1，否则返回0
	int (*match)(const void *key1, const void *key2);

	//释放数据域指针空间的方法，常用free
	void (*destroy)(void *data);
	ListElmt *head;
	ListElmt *tail;
} List;

//public interface
/*------------------------------------------------------------------------------
 *name:         initList()
 *arguments:    List *list, void (*destroy)(void *data)
 *return:       void
 *exception:
 *functions:    初始化链表
 -----------------------------------------------------------------------------*/
void initList(List *list, void (*destroy)(void *data));


/*------------------------------------------------------------------------------
 *name:         destroyList()
 *arguments:    List *list
 *return:       void
 *exception:
 *functions:    销毁链表
 -----------------------------------------------------------------------------*/
void destroyList(List *list);


/*------------------------------------------------------------------------------
 *name:         insertListElmtNext()
 *arguments:    List *list, ListElmt *element, const void *data
 *return:       already exists 1, insert succeeds 0, fails -1
 *exception:
 *functions:    在list指定的链表中element后面插入一个新元素。如果element设置为NULL，则新
 *              元素插入链表头部。新元素包含一个指向data的指针，故只要该元素在链表中，data
 *              所引用的内存空间就应该保持合法。
 -----------------------------------------------------------------------------*/
int insertListElmtNext(List *list, ListElmt *element, const void *data);


/*------------------------------------------------------------------------------
 *name:         removeListElmtNext()
 *arguments:    List *list, ListElmt *element, void **data
 *return:       remove succeeds 0, fails -1
 *exception:
 *functions:    移除由list指定的链表中element后的那个元素。如果element设置为NULL，则移除
 *              链表头元素。调用返回后，data指向已移除元素中存储的数据。
 -----------------------------------------------------------------------------*/
int removeListElmtNext(List *list, ListElmt *element, void **data);

#endif