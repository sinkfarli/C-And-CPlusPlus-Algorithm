/**
 * @file SequenceStack.cpp
 * @author 影风远sinkfarli
 * @brief 
 *      顺序栈的使用方式。
 *      从1开始
 * @version 0.1
 * @date 2022-06-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "stdio.h"
#include "SquenceStack.h"


/**
 * @brief 栈中存储的数据
 */
typedef struct Data{
    char name[10];
    int num;
}Data;


#define MAXLength 50 //栈结构的最大长度


/**
 * @brief 
 *      栈的数据结构
 *      当top=0时表示栈为空，当top=SIZE时表示栈满。
 */
typedef struct Stack
{
    Data data[Size+1]; //栈元素
    int top; //栈顶
}StackType;


/**
 * @brief 
 *      在使用顺序栈之前，首先要创建一个空的顺序栈，也就是初始化顺序栈。
 *      顺序栈的初始化操作步骤如下：
 *      1. 按符号常量SIZE指定的大小申请一块内存空间，用来保存栈中的数据。
 *      2. 设置栈顶指针的值为0，表示是一个空栈。
 * @return SrackType* 
 */
StackType *ST_Init()
{
    StackType *p;

    /* 申请内存 */
    if(p = (StackType*)malloc(sizeof(StackType)))
    {
        p->top = 0; //设置栈顶为0
        return p; //返回栈的指针
    }

    return NULL;
}


/**
 * @brief 
 *      判断空栈就是判断一个栈结构是否为空。如果是空栈，则表示该栈结构中没有数据。
 *      此时可以进行入栈操作，但不可以进行出栈操作。
 * @param s 指向操作的栈的指针
 * @return int 
 */
int ST_IsEmpty(StackType *s)
{
    int t;
    
    /* 判断是否为空栈 */
    if(s->top == 0)
    {
        t = s->top; //是空栈，即t=0
    }

    return t;
}


/**
 * @brief 
 *      判断满栈就是判断一个栈结构是否为满。如果是满栈，则表示该栈结构中没有多余的空间来保存额外数据。
 *      此时不可以进行入栈操作，但是可以进行出栈操作。
 * @param s 指向操作的栈的指针
 * @return int 
 */
int ST_IsFull(StackType *s)
{
    int t;

    /* 判断是否满栈 */
    if(s->top == MAXLength)
    {
        t = s->top; //即t=满栈的值
    }

    return t;
}


/**
 * @brief 
 *      清空栈就是栈中的所有数据被清除。
 * @param s 指向操作的栈的指针
 */
void ST_Clear(StackType *s)
{
    s->top = 0; //将栈顶指针top设置为0，表示执行清空栈操作
}


/**
 * @brief 
 *      释放空间是释放栈结构所占用的内存单元。
 *      在初始化栈结构时，使用了malloc（）函数分配内存空间。
 *      虽然可以使用清空栈操作，但是清空栈操作并没有释放内存空间，这就需要使用free（）函数释放所分配的内存。
 *      一般在不需要使用栈结构时调用该函数，特别是程序结束时。
 * @param s 指向操作的栈的指针
 */
void ST_Free(StackType *s)
{
    if(s)
    {
        free(s);
    }
}


/**
 * @brief 
 *      入栈（Push）是栈结构的基本操作，主要操作是将数据元素保存到栈结构。
 *      入栈操作的具体步骤如下：
 *          1. 首先判断栈顶top，如果top大于或等于SIZE，则表示溢出，进行出错处理。
 *          2. 设置top=top+1（栈顶指针加1，指向入栈地址）。
 *          3. 将入栈元素保存到top指向的位置。
 * @param s     指向操作的栈的指针
 * @param data  存入的数据
 * @return int 
 */
int ST_Push(StackType *s,Data data)
{
    /* 判断栈是否溢出 */
    if((s->top+1) > MAXLength)
    {
        printf("栈溢出！\n");
        return 0;
    }

    s->data[++s->top] = data; //将元素入栈
    return 1;
}


/**
 * @brief 
 *      出栈（Pop）是栈结构的基本操作，主要操作与入栈相反，它是从栈顶弹出一个数据元素。
 *      出栈操作的具体步骤如下：
 *          1. 首先判断栈顶top，如果top等于0，则表示为空栈，进行出错处理。
 *          2. 将栈顶指针top所指位置的元素返回。
 *          3. 设置top=top-1，也就是使栈顶指针减1，指向栈的下一个元素，原来栈顶元素被弹出。
 * @param s 指向操作的栈的指针
 * @return Data 
 */
Data ST_Pop(StackType *s)
{
    /* 判断是否为空栈 */
    if(s->top == 0)
    {
        printf("栈为空！\n");
        exit(0);
    }

    return (s->data[s->top--]);
}


/**
 * @brief 
 *      读结点数据也就是读取栈结构中结点的数据。由于栈结构只能在一端进行操作，因此这里的读操作其实就是读栈顶的数据。
 *      读结点数据的操作仅是显示栈顶结点数据的内容，而出栈操作则将栈顶数据弹出，该数据将不再存在。
 * @param s 指向操作的栈的指针
 * @return Data 
 */
Data ST_Peek(StackType *s)
{
    /* 判断栈是否为空 */
    if(s->top == 0)
    {
        printf("栈为空！\n");
        exit(0);
    }

    return (s->data[s->top]);
}
