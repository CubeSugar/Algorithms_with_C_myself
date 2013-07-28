#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "list.h"

/*------------------------------------------------------------------------------
 *name:         initList()
 *arguments:    List *list, void (*destroy)(void *data)
 *return:       void
 *exception:
 *functions:    初始化链表
 -----------------------------------------------------------------------------*/
void initList(List *list, void (*destroy)(void *data))
{
	list->size = NULL;
	list->head = NULL;
	list->tail = NULL;

	list->destroy = destroy;
}


/*------------------------------------------------------------------------------
 *name:         destroyList()
 *arguments:    List *list
 *return:       void
 *exception:
 *functions:    销毁链表
 -----------------------------------------------------------------------------*/
void destroyList(List *list)
{
	//元素数据域指针寄存
	void *data;

	//逐个删除链表element
	while(list->size > 0)
	{
		//removeListElmtNext()作为判断条件的一部分，每次都会执行。
		//若List初始化时指定了释放数据域指针空间的方法，则调用该方法释放数据域指针。
		if (removeListElmtNext(list, NULL, (void **)&data) == 0 && list->destroy != NULL)
		{
			//释放数据域指针空间
			list->destroy(data);
		}
		//若初始化方法中指定了缺省的释放方法，则可采用以下语句：
		//removeListElmtNext(list, NULL, (void **)&data);
		//list.destroy(data);
	}

	memset(list, 0, sizeof(List));
}

/*------------------------------------------------------------------------------
 *name:         insertListElmtNext()
 *arguments:    List *list, ListElmt *element, const void *data
 *return:       already exists 1, insert succeeds 0, fails -1
 *exception:
 *functions:    在list指定的链表中element后面插入一个新元素。如果element设置为NULL，则新
 *              元素插入链表头部。新元素包含一个指向data的指针，故只要该元素在链表中，data
 *              所引用的内存空间就应该保持合法。
 -----------------------------------------------------------------------------*/
int insertListElmtNext(List *list, ListElmt *element, const void *data)
{
	ListElmt *new_element;
	if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
	{
		return -1;
	}

	new_element->data = (void *)data;

	//插入链表头部
	if (element == NULL)
	{
		//若链表为空
		if (list->size == 0)
		{
			list->tail = new_element;
		}

		new_element->next = list->head;
		list->head = new_element;
	}
	else
	{
		//若插入位置为连表尾部
		if (element->next == NULL)
		{
			list->tail = new_element;
		}

		new_element->next = element->next;
		element->next = new_element;
	}

	//修改链表长度
	list->size++;
	return 0;
}

/*------------------------------------------------------------------------------
 *name:         removeListElmtNext()
 *arguments:    List *list, ListElmt *element, void **data
 *return:       remove succeeds 0, fails -1
 *exception:
 *functions:    移除由list指定的链表中element后的那个元素。如果element设置为NULL，则移除
 *              链表头元素。调用返回后，data指向已移除元素中存储的数据。
 -----------------------------------------------------------------------------*/
int removeListElmtNext(List *list, ListElmt *element, void **data)
{
	ListElmt *old_element;

	//链表为空时
	if (list->size == 0)	
	{
		return -1;
	}

	//链表非空时
	//删除头节点
	if (element == NULL)
	{
		//ListElmt结构类型的数据域为指针
		*data       = list->head->data;
		old_element = list->head;
		list->head  = list->head->next;

		if (list->size == 1)
		{
			list->tail = NULL;
		}
	}
	//删除非头节点
	else
	{
		//所给element为尾节点，无法删除后继节点
		if (element->next == NULL)
		{
			return -1;
		}

		//ListElmt结构类型的数据域为指针
		*data         = element->next->data;
		old_element   = element->next;
		element->next = element->next->next;

		//删除的时尾节点
		if (element->next == NULL)
		{
			list->tail = element;
		}
	}

	free(old_element);

	//修改链表长度
	list->size--;
	return 0;
}

/*------------------------------------------------------------------------------
 *name:         displayList()
 *arguments:    List *list
 *return:       0
 *exception:
 *functions:    显示列表元素
 *----------------------------------------------------------------------------*/
int displayList(List *list)
{
    return 0;
}
