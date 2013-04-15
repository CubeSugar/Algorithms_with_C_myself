#ifndef SET_H
#define SET_H

#include <stdlib.h>

#include "list.h"

typedef List Set;
typedef ListElmt SetElmt;

//public interface
/*------------------------------------------------------------------------------
 *name:         initSet()
 *arguments:    Set *set, 
                int (*match)(const void *key1,const void *key2), 
                void (*destroy)(void *data)
 *return:       void
 *exception:    
 *functions:    初始化集合
 *----------------------------------------------------------------------------*/
void initSet(Set *set, int (*match)(const void *key1,const void *key2),
             void (*destroy)(void *data));


/*------------------------------------------------------------------------------
 *name:         destroySet()
 *arguments:    Set *set
 *return:       void
 *exception:
 *functions:    销毁集合
 *----------------------------------------------------------------------------*/
#define destroySet destroyList


/*------------------------------------------------------------------------------
 *name:         insertSetElmt()
 *arguments:    Set *set, const void *data
 *return:       already exists 1, succeeds 0, fails -1
 *exception:
 *functions:    插入集合元素
 *----------------------------------------------------------------------------*/
int insertSetElmt(Set *set, const void *data);


/*------------------------------------------------------------------------------
 *name:         removeSetElmt()
 *arguments:    Set *set, void **data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    移除集合元素
 *----------------------------------------------------------------------------*/
int removeSetElmt(Set *set, void **data);


/*------------------------------------------------------------------------------
 *name:         unionSet()
 *arguments:    Set *set_u, const Set *set1, const Set *set2
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    合并两个集合
 *----------------------------------------------------------------------------*/
int unionSet(Set *set_u, const Set *set1, const Set *set2);


/*------------------------------------------------------------------------------
 *name:         intersectSet()
 *arguments:    Set *set_i, const Set *set1, const Set *set2
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    去两个集合交集
 *----------------------------------------------------------------------------*/
int intersectSet(Set *set_i, const Set *set1, const Set *set2);


/*------------------------------------------------------------------------------
 *name:         differSet()
 *arguments:    Set *set_d, const Set *set1, const Set *set2
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    set1 - set2 的差集
 *----------------------------------------------------------------------------*/
int differenceSet(Set *set_d, const Set *set1, const Set *set2);


/*------------------------------------------------------------------------------
 *name:         isSetMember()
 *arguments:    const Set *set, const void *data
 *return:       succeeds 1, fails 0
 *exception:
 *functions:    判定元素是否为集合成员
 *----------------------------------------------------------------------------*/
int isSetMember(const Set *set, const void *data);


/*------------------------------------------------------------------------------
 *name:         isSubSet()
 *arguments:    const Set *set1, const Set *set2
 *return:       succeeds 1, fails 0
 *exception:
 *functions:    判定set1是否是set2的子集
 *----------------------------------------------------------------------------*/
int isSubSet(const Set *set1, const Set *set2);


/*------------------------------------------------------------------------------
 *name:         isSetEqual()
 *arguments:    const Set *set1, const Set *set2
 *return:       succeeds 1, fails 0
 *exception:
 *functions:    判定两个集合是否相等
 *----------------------------------------------------------------------------*/
int isSetEqual(const Set *set1, const Set *set2);

#endif