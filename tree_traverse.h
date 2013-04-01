#ifndef TREE_TRAVERSE_H
#define TREE_TRAVERSE_H

#include "tree_binary.h"
#include "list.h"

/*name:		preorderTree()
 *input:	const BiTreeNode *node, List *list
 *return:	success 0, failure -1
 *function: 先序遍历以node为根的树，并将当前节点node插入链表list
 */
int preorderTree(const BiTreeNode *node, List *list);

/*name:		inorderTree()
 *input:	const BiTreeNode *node, List *list
 *return:	success 0, failure -1
 *function:	中序遍历以node为根的树，并将当前节点node插入链表list
 */
int inorderTree(const BiTreeNode *node, List *list);

/*name:		postorderTree()
 *input:	cconst BiTreeNode *node, List *list
 *return:	success 0, failure -1
 *function:	后序遍历以node为根的树，并将当前节点node插入链表list
 */
int postorderTree(const BiTreeNode *node, List *list);

#endif