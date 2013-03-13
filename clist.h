#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>

typedef struct CListElmt_
{
	/* data */
	void *data;
	struct CListElmt_ *next;
} CListElmt;

typedef struct CList_
{
	/* data */
	int size;
	int (*match)(const void *key1, const void *key2);
	void (*destroy)(void *data);
	CListElmt *head;
} CList;

//public interface
/*name:		initCList()
 *input:	Clist *clist, void (*destroy)(void *data)
 *
 *return:	none
 *
 *function:	初始化循环链表
 */
 void initCList(Clist *clist, void (*destroy)(void *data));

 /*name:	destroyCList()
 *input:	CList *clist
 *
 *return:	none
 *
 *function:	销毁循环链表
 */
 void destroyCList(CList *clist);

 /*name:	insertCListElmt()
 *input:	CList *clist, CListElmt *celement, const void *data
 *
 *return:	success 0, false -1
 *
 *function:	在指定元素后插入新元素
 */
 int insertCListElmt(CList *clist, CListElmt *celement, const void *data);

 /*name:	removeCListElmt()
 *input:	CList *clist, CListElmt *celement, void **data
 *
 *return:	success 0, false -1
 *
 *function:	删除指定元素
 */
 int removeCListElmt(CList *clist, CListElmt *celement, void **data);

 #endif