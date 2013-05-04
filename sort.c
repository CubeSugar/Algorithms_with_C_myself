#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"
/*----------------------------------------------------------------------------*
 *                              插入排序算法                                    *
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 *name:         insertSort()
 *arguments:    //待排序数据
 *              void *data,
 *              //无序元素个数
 *              int size,
 *              //元素类型大小
 *              int elmt_size,
 *              //比较方法:
 *                compare       return value
 *              -----------     ------------
 *              key1 > key2         1
 *              key1 = key2         0
 *              key1 < key2        -1
 *              int (*compare)(const void *key1, const void *key2)
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    插入排序算法。每次从未排序的数据集中取出一个元素，插入到已排好的数据集中。
 *----------------------------------------------------------------------------*/
int insertSort(void *data, int size, int elmt_size,
               int (*compare)(const void *key1,const void *key2))
{
    char *a;
    void *key;
    
    a = data;
    
    //待移动元素为指针变量，将key转化为char * 类型
    if ((key = (char *)malloc(elmt_size)) == NULL)
    {
        return -1;
    }
    
    for (int j = 1; j < size; j++)
    {
        memcpy(key, &a[j * elmt_size], elmt_size);
        
        int i = j - 1;
        
        while (i >= 0 && compare(&a[i * elmt_size], key) > 0)
        {
            memcpy(&a[(i + 1) * elmt_size], &a[i * elmt_size], elmt_size);
            i--;
        }
        
        memcpy(&a[(i + 1) * elmt_size], key, elmt_size);
    }
    
    free(key);    
    
    return 0;
}


/*----------------------------------------------------------------------------*
 *                              快速排序算法                                    *
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 *name:         compareInt()
 *arguments:    const void *int_num1, const void *int_num2
 *return:              rusult           return_value
                int_num1 > int_num2         1
                int_num1 = int_num2         0
                int_num1 < int_num2        -1
 *exception:
 *functions:    比较两个整数大小
 *----------------------------------------------------------------------------*/
static int compareInt(const void *int_num1, const void *int_num2)
{
    if (*(const int *)int_num1 > *(const int *)int_num2)
    {
        return 1;
    }
    else
    {
        if (*(const int *)int_num1 < *(const int *)int_num2)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

/*------------------------------------------------------------------------------
 *name:         partition()
 *arguments:    void *data, int elmt_size, int left_pos, int right_pos,
 *              int (*compare)(const void *key1, const void *key2)
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    对快速排序序列分段
 *----------------------------------------------------------------------------*/
static int partition(void *data, int elmt_size, int left_pos, int right_pos,
                     int (*compare)(const void *key1, const void *key2))
{
    //数据别名
    char *a;
    //待排数据分割轴
    void *pivot_value;
    //临时存放
    void *temp;
    //生成随机位置
    int random[3];
    
    a = data;
    
    if ((pivot_value = malloc(elmt_size)) == NULL)
    {
        return -1;
    }
    
    if ((temp = malloc(elmt_size)) == NULL)
    {
        free(pivot_value);
        return -1;
    }
    
    //生成随机位置
    random[0] = (rand() % (right_pos - left_pos + 1)) + left_pos;
    random[1] = (rand() % (right_pos - left_pos + 1)) + left_pos;
    random[2] = (rand() % (right_pos - left_pos + 1)) + left_pos;
    //取中值
    insertSort(random, 3, sizeof(int), compareInt);
    //设置分割轴
    memcpy(pivot_value, &a[random[1] * elmt_size], elmt_size);
    
    left_pos--;
    right_pos++;
    
    while (1)
    {
        //从右侧寻找小于分割轴值的位置
        do
        {
            right_pos--;
        } while (compare(&a[right_pos * elmt_size], pivot_value) > 0);
        
        //从左侧寻找大于分割轴值的位置
        do
        {
            left_pos++;
        } while (compare(&a[left_pos * elmt_size], pivot_value) < 0);
        
        if (left_pos > right_pos)
        {
            //已完成本次数据分割
            break;
        }
        else
        {
            //交换错位值
            memcpy(temp, &a[left_pos * elmt_size], elmt_size);
            memcpy(&a[left_pos * elmt_size], &a[right_pos * elmt_size], elmt_size);
            memcpy(&a[right_pos * elmt_size], temp, elmt_size);
        }
    }
    
    //释放指针
    free(pivot_value);
    free(temp);
    
    //返回分割轴位置
    return right_pos;
}

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
              int (*compare)(const void *key1, const void *key2))
{
    //分割轴位置
    int pivot;
    
    while (left_pos < right_pos)
    {
        //设置分割位置
        if ((pivot = partition(data, size, left_pos, right_pos, compare)) < 0)
        {
            return -1;
        }
        
        //完成左侧部分排序
        if (quickSort(data, size, elmt_size, left_pos, pivot, compare) < 0)
        {
            return -1;
        }
        
        //完成右侧部分排序
        left_pos = pivot + 1;
    }
    
    return 0;
}


/*----------------------------------------------------------------------------*
 *                              归并排序算法                                    *
 *----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
 *name:         merge()
 *arguments:    void *data,
 *              int elmt_size,
 *              int left_pos,
 *              int mid_pos,
 *              int right_pos,
 *              int (*compare)(const void *key1, const void *key2)
 *return:       succeeds 0, fails -1
 *exception:
 *functions:    归并两部分数据
 *----------------------------------------------------------------------------*/
static int merge(void *data, int elmt_size, int left_pos, int mid_pos,
                 int right_pos,
                 int (*compare)(const void *key1,const void *key2))
{
    char *a;
    char *mergeBuffer;
    
    int aleft;
    int aright;
    int mgbuff_pos;
    
    //initial
    a = data;
    aleft = left_pos;
    aright = mid_pos + 1;
    mgbuff_pos = 0;
    
    if ((mergeBuffer = (char *)malloc(elmt_size * (right_pos - left_pos + 1)))
        == NULL)
    {
        return -1;
    }
    
    while (aleft <= mid_pos || aright <= right_pos)
    {
        if (aleft > mid_pos)
        {
            while (aright <= right_pos)
            {
                memcpy(&mergeBuffer[mgbuff_pos * elmt_size],
                       &a[aright * elmt_size], elmt_size);
                aright++;
                mgbuff_pos++;
            }
            continue;
        }
        else if (aright > right_pos)
        {
            while (aleft <= mid_pos)
            {
                memcpy(&mergeBuffer[mgbuff_pos * elmt_size],
                       &a[aleft * elmt_size], elmt_size);
                
                aleft++;
                mgbuff_pos++;
            }
            continue;
        }
        
        if (compare(&a[aleft * elmt_size], &a[aright * elmt_size]) < 0)
        {
            memcpy(&mergeBuffer[mgbuff_pos * elmt_size], &a[aleft * elmt_size],
                   elmt_size);
            
            aleft++;
            mgbuff_pos++;
        }
        else
        {
            memcpy(&mergeBuffer[mgbuff_pos * elmt_size], &a[aright * elmt_size],
                   elmt_size);
            
            aright++;
            mgbuff_pos++;
        }
    }
    
    memcpy(&a[left_pos * elmt_size], mergeBuffer,
           elmt_size * (right_pos - left_pos + 1));
    
    free(mergeBuffer);    
    
    return 0;
}


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
              int (*compare)(const void *key1, const void *key2))
{
    int mid_pos;
    int left_size;
    int right_size;
    
    if (left_pos < right_pos)
    {
        mid_pos = (int)((left_pos + right_pos - 1) / 2);
        
        left_size = mid_pos - left_pos + 1;
        right_size = right_pos - mid_pos;
        
        if (mergeSort(data, size, elmt_size, left_pos, mid_pos, compare) < 0)
        {
            return -1;
        }
        
        if (mergeSort(data, size, elmt_size, mid_pos + 1, right_pos, compare) < 0)
        {
            return -1;
        }
        
        if (merge(data, elmt_size, left_pos, mid_pos, right_pos, compare) < 0)
        {
            return -1;
        }
    }
    
    return 0;
}


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
