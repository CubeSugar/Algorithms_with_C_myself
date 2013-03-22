#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "set.h"

/*name:		initSet()
 *input:	Set *set, int (*match)(const void *key1,const void *key2), void (*destroy)(void *data)
 *			集合；匹配方法（匹配返回1，否则0）；销毁方法
 *return:	none
 *function:	initial Set
 *
 */
void initSet(Set *set, int (*match)(const void *key1,const void *key2), void (*destroy)(void *data))
{
	initList(set, destroy);
	set->match = match;
}

/*name:		insertSetElmt()
 *input:	Set *set, const void *data
 *return:	already exist 1，insert success 0, false -1
 *function:	insert Set Element
 *
 */
int insertSetElmt(Set *set, const void *data)
{
	if (isSetMember(set, data))
	{
		return 1;
	}

	return insertListElmtNext(set, set->tail, data);
}

/*name:		removeSetElmt()
 *input:	Set *set, void **data
 *return:	success 0, false -1
 *function:	remove ELement form Set
 *
 */
int removeSetElmt(Set *set, void **data)
{
	SetElmt *member, *prev;

	prev = NULL;

	for (member = set->head; member != NULL; member = member->next)
	{
		/* code */
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

/*name:		unionSet()
 *input:	Set *set_u, const Set *set1, const Set *set2
 *return:	success 0, false -1
 *function
 *
 */
int unionSet(Set *set_u, const Set *set1, const Set *set2)
{
	SetElmt *member;
	void *data;

	initSet(set_u, set1->match, NULL);

	for (member = set1->head; member != NULL; member = member->next)
	{
		/* code */
		data = member->data;
		if (insertListElmtNext(set_u, set_u->tail, data) != 0)
		{
			/* code */
			destroySet(set_u);
			return -1;
		}
	}

	for (member = set2->head; member != NULL; member = member->next)
	{
		/* code */
		if (isSetMember(set1, member->data))
		{
			/* code */
			continue;
		}
		else
		{
			data = member->data;
			if (insertListElmtNext(set_u, set_u->tail, data) != 0)
			{
				/* code */
				destroySet(set_u);
				return -1;
			}
		}
	}

	return 0;
}

/*name:		intersectionSet()
 *input:	Set *set_i, const Set *set1, const Set *set2
 *return:	success 0, false -1
 *function
 *
 */
int intersectionSet(Set *set_i, const Set *set1, const Set *set2)
{
	SetElmt *member;
	void *data;

	initSet(set_i, set1->match, NULL);

	for (member = set1->head; member != NULL; member = member->next)
	{
		/* code */
		if (isSetMember(set2, member->data))
		{
			/* code */
			data = member->data;

			if (insertListElmtNext(set_i, set_i->tail, data) != 0)
			{
				/* code */
				destroySet(set_i);
				return -1;
			}
		}
	}

	return 0;
}

/*name:		differenceSet()
 *input:	Set *set_d, const Set *set1, const Set *set2
 *return:	success 0, false -1
 *function
 *
 */
int differenceSet(Set *set_d, const Set *set1, const Set *set2)
{
	SetElmt *member;
	void *data;

	initSet(set_d, set1->match, NULL);

	for (member = set1->head; member != NULL; member = member->next)
	{
		/* code */
		if (!isSetMember(set2, member->data))
		{
			/* code */
			data = member->data;

			if (insertListElmtNext(set_d, set_d->tail, data) != 0)
			{
				/* code */
				destroySet(set_d);
				return -1;
			}
		}
	}

	return 0;
}

/*name:		isSetMember()
 *input:	const Set *set, const void *data
 *return:	success 1, false 0
 *function
 *
 */
int isSetMember(const Set *set, const void *data)
{
	SetElmt *member;

	for (member = set->head; member != NULL; member = member->next)
	{
		/* code */
		if (set->match(data, member->data))
		{
			//!!!!!
			return 1;
		}
	}

	return 0;
}

/*name:		isSubSet()
 *input:	const Set *set1, const Set *set2
 *return:	success 1, false 0
 *function:	set1是否是set2的子集
 *
 */
int isSubSet(const Set *set1, const Set *set2)
{
	SetElmt *member;

	if (set1->size > set2->size)
	{
		/* code */
		return 0;
	}

	for (member = set1->head; member != NULL; member = member->next)
	{
		/* code */
		if (!isSetMember(set2, member->data))
		{
			/* code */
			return 0;
		}
	}

	return 1;
}

/*name:		isSetEqual()
 *input:	const Set *set1, const Set *set2
 *return:	success 1, false 0
 *function
 *
 */
int isSetEqual(const Set *set1, const Set *set2)
{
	if (set1->size != set2->size)
	{
		/* code */
		return 0;
	}

	return isSubSet(set1, set2); 
}