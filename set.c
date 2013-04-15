#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "set.h"

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
			 void (*destroy)(void *data))
{
	initList(set, destroy);
	set->match = match;
}


/*------------------------------------------------------------------------------
 *name:         insertSetElmt()
 *arguments:    Set *set, const void *data
 *return:       already exists 1, succeeds 0, fails -1
 *exception:
 *functions:    插入集合元素
 *----------------------------------------------------------------------------*/
int insertSetElmt(Set *set, const void *data)
{
	if (isSetMember(set, data))
	{
		return 1;
	}

	return insertListElmtNext(set, set->tail, data);
}


/*------------------------------------------------------------------------------
 *name:         removeSetElmt()
 *arguments:    Set *set, void **data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    移除集合元素
 *----------------------------------------------------------------------------*/
int removeSetElmt(Set *set, void **data)
{
	SetElmt *member, *prev;

	prev = NULL;

	for (member = set->head; member != NULL; member = member->next)
	{
		if (set->match(*data, member->data))
		{
			break;
		}
		prev = member;
	}

	if (member == NULL)
	{
		return -1;
	}

	return removeListElmtNext(set, prev, data);
}


/*------------------------------------------------------------------------------
 *name:         unionSet()
 *arguments:    Set *set_u, const Set *set1, const Set *set2
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    合并两个集合
 *----------------------------------------------------------------------------*/
int unionSet(Set *set_u, const Set *set1, const Set *set2)
{
	SetElmt *member;
	void *data;

	initSet(set_u, set1->match, NULL);

	for (member = set1->head; member != NULL; member = member->next)
	{
		data = member->data;
		if (insertListElmtNext(set_u, set_u->tail, data) != 0)
		{
			destroySet(set_u);
			return -1;
		}
	}

	for (member = set2->head; member != NULL; member = member->next)
	{
		if (isSetMember(set1, member->data))
		{
			continue;
		}
		else
		{
			data = member->data;
			if (insertListElmtNext(set_u, set_u->tail, data) != 0)
			{
				destroySet(set_u);
				return -1;
			}
		}
	}

	return 0;
}


/*------------------------------------------------------------------------------
 *name:         intersectSet()
 *arguments:    Set *set_i, const Set *set1, const Set *set2
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    去两个集合交集
 *----------------------------------------------------------------------------*/
int intersectSet(Set *set_i, const Set *set1, const Set *set2)
{
	SetElmt *member;
	void *data;

	initSet(set_i, set1->match, NULL);

	for (member = set1->head; member != NULL; member = member->next)
	{
		if (isSetMember(set2, member->data))
		{
			data = member->data;

			if (insertListElmtNext(set_i, set_i->tail, data) != 0)
			{
				destroySet(set_i);
				return -1;
			}
		}
	}

	return 0;
}


/*------------------------------------------------------------------------------
 *name:         differSet()
 *arguments:    Set *set_d, const Set *set1, const Set *set2
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    set1 - set2 的差集
 *----------------------------------------------------------------------------*/
int differSet(Set *set_d, const Set *set1, const Set *set2)
{
	SetElmt *member;
	void *data;

	initSet(set_d, set1->match, NULL);

	for (member = set1->head; member != NULL; member = member->next)
	{
		if (!isSetMember(set2, member->data))
		{
			data = member->data;

			if (insertListElmtNext(set_d, set_d->tail, data) != 0)
			{
				destroySet(set_d);
				return -1;
			}
		}
	}

	return 0;
}


/*------------------------------------------------------------------------------
 *name:         isSetMember()
 *arguments:    const Set *set, const void *data
 *return:       succeeds 1, fails 0
 *exception:
 *functions:    判定元素是否为集合成员
 *----------------------------------------------------------------------------*/
int isSetMember(const Set *set, const void *data)
{
	SetElmt *member;

	for (member = set->head; member != NULL; member = member->next)
	{
		if (set->match(data, member->data))
		{
			return 1;
		}
	}

	return 0;
}


/*------------------------------------------------------------------------------
 *name:         isSubSet()
 *arguments:    const Set *set1, const Set *set2
 *return:       succeeds 1, fails 0
 *exception:
 *functions:    判定set1是否是set2的子集
 *----------------------------------------------------------------------------*/
int isSubSet(const Set *set1, const Set *set2)
{
	SetElmt *member;

	if (set1->size > set2->size)
	{
		return 0;
	}

	for (member = set1->head; member != NULL; member = member->next)
	{
		if (!isSetMember(set2, member->data))
		{
			return 0;
		}
	}

	return 1;
}


/*------------------------------------------------------------------------------
 *name:         isSetEqual()
 *arguments:    const Set *set1, const Set *set2
 *return:       succeeds 1, fails 0
 *exception:
 *functions:    判定两个集合是否相等
 *----------------------------------------------------------------------------*/
int isSetEqual(const Set *set1, const Set *set2)
{
	if (set1->size != set2->size)
	{
		return 0;
	}
	
	return isSubSet(set1, set2); 
}