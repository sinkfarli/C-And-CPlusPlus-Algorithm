/**
 * @file SequenceStack.h
 * @author 影风远sinkfarli
 * @brief 
 * @version 0.1
 * @date 2022-06-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef SEQUENCESTACK_H
#define SEQUENCESTACK_H


StackType *ST_Init(); //初始化顺序栈
int ST_IsEmpty(StackType *s); //判断空栈
int ST_IsFull(StackType *s); //判断满栈
void ST_Clear(StackType *s); //清空栈
void ST_Free(StackType *s); //释放空间
int ST_Push(StackType *s,Data data); //入栈
Data ST_Pop(StackType *s); //出栈
Data ST_Peek(StackType *s); //读结点数据


#endif