#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "hash_chn_tbl.h"


/*------------------------------------------------------------------------------
 *name:         initChnTbl()
 *arguments:    ChnTbl *chntbl,
 int key_num,
 int (*hash)(const void *key)
 int (*match)(const void key1, const void *key2),
 void (*destroy)(void *data)
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    初始化哈希链表
 *----------------------------------------------------------------------------*/
int initChnTbl(ChnTbl *chntbl, int key_num,
               int (*hash)(const void *key),
               int (*match)(const void key1, const void *key2),
 			   void (*destroy)(void *data))
{
	if ((chntbl->kye_lists = (List *)malloc(key_num * sizeof(List))) == NULL)
	{
		return -1;
	}

	chntbl->key_num = key_num;

	for (int i = 0; i < key_num; ++i)
	{
		initList(&chntbl->key_lists[i], destroy);
	}

	chntbl->hash    = hash;
	chntbl->match   = match;
	chntbl->destroy = destroy;
	chntbl->size    = 0;

	return 0;
}


/*------------------------------------------------------------------------------
 *name:         destroyChnTbl()
 *arguments:    ChnTbl *chntbl
 *return:       void
 *exception:
 *functions:    销毁哈希链表
 *----------------------------------------------------------------------------*/
void destroyChnTbl(ChnTbl *chntbl)
{
	for (int i = 0; i < chntbl->key_num; ++i)
	{
		destroyList(&chntbl->key_lists[i]);
	}

	free(chntbl->key_lists);

	memset(chntbl, 0, sizeof(ChnTbl));
}


/*------------------------------------------------------------------------------
 *name:         insertChnTblElmt()
 *arguments:    ChnTbl *chntbl, const void *data
 *return:       already exists 1, succeeds 0, fails -1
 *exception:
 *functions:    向哈希链表中插入元素
 *----------------------------------------------------------------------------*/
int insertChnTblElmt(ChnTbl *chntbl, const void *data)
{
	void *temp;
	int key_temp, rtnval;

	temp = (void *)data;
	if (findChnTblElmt(chntbl, temp) == 0)
	{
		return 1;
	}

	key_temp = chntbl->hash(data) % chntbl->key_num;

	if ((rtnval = insertListElmtNext(&chntbl->key_lists[key_temp], NULL, data)) == 0)
	{
		chntbl->size++;
	}

	return rtnval;
}


/*------------------------------------------------------------------------------
 *name:         removeChnTblElmt()
 *arguments:    ChnTbl *chntbl, void **data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    从哈希链表中移除元素
 *----------------------------------------------------------------------------*/
int removeChnTblElmt(ChnTbl *chntbl, void **data)
{
	ListElmt *element, *prev;
	int key_temp;

	key_temp = chntbl->hash(*data) % chntbl->key_num;

	prev = NULL;

	for (element = &chntbl->key_lists[key_temp]->head;
         element != NULL;
         element = element->next)
	{
		if (chntbl->match(*data, element->data))
		{
			if (removeListElmtNext(&chntbl->key_lists[key_temp], prev, data) == 0)
			{
				chntbl->size--;
				return 0;
			}
			else
			{
				return -1;
			}
		}
		prev = element;
	}

	return -1;
}


/*------------------------------------------------------------------------------
 *name:         findChnTblElmt()
 *arguments:    const ChnTbl *chntbl, const void *target
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    在哈希链表中查找目标元素
 *----------------------------------------------------------------------------*/
int findChnTblELmt(const ChnTbl *chntbl, const void *target)
{
	ListElmt *element;
	int key_temp;

	key_temp = chntbl->hash(target) % chntbl->key_num;

	for (element = &chntbl->key_lists[key_temp]->head;
         element != NULL;
         element = element->next)
	{
		if (chntbl->match(target, element->data))
		{
			return 0;
		}
	}

	return -1;
}


/*------------------------------------------------------------------------------
 *name:         getChnTblElmt()
 *arguments:    const ChnTbl *chntbl, const void *target, void **data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    获取哈希链表中的元素
 *----------------------------------------------------------------------------*/
int getChnTblElmt(const ChnTbl *chntbl, const void *target, void **data)
{
	ListElmt *element;
	int key_temp;

	key_temp = chntbl->hash(target) % chntbl->key_num;

	for (element = &chntbl->key_lists[key_temp]->head;
         element != NULL;
         element = element->next)
	{
		if (chntbl->match(target, element->data))
		{
			*data = element->data;
			return 0;
		}
	}

	return -1;
}