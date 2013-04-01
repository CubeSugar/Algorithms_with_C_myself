#include "list.h"
#include "tree_traverse.h"

/*name:		preorderTree()
 *input:	const BiTreeNode *node, List *list
 *return:	success 0, failure -1
 *function: 先序遍历以node为根的树，并将当前节点node插入链表list
 */
int preorderTree(const BiTreeNode *node, List *list)
{
	if (node != NULL)
	{
		//将当前节点插入遍历结果链表list
		if (insertListElmtNext(list, list->tail, node->data) != 0)
		{
			return -1;
		}

		//递归遍历左子树
		if (node->left != NULL)
		{
			if (preorderTree(node->left, list) != 0)
			{
				return -1;
			}
		}

		//递归遍历右子树
		if (node->right != NULL)
		{
			if (preorderTree(node->right, list) != 0)
			{
				return -1;
			}
		}
	}

	return 0;
}

/*name:		inorderTree()
 *input:	const BiTreeNode *node, List *list
 *return:	success 0, failure -1
 *function:	中序遍历以node为根的树，并将当前节点node插入链表list
 */
int inorderTree(const BiTreeNode *node, List *list)
{
	if (node != NULL)
	{
		//递归遍历左子树
		if (node->left != NULL)
		{
			if (inorderTree(node->left, list) != 0)
			{
				return -1;
			}
		}

		//将当前节点插入遍历结果链表list
		if (insertListElmtNext(list, list->tail, node->data) != 0)
		{
			return -1;
		}

		//递归遍历右子树
		if (node->right != NULL)
		{
			if (inorderTree(node->right, list) != 0)
			{
				return -1;
			}
		}
	}

	return 0;

}

/*name:		postorderTree()
 *input:	cconst BiTreeNode *node, List *list
 *return:	success 0, failure -1
 *function:	后序遍历以node为根的树，并将当前节点node插入链表list
 */
int postorderTree(const BiTreeNode *node, List *list)
{
	if (node != NULL)
	{
		//递归遍历左子树
		if (node->left != NULL)
		{
			if (postorderTree(node->left, list) != 0)
			{
				return -1;
			}
		}

		//递归遍历右子树
		if (node->right != NULL)
		{
			if (postorderTree(node->right, list) != 0)
			{
				return -1;
			}
		}

		//将当前节点插入遍历结果链表list
		if (insertListElmtNext(list, list->tail, node->data) != 0)
		{
			return -1;
		}
	}

	return 0;
}