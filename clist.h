#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>

typedef struct CListElmt_
{
	void *data;
	struct CListElmt_ *next;
} CListElmt;

typedef struct CList_
{
	int size;
	int (*match)(const void *key1, const void *key2);
	void (*destroy)(void *data);
	CListElmt *head;
} CList;

//public interface
/*------------------------------------------------------------------------------
 *name:         initCList()
 *arguments:    CList *clist, void (*destroy)(void *data)
 *return:       void
 *exception:
 *functions:    初始化循环链表
 -----------------------------------------------------------------------------*/
void initCList(CList *clist, void (*destroy)(void *data));


/*------------------------------------------------------------------------------
 *name:         destroyCList()
 *arguments:    CList *clist
 *return:       void
 *exception:
 *functions:    销毁循环链表
 -----------------------------------------------------------------------------*/
void destroyCList(CList *clist);


/*------------------------------------------------------------------------------
 *name:         insertCListElmtNext()
 *arguments:    CList *clist, CListELmt *celement, const void *data
 *return:       already exists 1, succeeds 0, fails -1
 *exception:
 *functions:    在指定元素后插入新元素
 -----------------------------------------------------------------------------*/
int insertCListElmtNext(CList *clist, CListElmt *celement, const void *data);


/*------------------------------------------------------------------------------
 *name:         removeCListElmtNext()
 *arguments:    CList *clist, CListElmt *celement, void **data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    删除指定元素后继
 -----------------------------------------------------------------------------*/
int removeCListElmtNext(CList *clist, CListElmt *celement, void **data);

#endif