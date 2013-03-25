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

/*name:		initChnTbl()
 *input:	ChnTbl *chntbl
			//hash链表
 			int key_num
			//关键字个数
            int (*hash)(const void *key)
            //哈希方法
            int (*match)(const void key1, const void *key2)
            //元素匹配方法
 			void (*destroy)(void *data)
 			//元素销毁方法
 *return:	success 0, false -1;
 *function:	初始化哈希链表
 */
int initChnTbl(ChnTbl *chntbl, int key_num,
               int (*hash)(const void *key),
               int (*match)(const void key1, const void *key2),
 			   void (*destroy)(void *data));

/*name:		destroyChnTbl()
 *input:	ChnTbl *chntbl
 *return:	none
 *function:	销毁哈希链表
 */
void destroyChnTbl(ChnTbl *chntbl);

/*name:		insertChnTblElmt()
 *input:	ChnTbl *chntbl, const void *data
 *return:	already exist 1, success 0, false -1
 *function:	向哈希链表中插入元素，若已存在该元素，返回1，若插入成功，返回0，若插入失败，返回-1
 */
int insertChnTblElmt(ChnTbl *chntbl, const void *data);

/*name:		removeChnTblElmt()
 *input:	ChnTbl *chntbl, void **data
 *return:	success 0, false -1
 *function:	从哈希链表中删除元素，删除成功，返回0，删除失败，返回-1
 */
int removeChnTblElmt(ChnTbl *chntbl, void **data);

/*name:		findChnTblElmt()
 *input:	const ChnTbl *chntbl, const void *target
 *return:	success 0, false -1
 *function:	在哈希链表中查找与target匹配的元素
 */
int findChnTblELmt(const ChnTbl *chntbl, const void *target);

/*name:		getChnTblElmt()
 *input:	const ChnTbl *chntbl, const void *target, void **data
 *return:	success 0, false -1
 *function:	在哈希链表中查找与target匹配的元素，若找到，将data哈希表中相匹配元素的数据域
 */
int getChnTblElmt(const ChnTbl *chntbl, const void *target, void **data);

#endif