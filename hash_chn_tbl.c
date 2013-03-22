#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "hash_chn_tbl.h"


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
 			   void (*destroy)(void *data))
{
	if ((chntbl->kye_lists = (List *)malloc(key_num * sizeof(List))) == NULL)
	{
		return -1;
	}

	chntbl->key_num = key_num;

	for (int i = 0; i < key_num; ++i)
	{
		/* code */
		initList(&chntbl->key_lists[i], destroy);
	}

	chntbl->hash    = hash;
	chntbl->match   = match;
	chntbl->destroy = destroy;
	chntbl->size    = 0;

	return 0;
}

/*name:		destroyChnTbl()
 *input:	ChnTbl *chntbl
 *return:	none
 *function:	销毁哈希链表
 */
void destroyChnTbl(ChnTbl *chntbl)
{

}

/*name:		insertChnTblElmt()
 *input:	ChnTbl *chntbl, const void *data
 *return:	already exist 1, success 0, false -1
 *function:	向哈希链表中插入元素，若已存在该元素，返回1，若插入成功，返回0，若插入失败，返回-1
 */
int insertChnTblElmt(ChnTbl *chntbl, const void *data)
{

}

/*name:		removeChnTblElmt()
 *input:	ChnTbl *chntbl, void **data
 *return:	success 0, false -1
 *function:	从哈希链表中删除元素，删除成功，返回0，删除失败，返回-1
 */
int removeChnTblElmt(ChnTbl *chntbl, void **data)
{

}

/*name:		findChnTblElmt()
 *input:	const ChnTbl *chntbl, const void *target, void **data
 *return:	success 0, false -1
 *function:	在哈希链表中查找与target匹配的元素，若找到，将data只想哈希表中相匹配元素的数据域
 */
int findChnTblELmt(const ChnTbl *chntbl, const void *target, void **data)
{

}