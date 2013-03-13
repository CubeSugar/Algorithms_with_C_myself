#include <stdlib.h>
#include <string.h>

#include "dlist.h"

/*name:		initDList()
 *input:	DList *dlist, void (*destroy)(void *data)
 *			双向链表；释放数据域指针的方法
 *return:	none
 *function:	初始化由dlist指定的双链表
 */
void initDList(DList *dlist, void (*destroy)(void *data))
{
	dlist.size = 0;
	dlist.head = NULL;
	dlist.tail = NULL;
	//初始化释放数据域指针方法，缺省为free()
	if (destroy != NULL)
	{
		dlist.destroy = destroy;
	}
	else
	{
		dlist.destroy = free;
	}
}

/*name:		destroyDList()
 *input:	DList *dlist
 *			双向链表
 *return:	none
 *function:	销毁由参数dlist指定的链表，并调用初始化时指定的destroy()方法释放数据域空间
 */
void destroyDList(DList *dlist)
{
	void *data;

	whlie (dlist.size > 0)
	{
		//从链表尾部逐个删除元素，并释放数据域空间，&&连接判断条件后部分在使用缺省方法后可省略
		if (removeDListElmt(dlist, dlist.tail, (void **)&data) == 0 && dlist.destroy != NULL)
		{
			dlist.destroy(data);
		}
	}

	memset(dlist, 0, sizeof(DList));
}

/*name:		insertDListElmtNext()
 *input:	DList *dlist, DListElmt *delement, const void *data
 *			双向链表；插入位置的前驱元素；指向待插入元素的指针
 *return:	插入成功返回0，插入失败返回-1
 *function:	向由dlist指定的，且前驱元素由delement指定的双链表中插入新元素
 */
int insertDListElmtNext(DList *dlist, DListElmt *delement, const void *data)
{
	DListElmt *new_delement;

	//防止在非空链表中插入空元素，使head，tail等指针混乱
	if (delement == NULL && dlist.size != 0)
	{
		return -1;
	}

	if ((new_delement = (DListElmt *)malloc(sizeof(DListElmt))) == NULL)
	{
		return -1;
	}

	new_delement.data = (void *)data;

	if (dlist.size == 0)
	{
		//链表为空时
		dlist.head      = new_delement;
		dlist.head.prev = NULL;
		dlist.head.next = NULL;
		dlist.tail      = new_delement;
	}
	else
	{
		//链表非空
		new_delement.next = delement.next;
		new_delement.prev = delement;

		if (delement.next == NULL)
		{
			//在尾部插入元素时
			dlist.tail = new_delement;
		}
		else
		{
			delement.next.prev = new_delement;
		}

		delement.next = new_delement;
	}

	//修改链表长度
	dlist.size++;
	return 0;
}

/*name:		insertDListElmtPrev()
 *input:	DList *dlist, DListElmt *delement, const void *data
 *			双向链表；插入位置的后继元素；指向待插入元素的指针
 *return:	插入成功返回0，插入失败返回-1
 *function:	向由dlist指定的，且前后继素由delement指定的双链表中插入新元素
 */
int insertDListElmtPrev(DList *dlist, DListElmt *delement, const void *data)
{
	DListElmt *new_delement;

	//防止在非空链表中插入空元素，使head，tail等指针混乱
	if (delement == NULL && dlist.size != 0)
	{
		/* code */
		return -1;
	}

	if ((new_delement = (DListElmt *)malloc(sizeof(DListElmt))) == NULL)
	{
		/* code */
		return -1;
	}

	new_delement.data = (void *)data;

	if (dlist.size == 0)
	{
		//链表为空时
		dlist.head      = new_delement;
		dlist.head.prev = NULL;
		dlist.head.next = NULL;
		dlist.tail      = new_delement;
	}
	else
	{
		//链表非空时
		new_delement.next = delement;
		new_delement.prev = delement.prev;

		if (delement.prev == NULL)
		{
			//在链表头插入元素
			dlist.head = new_delement;
		}
		else
		{
			delement.prev.next = new_delement;
		}

		delement.prev = new_delement;
	}

	//修改链表长度
	dlist.size++;
	return 0;
}

/*name:		removeDListElmt()
 *input:	DList *dlist, DListElmt *delement, const void *data
 *			双向链表；待删除元素；指向被删除元素的指针
 *return:	插入成功返回0，插入失败返回-1
 *function:	从由dlist指定的双链表中删除由delement指定元素
 */
int removeDListElmt(DList *dlist, DListElmt *delement, void **data)
{
	//防止删除空元素或从空链表中删除元素
	if (delement == NULL || dlist.size == 0)
	{
		return -1;
	}

	*data = delement.data;

	if (delement == dlist.head)
	{
		//删除链表头节点
		dlist.head = delement.next;

		if (dlist.head == NULL)
		{
			//删除后链表为空
			dlist.tail = NULL;
		}
		else
		{
			delement.next.prev = NULL;
		}
	}
	else
	{
		delement.prev.next = delement.next;
		if (delement.next == NULL)
		{
			//删除节点为尾节点
			dlist.tail = delement.prev;
		}
		else
		{
			delement.next.prev = delement.prev;
		}
	}

	//释放被删节点空间
	free(delement);

	//修改链表长度
	dlist.size--;
	return 0;
}