#include <stdlib.h>
#include <string.h>

#include "clist.h"

//public interface
/*name:		initCList()
 *input:	Clist *clist, void (*destroy)(void *data)
 *
 *return:	none
 *
 *function:	初始化循环链表
 */
void initCList(Clist *clist, void (*destroy)(void *data))
{
	clist.size    = 0;
	clist.destroy = destroy;
	clist.head    = NULL;
}

/*name:	destroyCList()
 *input:	CList *clist
 *
 *return:	none
 *
 *function:	销毁循环链表
 */
void destroyCList(CList *clist)
{
	void *data;

 	while (clist.size > 0)
 	{
 		if (removeCListElmt(clist, clist.head, (void **)&data) == 0 && clist.destroy != NULL)
 		{
 			/* code */
 			clist.destroy(data);
 		}
 	}
 	
 	memset(clist, 0, sizeof(CList));
}

/*name:	insertCListElmt()
 *input:	CList *clist, CListElmt *celement, const void *data
 *
 *return:	success 0, false -1
 *
 *function:	在指定元素后插入新元素
 */
int insertCListElmt(CList *clist, CListElmt *celement, const void *data)
{
 	CListElmt *new_element;
 	if ((new_element = (CListElmt *)malloc(sizeof(CListElmt))) == NULL)
 	{
 		/* code */
 		return -1;
 	}

 	new_element.data = (void *)data;
 	if (clist.size == 0)
 	{
 		/* code */
 		new_element.next = new_element;
 		clist.head = new_element;
 	}
 	else
 	{
 		new_element.next = celement.next;
 		celement.next = new_element;
 	}

 	clist.size++;
 	return 0;
}

/*name:	removeCListElmt()
 *input:	CList *clist, CListElmt *celement, void **data
 *
 *return:	success 0, false -1
 *
 *function:	删除指定元素
 */
int removeCListElmtNext(CList *clist, CListElmt *celement, void **data)
{
	CListElmt *old_celement;

	if (clist.size == 0)
	{
		/* code */
		return -1;
	}

	*data = celement.

}