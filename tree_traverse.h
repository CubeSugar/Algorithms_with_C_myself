#ifndef TREE_TRAVERSE_H
#define TREE_TRAVERSE_H

#include "tree_binary.h"
#include "list.h"


/*------------------------------------------------------------------------------
 *name:         preorderTree()
 *arguments:    const BiTreeNode *node, List *list
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    先序遍历以node为根的树，并将当前遍历结点node插入链表
 *----------------------------------------------------------------------------*/
int preorderTree(const BiTreeNode *node, List *list);


/*------------------------------------------------------------------------------
 *name:         inorderTree()
 *arguments:    const BiTreeNode *node, List *list
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    中序遍历以node为根的树，并将当前遍历结点node插入链表
 *----------------------------------------------------------------------------*/
int inorderTree(const BiTreeNode *node, List *list);


/*------------------------------------------------------------------------------
 *name:         postorderTree()
 *arguments:    const BiTreeNode *node, List *list
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    后续遍历以node为根的树，并将当前遍历结点node插入链表
 *----------------------------------------------------------------------------*/
int postorderTree(const BiTreeNode *node, List *list);

#endif