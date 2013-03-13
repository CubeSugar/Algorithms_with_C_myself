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
	/* data */
	int size;
	int (*match)(const void *key1, const void *key2);

	//释放数据域指针空间的方法，常用free
	void (*destroy)(void *data);
	ListElmt *head;
	ListElmt *tail;
} List;

//public interface
/*name:		initList()
 *input:	List *list, void (*destroy)(void *data)
 *return:	none
 *function:	初始化参数List指定的列表。
 */
void initList(List *list, void (*destroy)(void *data));

/*name:		destroyList()
 *input:	List *list
 *return:	none
 *function:	销毁由参数list指定的链表。
 */
void destroyList(List *list);

/*name:		insertElmt()
 *input:	List *list, ListElmt *element, const void *data
 *return:	插入成功返回0，否则返回-1。
 *function:	在list指定的链表中element后面插入一个新元素。
 *			如果element设置为NULL，则新元素插入链表头部。
 *			新元素包含一个指向data的指针，故只要该元素在链表中，data所引用的内存空间就应该保持合法。
 */
int insertElmt(List *list, ListElmt *element, const void *data);

/*name:		removerElmt()
 *input:	List *list, ListElmt *element, void **data
 *return:	移除成功返回0，否则返回-1。
 *function:	移除由list指定的链表中element后的那个元素。
 *			如果element设置为NULL，则移除链表头元素。
 *			调用返回后，data指向已移除元素中存储的数据。
 */
int removeElmt(List *list, ListElmt *element, void **data);

#endif