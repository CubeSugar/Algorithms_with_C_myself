#ifndef HASH_CHN_TBL_H
#define HASH_CHN_TBL_H

#include <stdlib.h>

#include <list.h>

//define a structure for chained hash tables - ChnTbl
tpyedef struct ChnTbl_
{
	//关键字个数
	int key_num;

	int (*hash)(const void *key);
	int (*match)(const void *key1, const void *key2);
	void (*destroy)(void *data);

	//现有元素个数
	int size;

	//关键字链表
	List *key_lists;
} ChnTbl;

//public interface


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
 			   void (*destroy)(void *data));


/*------------------------------------------------------------------------------
 *name:         destroyChnTbl()
 *arguments:    ChnTbl *chntbl
 *return:       void
 *exception:
 *functions:    销毁哈希链表
 *----------------------------------------------------------------------------*/
void destroyChnTbl(ChnTbl *chntbl);


/*------------------------------------------------------------------------------
 *name:         insertChnTblElmt()
 *arguments:    ChnTbl *chntbl, const void *data
 *return:       already exists 1, succeeds 0, fails -1
 *exception:
 *functions:    向哈希链表中插入元素
 *----------------------------------------------------------------------------*/
int insertChnTblElmt(ChnTbl *chntbl, const void *data);


/*------------------------------------------------------------------------------
 *name:         removeChnTblElmt()
 *arguments:    ChnTbl *chntbl, void **data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    从哈希链表中移除元素
 *----------------------------------------------------------------------------*/
int removeChnTblElmt(ChnTbl *chntbl, void **data);


/*------------------------------------------------------------------------------
 *name:         findChnTblElmt()
 *arguments:    const ChnTbl *chntbl, const void *target
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    在哈希链表中查找目标元素
 *----------------------------------------------------------------------------*/
int findChnTblELmt(const ChnTbl *chntbl, const void *target);


/*------------------------------------------------------------------------------
 *name:         getChnTblElmt()
 *arguments:    const ChnTbl *chntbl, const void *target, void **data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    获取哈希链表中的元素
 *----------------------------------------------------------------------------*/
int getChnTblElmt(const ChnTbl *chntbl, const void *target, void **data);

#endif