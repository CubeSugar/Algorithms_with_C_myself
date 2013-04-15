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
/*------------------------------------------------------------------------------
 *name:         initBiTree()
 *arguments:    BiTree *tree, void (*destroy)(void *data)
 *return:       void
 *exception:
 *functions:    初始化二叉树
 *----------------------------------------------------------------------------*/
void initBiTree(BiTree *tree, void (*destroy)(void *data));


/*------------------------------------------------------------------------------
 *name:         destroyTree()
 *arguments:    BiTree *tree
 *return:       void
 *exception:
 *functions:    destroy BiTree
 *----------------------------------------------------------------------------*/
void destroyTree(BiTree *tree);


/*------------------------------------------------------------------------------
 *name:         insertTreeNodeLeft()
 *arguments:    BiTree *tree, BiTreeNode *node, const void *data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    二叉树中插入左子结点
 *----------------------------------------------------------------------------*/
int insertTreeNodeLeft(BiTree *tree, BiTreeNode *node, const void *data);


/*------------------------------------------------------------------------------
 *name:         insertTreeNodeRight()
 *arguments:    BiTree *tree, BiTreeNode *node, const void *data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    二叉树中插入右子结点
 *----------------------------------------------------------------------------*/
int insertTreeNodeRight(BiTree *tree, BiTreeNode *node, const void *data);


/*------------------------------------------------------------------------------
 *name:         removeTreeNodeLeft()
 *arguments:    BiTree *tree, BiTreeNode *node
 *return:       void
 *exception:
 *functions:    移除左子结点
 *----------------------------------------------------------------------------*/
void removeTreeNodeLeft(BiTree *tree, BiTreeNode *node);


/*------------------------------------------------------------------------------
 *name:         removeTreeNodeRight()
 *arguments:    BiTree *tree, BiTreeNode *node
 *return:       void
 *exception:
 *functions:    移除右子结点
 *----------------------------------------------------------------------------*/
void removeTreeNodeRight(BiTree *tree, BiTreeNode *node);


/*------------------------------------------------------------------------------
 *name:         mergeTree()
 *arguments:    BiTree *merge, BiTree *left, BiTree *right, const void *data
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    合并两棵树
 *----------------------------------------------------------------------------*/
int mergeTree(BiTree *merge, BiTree *left, BiTree *right, const void *data);


/*------------------------------------------------------------------------------
 *name:         isTreeLeaf()
 *arguments:    const BiTreeNode *node
 *return:       succeeds 1, fails 0
 *exception:
 *functions:    判断是否为叶结点
 *----------------------------------------------------------------------------*/
int isTreeLeaf(const BiTreeNode *node);

#endif