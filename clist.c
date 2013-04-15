#include <stdlib.h>
#include <string.h>

#include "clist.h"

//public interface
/*------------------------------------------------------------------------------
 *name:         initCList()
 *arguments:    CList *clist, void (*destroy)(void *data)
 *return:       void
 *exception:
 *functions:    初始化循环链表
 -----------------------------------------------------------------------------*/
void initCList(Clist *clist, void (*destroy)(void *data))
{
	clist->size    = 0;
	//未指定默认释放方法
	clist->destroy = destroy;
	clist->head    = NULL;
}

/*------------------------------------------------------------------------------
 *name:         destroyCList()
 *arguments:    CList *clist
 *return:       void
 *exception:
 *functions:    销毁循环链表
 -----------------------------------------------------------------------------*/
void destroyCList(CList *clist)
{
	void *data;

 	while (clist->size > 0)
 	{
 		if (removeCListElmtNext(clist, clist->head, (void **)&data) == 0
            && clist->destroy != NULL)
 		{
 			clist->destroy(data);
 		}
 	}
 	
 	memset(clist, 0, sizeof(CList));
}

/*------------------------------------------------------------------------------
 *name:         insertCListElmtNext()
 *arguments:    CList *clist, CListELmt *celement, const void *data
 *return:       already exists 1, succeeds 0, fails -1
 *exception:
 *functions:    在指定元素后插入新元素
 -----------------------------------------------------------------------------*/
int insertCListElmtNext(CList *clist, CListElmt *celement, const void *data)
{
 	CListElmt *new_element;
 	if ((new_element = (CListElmt *)malloc(sizeof(CListElmt))) == NULL)
 	{
 		return -1;
 	}

 	new_element->data = (void *)data;

 	if (clist->size == 0)
 	{
 		//循环链表为空时
 		new_element->next = new_element;
 		clist->head = new_element;
 	}
 	else
 	{
 		//非空时
 		new_element->next = celement->next;
 		celement->next = new_element;
 	}

 	clist->size++;
 	return 0;
}

/*------------------------------------------------------------------------------
 *name:         removeCListElmtNext()
 *arguments:    CList *clist, CListElmt *celement, void **data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    删除指定元素后继
 -----------------------------------------------------------------------------*/
int removeCListElmtNext(CList *clist, CListElmt *celement, void **data)
{
	CListElmt *old_celement;

	//防止在空链表中执行方法
	if (clist->size == 0)
	{
		return -1;
	}

	*data = celement->next->data;

	if (celement->next = celement)
	{
		//循环链表只有一个元素
		old_celement = celement->next;
		clist->head   = NULL;
	}
	else
	{
		old_celement  = celement->next;
		celement->next = celement->next->next;
		if (old_celement == clist->head)
		{
			//若celement为链表尾节点，则待删除节点为头节点
			clist->head = old_celement->next;
		}
	}

	free(old_celement);

	clist->size--;
	return 0;
}