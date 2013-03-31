#include <stdlib.h>
#include <string.h>

#include "tree_binary.h"

/*name:		initBiTree()
 *input:	BiTree *tree, void (*destroy)(void *data)
 *return:	none
 *function:	initiate BiTree
 */
void initBiTree(BiTree *tree, void (*destroy)(void *data))
{
	tree->size    = 0;
	tree->destroy = NULL;
	tree->root    = NULL;
}

/*name:		destroyTree()
 *input:	BiTree *tree
 *return:	none
 *function:	destroy BiTree
 */
void destroyTree(BiTree *tree)
{
	removeTreeNodeLeft(tree, NULL);

	memset(tree, 0, sizeof(BiTree));
}

/*name:		insertTreeNodeLeft()
 *input:	BiTree *tree, BiTreeNode *node, const void *data
 *return:	success 0, false -1
 *function:	向指定节点插入左节点，若指定节点为NULL，且为空树，则将插入节点设为root
 */
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

/*name:		insertTreeNodeRight()
 *input:	BiTree *tree, BiTreeNode *node, const void *data
 *return:	success 0, false -1
 *function:	insert TreeNode Right child
 */
int insertTreeNodeRight(BiTree *tree, BiTreeNode *node, const void *data);

/*name:		removeTreeNodeLeft()
 *input:	BiTree *tree, BiTreeNode *node
 *return:	none
 *function:	remove TreeNode LeftTree
 */
void removeTreeNodeLeft(BiTree *tree, BiTreeNode *node);

/*name:		removeTreeNodeRight()
 *input:	BiTree *tree, BiTreeNode *node
 *return:	none
 *function:	remove TreeNode RightTree
 */
void removeTreeNodeRight(BiTree *tree, BiTreeNode *node);

/*name:		mergeTree
 *input:	BiTree *merge, BiTree *left, BiTree *right, const void *data
 *return:	success 0, false -1
 *function:	merge
 */
int mergeTree(BiTree *merge, BiTree *left, BiTree *right, const void *data);

/*name:		isTreeLeaf()
 *input:	const BiTreeNode *node
 *return:	node is leaf 1, false 0
 *function:	is node a leaf
 */
int isTreeLeaf(const BiTreeNode *node);