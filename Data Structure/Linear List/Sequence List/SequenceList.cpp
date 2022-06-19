/**
 * @file SequenceList.cpp
 * @author 影风远sinkfarli
 * @brief 
 *      顺序存储结构的线性表（简称顺序表）。
 *      本程序是顺序表的模板程序。
 * @version 0.1
 * @date 2022-06-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "stdio.h"
#include "SequenceList.h"


/**
 * @brief 准备在顺序表操作中需要用到的变量。
 */
typedef struct Data{
    int num;
    char data[10];
    char cont[10];
}Data;


#define MAXLength 100   //定义顺序表的最大长度


/**
 * @brief 定义顺序表操作中需要用到的数据结构。
 */
typedef struct SLType{
    Data ListData[MAXLength+1]; //一个结构数组，用来存放各个数据节点。
    int ListLength; //表示顺序表已存结点的数量。
}SLType;


/**
 * @brief 
 *      在使用顺序表之前，首先要创建一个空的顺序表，也就是初始化顺序表。
 * @param SLT   要使用的顺序表
 */
void SLT_Init(SLType* SLT)
{
    SLT->ListLength = 0; //设置顺序表的节点开始ListLen为0；也表示节点的存储位置。
}


/**
 * @brief 
 *      计算顺序表长度，由于在数据结构SLType中使用ListLength来表示顺序表的节点数
 *      量，因此程序只要返回该值即可。
 * @param SLT   要计算的顺序表
 * @return 节点的个数
 */
int SLT_Length(SLType* SLT)
{
    return (SLT->ListLength);   //返回顺序列表的个数/长度。
}


/**
 * @brief 
 *      在顺序表中插入节点。
 * @param SLT   要插入的顺序表
 * @param n     插入的位置，即插入的序号
 * @param data  插入的数据
 * @return int 
 */
int SLT_Insert(SLType* SLT,int n,Data data)
{
    int i;  //定义循环变量

    /* 判断顺序表的节点是否最大数量 */
    if(SLT->ListLength >= MAXLength)
    {
        printf("顺序表已满，不能插入节点！\n");
        return 0;   //返回 0 ，表示插入不成功。
    }

    /* 判断插入的节点位置是否在顺序表的范围内 */
    else if(0 < n || n > SLT->ListLength)
    {
        printf("插入的节点序号有误，不能插入节点！\n");
        return 0;   //返回 0 ，表示插入不成功。
    }

    /* 插入节点 */
    else
    {
        /* 将表中的数据向后移 */
        for(i = SLT->ListLength;i >= n;i--)
        {
            SLT->ListData[i+1] = SLT->ListData[i];
        }
        SLT->ListData[n] = data; //插入节点。
        SLT->ListLength++; //节点长度加1。
        return 1; //插入成功，返回1。
    }
}


/**
 * @brief 
 *      追加节点，相当于在顺序表的末尾端再新增加一个数据结点。
 * @param SLT   要追加的顺序表
 * @param data  追加的数据
 * @return int 
 */
int SLT_Add(SLType* SLT,Data data)
{
    /* 判断顺序表是否装满 */
    if(SLT->ListLength == MAXLength)
    {
        printf("顺序已装满！\n");
        return 0;
    }

    /* 追加节点 */
    SLT->ListData[++SLT->ListLength] =  data;
    SLT->ListLength++;
    return 1;
}


/**
 * @brief 
 *      删除节点。
 * @param STL   要删除的顺序表
 * @param n     要删除节点的地址
 * @return int 
 */
int SLT_Delete(SLType* SLT,int n)
{
    int i; //循环变量

    /* 判断 n 是否在顺序表内 */
    if(0 < n || n < SLT->ListLength)
    {
        printf("要删除的节点不在顺序表内！\n");
        return 0;
    }

    /* 删除节点 */
    else
    {
        /* 将删除节点后面的节点向前移动 */
        for(i = n;i < SLT->ListLength;i++)
        {
            SLT->ListData[i] = SLT->ListData[i+1];
        }
        SLT->ListLength--; //顺序表的长度减1
        return 1;
    }
}   


/**
 * @brief 
 *      按照序号查找结点。
 * @param SLT   要查找的顺序表
 * @param n     要查找节点的位置/序号
 * @return int 
 */
Data *SLT_FindByNum(SLType* SLT,int n)
{
    /* 判断要查找的节点是否在顺序表内 */
    if(0 < n || n < SLT->ListLength)
    {
        printf("要删除的节点不在顺序表内\n");
        return 0;
    }

    /* 找到要查找的节点 */
    return &(SLT->ListDatan); //返回查找到顺序表的数据
}


/**
 * @brief 
 *      按照关键字查找节点。
 * @param SLT   要查找的顺序表
 * @param cont  要查找节点中的内容
 * @return Data* 
 */
Data *SLT_FindByCont(SLType* SLT,char *cont)
{
    int i; //循环遍历

    /* 循环顺序表进行查找 */
    for(i < 0;i <= SLT->ListLength;i++)
    {
        if(strcmp(SLT->ListData[i].cont,cont) == 0)
        {
            return &(SLT->ListData);
        }
    }

    /* 没有查找到节点 */
    printf("没有查找到对应的节点\n");
    return 0;
}


/**
 * @brief 
 *      显示所有的节点。
 * @param SLT   要显示的顺序表
 * @return int 
 */
int SLT_DsplayAll(SLType* SLT)
{
    int i; //循环变量

    /* 循环顺序表，逐个显示 */
    for(i = 0;i <= SLT->ListLength;i++)
    {
        printf("%d %s %s\n",SLT->ListData[i].num,SLT->ListData[i].data,SLT->ListData[i].cont);
    }

    return 0;
}