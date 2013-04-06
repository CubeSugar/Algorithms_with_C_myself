#ifndef TREE_BINARY_H
#define TREE_BINARY_H

#include <stdlib.h>

typedef struct BiTreeNode_
{
	void *data;
	struct BiTreeNode_ *left;
	struct BiTreeNode_ *right;
} BiTreeNode;

//binary trees
typedef struct BiTree_
{
	int size;
	int (*compare)(const void *key1, const void *key2);
	void (*destroy)(void *data);
	BiTreeNode *root;
} BiTree;

//public interface
/*---------------------------------------------------------
 *name:		initBiTree()
 *input:	BiTree *tree, void (*destroy)(void *data)
 *return:	none
 *function:	initiate BiTree
 *---------------------------------------------------------*/
void initBiTree(BiTree *tree, void (*destroy)(void *data));

/*---------------------------------------------------------
 *name:		destroyTree()
 *input:	BiTree *tree
 *return:	none
 *function:	destroy BiTree
 *---------------------------------------------------------*/
void destroyTree(BiTree *tree);

/*---------------------------------------------------------
 *name:		insertTreeNodeLeft()
 *input:	BiTree *tree, BiTreeNode *node, const void *data
 *return:	success 0, failure -1
 *function:	insert TreeNode left child
 *---------------------------------------------------------*/
int insertTreeNodeLeft(BiTree *tree, BiTreeNode *node, const void *data);

/*---------------------------------------------------------
 *name:		insertTreeNodeRight()
 *input:	BiTree *tree, BiTreeNode *node, const void *data
 *return:	success 0, failure -1
 *function:	insert TreeNode Right child
 *---------------------------------------------------------*/
int insertTreeNodeRight(BiTree *tree, BiTreeNode *node, const void *data);

/*---------------------------------------------------------
 *name:		removeTreeNodeLeft()
 *input:	BiTree *tree, BiTreeNode *node
 *return:	none
 *function:	remove TreeNode LeftTree
 *---------------------------------------------------------*/
void removeTreeNodeLeft(BiTree *tree, BiTreeNode *node);

/*---------------------------------------------------------
 *name:		removeTreeNodeRight()
 *input:	BiTree *tree, BiTreeNode *node
 *return:	none
 *function:	remove TreeNode RightTree
 *---------------------------------------------------------*/
void removeTreeNodeRight(BiTree *tree, BiTreeNode *node);

/*---------------------------------------------------------
 *name:		mergeTree
 *input:	BiTree *merge, BiTree *left, BiTree *right, const void *data
 *return:	success 0, failure -1
 *function:	合并left和right所指的树，并将data作为merge根节点数值域
 *---------------------------------------------------------*/
int mergeTree(BiTree *merge, BiTree *left, BiTree *right, const void *data);

/*---------------------------------------------------------
 *name:		isTreeLeaf()
 *input:	const BiTreeNode *node
 *return:	node is leaf 1, failure 0
 *function:	is node a leaf
 *---------------------------------------------------------*/
int isTreeLeaf(const BiTreeNode *node);

#endif