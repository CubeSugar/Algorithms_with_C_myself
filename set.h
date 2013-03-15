#ifndef SET_H
#define SET_H

#include <stdlib.h>

#include "list.h"

typedef List Set;
typedef ListElmt SetElmt;

void initSet(Set *set, int (*match)(const void *key1,const void *key2), void (*destroy)(void *data));

#define destroySet destroyList

int insertSetElmt(Set *set, const void *data);

int removeSetElmt(Set *set, void **data);

int unionSet(Set *set_u, const Set *set1, const Set *set2);

int intersectionSet(Set *set_i, const Set *set1, const Set *set2);

int differenceSet(Set *set_d, const Set *set1, const Set *set2);

int isSetMember(const Set *set, const void *data);

int isSubSet(const Set *set1, const Set *set2);

int isSetEqual(const Set *set1, const Set *set2);

#endif