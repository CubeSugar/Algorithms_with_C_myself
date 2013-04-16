#include <stdlib.h>
#include <string.h>

#include "heap.h"

#define heap_parent(npos)   ((int)(((npos) - 1) / 2))
#define heap_left(npos)     (((npos) * 2) + 1)
#define heap_right(npos)    (((npos) * 2) + 2)

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
			  void (*destroy)(void *data))
{
    heap->size = 0;
    heap->compare = compare;
    heap->destroy = destroy;
    heap->tree = NULL;
}


/*------------------------------------------------------------------------------
 *name:         destroyHeap()
 *arguments:    Heap *heap
 *return:       void
 *exception:
 *functions:    销毁堆
 -----------------------------------------------------------------------------*/
void destroyHeap(Heap *heap)
{
    if (heap->destroy != NULL)
    {
        for (int i = 0; i < heap->size; i++)
        {
            heap->destroy(heap->tree[i]);
        }
    }
    
    free(heap->tree);
    
    memset(heap, 0, sizeof(Heap));
}

/*------------------------------------------------------------------------------
 *name:         insertHeapElmt()
 *arguments:    Heap *heap, const void *data
 *return:       already exists 1, insert succeeds 0, fails -1
 *exception:
 *functions:    向堆中插入元素
 -----------------------------------------------------------------------------*/
int insertHeapElmt(Heap *heap, const void *data)
{
    void *temp;
    int ipos, ppos;
    
    
    
    
    return 0;
}

/*------------------------------------------------------------------------------
 *name:         extractHeapTop()
 *arguments:    Heap *heap, void **data
 *return:       extract succeeds 0, fails -1
 *exception:
 *functions:    释放堆顶结点
 -----------------------------------------------------------------------------*/
int extractHeapTop(Heap *heap, void **data);

