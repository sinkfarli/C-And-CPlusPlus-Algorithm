/**
 * @file SeequenceLish.h
 * @author 影风远sinkfarli
 * @brief 
 *      顺序存储结构的线性表（简称顺序表）。
 *      本程序是顺序表的模板程序的相关声明。
 * @version 0.1
 * @date 2022-06-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

void SLT_Init(SLType* SLT); //初始化顺序表
int SLT_Length(SLType* SLT); //计算顺序表长度
int SLT_Insert(SLType* SLT,int n,Data data); //在顺序表中插入节点
int SLT_Add(SLType* SLT,Data data); //追加节点
int SLT_Delete(SLType* SLT,int n); //删除节点
Data *SLT_FindByNum(SLType* SLT,int n); //按照序号查找结点
Data *SLT_FindByCont(SLType* SLT,char *cont); //按照关键字查找节点
int SLT_DsplayAll(SLType* SLT); //显示所有的节点吧 

#endif 