#ifndef HEAP_H
#define HEAP_H

typedef struct HEAP_
{
	int size;
	int (*compare)(const void *key1, const void *key2);
	void (*destroy)(void *data);
	void **tree;
	
} Heap;

//
/*------------------------------------------------------------------------------
 *name:         initHeap()
 *arguments:    Heap *heap, 
				int (*compare)(const void *key1, const void *key2),
				void (*destroy)(void *data)
 *return:       void
 *exception:    
 *functions:    初始化堆
 -----------------------------------------------------------------------------*/
void initHeap(Heap *heap, int (*compare)(const void *key1, const void *key2),
			  void (*destroy)(void *data));

/*------------------------------------------------------------------------------
 *name:         destroyHeap()
 *arguments:    Heap *heap
 *return:       void
 *exception:
 *functions:    销毁堆
 -----------------------------------------------------------------------------*/
void destroyHeap(Heap *heap);

/*------------------------------------------------------------------------------
 *name:         insertHeapElmt()
 *arguments:    Heap *heap, const void *data
 *return:       already exists 1, insert succeeds 0, fails -1
 *exception:    
 *functions:    向堆中插入元素
 -----------------------------------------------------------------------------*/
int insertHeapElmt(Heap *heap, const void *data);

/*------------------------------------------------------------------------------
 *name:         extractHeapTop()
 *arguments:    Heap *heap, void **data
 *return:       extract succeeds 0, fails -1
 *exception:
 *functions:    释放堆顶结点
 -----------------------------------------------------------------------------*/
int extractHeapTop(Heap *heap, void **data);

#endif
