/**
 * @file SequenceQueue.h
 * @author 影风远sinkfarli
 * @brief 顺序队列算法
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef SEQUENCEQUEUE_H
#define SEQUENCEQUEUE_H


SQType *SQT_Init(); //初始化顺序队列
int SQT_IsEmpty(SQType *q); //判断一个队列结构是否为空
int SQT_IsFull(SQType *q); //判断一个队列结构是否为满
void SQT_Clear(SQType *q); //清除队列中的所有数据
void SQT_Free(SQType *q); //释放队列结构所占用的内存单元
int SQT_In(SQType *q,Data data); //将数据元素保存到队列结构
Data *SQT_Out(SQType *q); //将数据元素取出队列
Data *SQT_Peek(SQType *q); //读取队列结构中结点的数据
int SQT_Length(SQType *q); //统计该队列中数据节点的个数


#endif