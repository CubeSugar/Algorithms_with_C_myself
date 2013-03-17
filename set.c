#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "set.h"

/*name:		initSet()
 *input:	Set *set, int (*match)(const void *key1,const void *key2), void (*destroy)(void *data)
 *			集合；匹配方法；销毁方法
 *return:	none
 *function:	initial Set
 *
 */
void initSet(Set *set, int (*match)(const void *key1,const void *key2), void (*destroy)(void *data))
{
	initList(set, destroy);
	set.match = match;
}

/*name:		insertSetElmt()
 *input:	Set *set, const void *data
 *return:	success 0, false -1
 *function:	insert Set Element
 *
 */
int insertSetElmt(Set *set, const void *data)
{
	if (isSetMember(set, data))
	{
		return -1;
	}
}

/*name:		removeSetElmt()
 *input:	Set *set, void **data
 *return:	success 0, false -1
 *function:	remove ELement form Set
 *
 */
int removeSetElmt(Set *set, void **data);

/*name:		unionSet()
 *input:	Set *set_u, const Set *set1, const Set *set2
 *return:	success 0, false -1
 *function
 *
 */
int unionSet(Set *set_u, const Set *set1, const Set *set2);

/*name:		intersectionSet()
 *input:	Set *set_i, const Set *set1, const Set *set2
 *return:	success 0, false -1
 *function
 *
 */
int intersectionSet(Set *set_i, const Set *set1, const Set *set2);

/*name:		differenceSet()
 *input:	Set *set_d, const Set *set1, const Set *set2
 *return:	success 0, false -1
 *function
 *
 */
int differenceSet(Set *set_d, const Set *set1, const Set *set2);

/*name:		isSetMember()
 *input:	const Set *set, const void *data
 *return:	success 0, false -1
 *function
 *
 */
int isSetMember(const Set *set, const void *data);

/*name:		isSubSet()
 *input:	const Set *set1, const Set *set2
 *return:	success 0, false -1
 *function
 *
 */
int isSubSet(const Set *set1, const Set *set2);

/*name:		isSetEqual()
 *input:	const Set *set1, const Set *set2
 *return:	success 0, false -1
 *function
 *
 */
int isSetEqual(const Set *set1, const Set *set2);