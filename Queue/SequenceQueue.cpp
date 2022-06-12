/**
 * @file SequenceQueue.cpp
 * @author 影风远sinkfarli
 * @brief 顺序队列算法
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "stdio.h"
#include "SequenceQueue.h"


/**
 * @brief 队列的数据
 */
typedef struct Data{
    char cont[10];
    int num;
}Data;


#define QueueLength 15


/**
 * @brief 顺序队列的数据结构
 */
typedef struct SQType{
    Data data[QueueLength]; //队列的数组
    int head; //队头
    int tail; //队尾
}SQType;


/**
 * @brief 
 *      使用顺序队列之前，首先要创建一个空的顺序队列，也就是初始化顺序队列。
 *      顺序队列的初始化操作步骤如下：
 *          1. 按符号常量QueueLength指定的大小申请一块内存空间，用来保存队列中的数据。
 *          2. 设置head=0和tail=0，表示是一个空栈。
 * @return SQType* 
 */
SQType *SQT_Init()
{
    SQType *q; //要初始化的队列

    if(q = (SQType*)malloc(sizeof(SQType)))
    {
        q->head = 0; //设置队头
        q->tail = 0; //设置队尾

        return q; //返回申请内存的首地址
    }

    return NULL; //如果申请内存失败，将返回NULL
}


/**
 * @brief 
 *      判断空队列就是判断一个队列结构是否为空。
 *      如果是空队列，则表示该队列结构中没有数据。此时可以进行入队列操作，但不可以进行出队列操作。
 * @param q 要判断的队列
 * @return int 
 */
int SQT_IsEmpty(SQType *q)
{
    int temp; //返回的值

    /* 根据队列head是否等于tail，判断队列是否为空 */
    if(q->head == q->tail)
    {
        temp = q->head;
    }

    return temp;
}


/**
 * @brief 
 *      判断满队列就是判断一个队列结构是否为满。
 *      如果是满队列，则表示该队列结构中没有多余的空间来保存额外数据。
 *      此时不可以进行入队列操作，但是可以进行出队列操作。
 * @param q 要判断的队列
 * @return int 
 */
int SQT_IsFull(SQType *q)
{
    int temp; //返回的值

    /* 根据tail是否等于QueueLength，进行判断 */
    if(q->tail == QueueLength)
    {
        temp = q->tail;
    }

    return temp;
}


/**
 * @brief 
 *      清空队列就是清除队列中的所有数据。
 *      程序中，简单地将队列顶指针head和tail设置为0，表示执行清空队列操作。
 * @param q 要清空的队列
 */
void SQT_Clear(SQType *q)
{
    q->head = 0; //设置队头
    q->tail = 0; //设置队尾
}


/**
 * @brief 
 *      释放空间是释放队列结构所占用的内存单元。
 *      一般在不需要使用队列结构时调用该函数，特别是程序结束时。
 * @param q 要释放空间的队列
 */
void SQT_Free(SQType *q)
{
    if(q != NULL)
    {
        free(q);
    }
}


/**
 * @brief 
 *      入队列是队列结构的基本操作，主要操作是将数据元素保存到队列结构。
 *      入队列操作的具体步骤如下：
 *          1. 首先判断队列顶tail，如果tail等于QUEUELEN，则表示溢出，进行出错处理。
 *             否则执行以下操作:
 *              1. 设置tail=tail+1（队列顶指针加1，指向入队列地址）。
 *              2. 将入队列元素保存到tail指向的位置。
 * @param q     要入队的队列
 * @param data  要入队的数据
 * @return int 
 */
int SQT_In(SQType *q,Data data)
{
    if(q->tail == QueueLength)
    {
        printf("队列已满！\n");
        return 0;
    }

    q->data[++q->tail] = data;
    return 1;
}


/**
 * @brief 
 *      出队列是队列结构的基本操作，主要操作与入队列相反，是从队列顶弹出一个数据元素。
 *      出队列操作的具体步骤如下：
 *          1. 判断队列head，如果head等于tail，则表示为空队列，进行出错处理。
 *             否则执行下面的步骤。
 *                  1. 从队列首部取出队头元素（实际是返回队头元素的指针）。
 *                  2. 设修改队头head的序号，使其指向后一个元素。
 * @param q 要操作出队的队列
 * @return Data* 
 */
Data *SQT_Out(SQType *q)
{
    /* 判断队列是否为空队列 */
    if(q->head == NULL)
    {
        printf("队列为空队列！\n");
        return 0;
    }

    return &(q->data[q->head++]);
}


/**
 * @brief 
 *      读结点数据也就是读取队列结构中结点的数据，这里的读操作其实就是读队列头的数据。
 *      读结点数据的操作和出队列操作不同。
 *      读结点数据的操作仅是显示队列顶结点数据的内容，而出队列操作则将队列顶数据弹出，该数据将不再存在。
 * @param q 要读取的队列
 * @return Data* 
 */
Data *SQT_Peek(SQType *q)
{
    if(SQT_IsEmpty(q))
    {
        printf("队列为空队列！\n");
        return NULL;
    }

    return &(q->data[q->head]);
}


/**
 * @brief 
 *      计算队列长度就是统计该队列中数据节点的个数。
 *      计算队列长度的方法比较简单，直接将队尾序号减去队头序号即可。
 * @param q 要计算长度的队列
 * @return int 
 */
int SQT_Length(SQType *q)
{
    int temp;

    temp = q->tail - q->head; //计算队列长度

    return temp;
}

