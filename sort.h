#ifndef SORT_H
#define SORT_H

//public interface
/*------------------------------------------------------------------------------
 *name:         insertSort()
 *arguments:    void *data,
 *              int size,
 *              int elmt_size, 
 *              int (*compare)(const void *key1, const void *key2)
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    插入排序算法。每次从未排序的数据集中取出一个元素，插入到已排好的数据集中。
 *----------------------------------------------------------------------------*/
int insertSort(void *data, int size, int elmt_size,
                  int (*compare)(const void *key1,const void *key2));

/*------------------------------------------------------------------------------
 *name:         quickSort()
 *arguments:    void *data,
 *              int size,
 *              int elmt_size,
 *              int left_pos,
 *              int right_pos,
 *              int (*compare)(const void *key1, const void *key2)
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    快速排序算法。
 *----------------------------------------------------------------------------*/
int quickSort(void *data, int size, int elmt_size,
              int left_pos, int right_pos,
              int (*compare)(const void *key1, const void *key2));


/*------------------------------------------------------------------------------
 *name:         mergeSort()
 *arguments:    void *data,
 *              int size,
 *              int elmt_size,
 *              int left_pos,
 *              int right_pos,
 *              int (*compare)(const void *key1, const void *key2)
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    归并排序算法。
 *----------------------------------------------------------------------------*/
int mergeSort(void *data, int size, int elmt_size, int left_pos, int right_pos,
              int (*compare)(const void *key1, const void *key2));

/*------------------------------------------------------------------------------
 *name:         countSort()
 *arguments:    int *data, int size, int k
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    计数排序算法
 *----------------------------------------------------------------------------*/
int countSort();

/*------------------------------------------------------------------------------
 *name:         radixSort()
 *arguments:    int *data, int size, int p, int k
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    基数排序算法
 *----------------------------------------------------------------------------*/
int radixSort();




#endif
