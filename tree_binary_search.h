#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "tree_binary.h"

//define balance factors for AVL trees
#define AVL_LEFT_HEAVY   1
#define AVL_BALANCED     0
#define AVL_RIGHT_HEAVY -1

//define structure for nodes in AVL trees
typedef struct AVLNODE_
{
	void *data;
	int hidden;
	int factor;
} AvlNode;

typedef BiTree BiSearchTree;

//public interface
/*------------------------------------------------------------------------------
 *name:		initBiSearchTree()
 *argument:	BiSearchTree *biSearchTree, 
 			int (*compare)(const void *key1, const void *key2),
            void (*destroy)(void *data)
 *return:	none
 *function:	initiate binary search tree
 *----------------------------------------------------------------------------*/
void initBiSearchTree(BiSearchTree *biSearchTree,
					  int (*compare)(const void *key1, const void *key2),
                      void (*destroy)(void *data));
/*------------------------------------------------------------------------------
 *name:		destroyBiSearchTree()
 *argument:	BiSearchTree *biSearchTree
 *return:	none
 *function:	destroy Binary Search Tree
 *----------------------------------------------------------------------------*/
void destroyBiSearchTree(BiSearchTree *biSearchTree);

/*------------------------------------------------------------------------------
 *name:		insertAVLNode()
 *argument:	BiSearchTree *biSearchTree, const void *data
 *return:	already existence 1, insert success 0, failure -1
 *function:	insert an AVL Node
 *----------------------------------------------------------------------------*/
int insertAVLNode(BiSearchTree *biSearchTree, const void *data);

/*------------------------------------------------------------------------------
 *name:		removeAVLNode()
 *argument:	BiSearchTree *biSearchTree, const void *data
 *return:	remove success 0, failure -1
 *function:	在由参数tree所制定的二叉搜索树中移除数据同参数data相吻合的结点。实际上，该操作仅
			仅只执行一种惰性移除，即该结点只是简单地被标记为隐藏。因此，并不会返回指向结点数据
			的指针。更进一步，树中的数据就算被移除了也必须保持有效。结果即，二叉搜索树的大小，
			即biSearchTree.size值，并不会在移除一个结点后递减。
 *----------------------------------------------------------------------------*/
int removeAVLNode(BiSearchTree *biSearchTree, const void *data);

/*------------------------------------------------------------------------------
 *name:		findAVLNode()
 *argument:	BiSearchTree *biSearchTree, void **data
 *return:	find success 0, failure -1
 *function: find node @ tree
 *----------------------------------------------------------------------------*/
int findAVLNode(BiSearchTree *biSearchTree, void **data);


#endif