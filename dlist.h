#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

//Define a structure for doubly-linked list elements
typedef struct DListElmt_
{
	//数据域是指针域
	void *data;
	DListElmt_ *next;
	DListElmt_ *prev;
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
/*name:		initDList()
 *input:	DList *dlist, void (*destroy)(void *data)
 *			双向链表；释放数据域指针的方法
 *return:	none
 *function:	初始化由dlist指定的双链表
 */
void initDList(DList *dlist, void (*destroy)(void *data));

/*name:		destroyDList()
 *input:	DList *dlist
 *			双向链表
 *return:	none
 *function:	销毁由参数dlist指定的链表，并调用初始化时指定的destroy()方法释放数据域空间
 */
void destroyDList(DList *dlist);

/*name:		insertDListElmtNext()
 *input:	DList *dlist, DListElmt *delement, const void *data
 *			双向链表；插入位置的前驱元素；指向待插入元素的指针
 *return:	插入成功返回0，插入失败返回-1
 *function:	向由dlist指定的，且前驱元素由delement指定的双链表中插入新元素
 */
int insertDListElmtNext(DList *dlist, DListElmt *delement, const void *data);

/*name:		insertDListElmtPrev()
 *input:	DList *dlist, DListElmt *delement, const void *data
 *			双向链表；插入位置的后继元素；指向待插入元素的指针
 *return:	插入成功返回0，插入失败返回-1
 *function:	向由dlist指定的，且前后继素由delement指定的双链表中插入新元素
 */
int insertDListElmtPrev(DList *dlist, DListElmt *delement, const void *data);

/*name:		removeDListElmt()
 *input:	DList *dlist, DListElmt *delement, const void *data
 *			双向链表；待删除元素；指向被删除元素的指针
 *return:	插入成功返回0，插入失败返回-1
 *function:	从由dlist指定的双链表中删除由delement指定元素
 */
int removeDListElmt(DList *dlist, DListElmt *delement, void **data);

#endif