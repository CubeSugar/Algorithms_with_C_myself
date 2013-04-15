#include <stdlib.h>
#include <string.h>

#include "tree_binary.h"

/*------------------------------------------------------------------------------
 *name:         initBiTree()
 *arguments:    BiTree *tree, void (*destroy)(void *data)
 *return:       void
 *exception:
 *functions:    初始化二叉树
 *----------------------------------------------------------------------------*/
void initBiTree(BiTree *tree, void (*destroy)(void *data))
{
	tree->size    = 0;
	tree->destroy = NULL;
	tree->root    = NULL;
}

/*------------------------------------------------------------------------------
 *name:         destroyTree()
 *arguments:    BiTree *tree
 *return:       void
 *exception:
 *functions:    destroy BiTree
 *----------------------------------------------------------------------------*/
void destroyTree(BiTree *tree)
{
	removeTreeNodeLeft(tree, NULL);

	memset(tree, 0, sizeof(BiTree));
}

/*------------------------------------------------------------------------------
 *name:         insertTreeNodeLeft()
 *arguments:    BiTree *tree, BiTreeNode *node, const void *data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    二叉树中插入左子结点
 *----------------------------------------------------------------------------*/
int insertTreeNodeLeft(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *new_node, **position;

	if (node == NULL)
	{
		if (tree->size)
		{
			//only in an empty tree
			return -1;
		}

		//!!!!!!
		position = &tree->root;
	}
	else
	{
		if (node->left != NULL)
		{
			return -1;
		}
		//!!!!!!
		position = &node->left;
	}

	if ((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL)
	{
		return -1;
	}

	new_node->data  = (void *)data;
	new_node->left  = NULL;
	new_node->reght = NULL;
	*position       = new_node;//!!!!!!

	tree->size++;

	return 0;
}

/*------------------------------------------------------------------------------
 *name:         insertTreeNodeRight()
 *arguments:    BiTree *tree, BiTreeNode *node, const void *data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    二叉树中插入右子结点
 *----------------------------------------------------------------------------*/
int insertTreeNodeRight(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *new_node, **position;

	if (node == NULL)
	{
		if (tree->size)
		{
			return -1;
		}
		position = &tree->root;
	}
	else
	{
		if (node->right != NULL)
		{
			return -1;
		}
		position = &node->right;
	}

	if ((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL)
	{
		return -1;
	}

	new_node->data  = (void *)data;
	new_node->left  = NULL;
	new_node->right = NULL;
	*position       = new_node;

	tree->size++;
	return 0;
}

/*------------------------------------------------------------------------------
 *name:         removeTreeNodeLeft()
 *arguments:    BiTree *tree, BiTreeNode *node
 *return:       void
 *exception:
 *functions:    移除左子结点
 *----------------------------------------------------------------------------*/
void removeTreeNodeLeft(BiTree *tree, BiTreeNode *node)
{
	BiTreeNode **position;

	if (tree->size)
	{
		if (node == NULL)
		{
			position = &tree->root;
		}
		else
			position = &node->left;

		if (*position != NULL)
		{
			removeTreeNodeLeft(tree, *position);
			removeTreeNodeRight(tree, *position);

			if (tree->destroy != NULL)
			{
				tree->destroy((*position)->data);
			}

			free(*position);
			*position = NULL;////????????????

			tree->size--;
		}
	}
}

/*------------------------------------------------------------------------------
 *name:         removeTreeNodeRight()
 *arguments:    BiTree *tree, BiTreeNode *node
 *return:       void
 *exception:
 *functions:    移除右子结点
 *----------------------------------------------------------------------------*/
void removeTreeNodeRight(BiTree *tree, BiTreeNode *node)
{
	BiTreeNode **position;

	if (tree->size)
	{
		if (node == NULL)
		{
			position = &tree->root;
		}
		else
			position = &node->right;

		if (*position != NULL)
		{
			removeTreeNodeLeft(tree, *position);
			removeTreeNodeRight(tree, *position);

			if (tree->destroy != NULL)
			{
				tree->destroy((*position)->data);
			}

			free(*position);
			*position = NULL;////????????????

			tree->size--;
		}
	}
}

/*------------------------------------------------------------------------------
 *name:         mergeTree()
 *arguments:    BiTree *merge, BiTree *left, BiTree *right, const void *data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    合并两棵树
 *----------------------------------------------------------------------------*/
int mergeTree(BiTree *merge, BiTree *left, BiTree *right, const void *data)
{
	initBiTree(merge, left->destroy);

	if (insertTreeNodeLeft(merge, NULL, data) != 0)
	{
		destroyTree(merge);
		return -1;
	}

	merge->root->left  = left->root;
	merge->root->right = right->root;

	merge->size = merge->size + left->size + right->size;

	left->root  = NULL;
	left->size  = 0;
	right->root = NULL;
	right->size = 0;

	return 0;
}

/*------------------------------------------------------------------------------
 *name:         isTreeLeaf()
 *arguments:    const BiTreeNode *node
 *return:       succeeds 1, fails 0
 *exception:
 *functions:    判断是否为叶结点
 *----------------------------------------------------------------------------*/
int isTreeLeaf(const BiTreeNode *node)
{
	return (node->left == NULL) && (node->right == NULL);
}