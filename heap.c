#include <stdlib.h>
#include <string.h>

#include "heap.h"

#define heap_parent(npos)   ((int)(((npos) - 1) / 2))
#define heap_left(npos)     (((npos) * 2) + 1)
#define heap_right(npos)    (((npos) * 2) + 2)

/*------------------------------------------------------------------------------
 *name:         initHeap()
 *arguments:    Heap *heap,
 *              int (*compare)(const void *key1, const void *key2),
 *              void (*destroy)(void *data)
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
    
    if ((temp = (void **)realloc(heap->tree, (heap->size + 1) * sizeof(void *)))
        == NULL)
    {
        return -1;
    }
    else
    {
        heap->tree = temp;
    }
    
    heap->tree[heap->size] = (void *)data;
    
    ipos = heap->size;
    ppos = heap_parent(ipos);
    
    while (ipos > 0 && heap->compare(heap->tree[ppos], heap->tree[ipos]) < 0)
    {
        temp = heap->tree[ppos];
        heap->tree[ppos] = heap->tree[ipos];
        heap->tree[ipos] = temp;
        
        ipos = ppos;
        ppos = heap_parent(ipos);
    }
    
    heap->size++;
    
    return 0;
}

/*------------------------------------------------------------------------------
 *name:         extractHeapTop()
 *arguments:    Heap *heap, void **data
 *return:       extract succeeds 0, fails -1
 *exception:
 *functions:    释放堆顶结点
 -----------------------------------------------------------------------------*/
int extractHeapTop(Heap *heap, void **data)
{
    //暂存尾结点
    void *save;
    //临时结点
    void *temp;
    
    //当前操作结点坐标
    int ipos;
    //当前操作结点左子结点坐标
    int lpos;
    //当前操作结点右子结点坐标
    int rpos;
    //待调整子结点坐标
    int mpos;
    
    //禁止从空堆中释放堆顶结点
    if (heap->size == 0)
    {
        return -1;
    }
    
    //释放堆顶
    *data = heap->tree[0];
    
    //暂存尾结点
    save = heap->tree[heap->size - 1];
    
    if (heap->size > 1)
    {
        //重新分配堆空间
        if ((temp = (void **)realloc(heap->tree, (heap->size - 1) * sizeof(void *))) == NULL )
        {
            return -1;
        }
        else
        {
            heap->tree = temp;
        }
        
        //修改堆结点个数
        heap->size--;
    }
    else
    {
        //释放堆顶后为空堆，则释放空间
        free(heap->tree);
        heap->tree = NULL;
        heap->size = 0;
        return 0;
    }
    
    //尾结点前置
    heap->tree[0] = save;
    
    ipos = 0;
    lpos = heap_left(ipos);//本句可注释
    rpos = heap_right(ipos);//本句可注释
    
    while (1)
    {
        lpos = heap_left(ipos);
        rpos = heap_right(ipos);
        
        //筛选大结点
        if (lpos < heap->size && heap->compare(heap->tree[lpos], heap->tree[ipos]) > 0)
        {
            mpos = lpos;
        }
        else
        {
            mpos = ipos;
        }
        //筛选大结点
        if (rpos < heap->size && heap->compare(heap->tree[rpos], heap->tree[mpos]) > 0)
        {
            mpos = rpos;
        }
        
        //大结点恰是当前结点，则不需要调整
        if (mpos == ipos)
        {
            break;
        }
        else
        {
            //大结点为某一子结点
            temp = heap->tree[mpos];
            heap->tree[mpos] = heap->tree[ipos];
            heap->tree[ipos] = temp;
            
            //重置当前操作结点
            ipos = mpos;
        }
    }
    
    return 0;
}

