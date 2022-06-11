/**
 * @file LinkedList.cpp
 * @author 影风远sinkfarli
 * @brief 
 * 
 * @version 0.1
 * @date 2022-06-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "stdio.h"
#include "LinkedList.h"


/**
 * @brief 准备链表所需的变量
 */
typedef struct Data{
    char cont[10];
    char string[10];
    int num;
}Data;


/**
 * @brief 定义链表的数据结构
 */
typedef struct Node{
    Data nodedata;  
    struct Node *nextnode;  //指向下一个节点
}CLTpye;


/**
 * @brief 
        追加节点即是在链表末尾增加一个节点。追加步骤如下：
        1. 首先分配内存空间，保存新增的节点。
        2. 从头指针head开始逐个检查，直到找到最后一个节点（即表尾）。
        3. 将表尾节点的地址设置为新增节点的地址。
        4. 将新增节点的地址部分设置为空地址NULL，即新增节点成为表尾。
 * @param head      要加入的头节点
 * @param nodedata  加入的数据
 * @return CLTpye* 
 */
CLTpye *CLT_AddEnd(CLTpye *head,Data nodedata)
{
    CLTpye *node,*newnode; //创建节点指针变量和新节点指针变量

    /* 判断是否能为node节点分配内存空间 */
    if(!(node = (CLTpye*)=malloc(sizeof(CLTpye))))
    {
        printf("申请内存失败\n");
        return NULL;
    }

    /* 追加节点 */
    else
    {
        node->nodedata = nodedata; //保存节点的数据
        node->nextnode = NULL; //设置下一个节点的地址为NULL，即表尾

        /* 判段追加的节点是否为头节点 */
        if(head == NULL)
        {
            head = node; //将节点的数据转交给头节点
            return head; //返回头节点，即链表
        }

        /* 如果不是头节点 */
        else
        {
            newnode = head; //将头节点给newnode

            /* 查找为尾节点 */
            while(newnode->nextnode != NULL)
            {
                newnode = newnode->nextnode; //将newnode节点指向下一个的地址
            } 
            
            newnode->nodedata = node; //将newnode移动到node
            return head;
        }
    }
}


/**
 * @brief 
 *      插入头节点，即在链表首部添加节点的过程。
 *      1. 首先分配内存空间，保存新增的节点。
 *      2. 使新增节点指向头指针head所指向的节点。
 *      3. 然后使头指针head指向新增节点。
 * @param head      要加入的头节点
 * @param nodedata  加入的数据
 * @return CLTpye* 
 */
CLTpye *CLT_AddFirst(CLTpye *head,Data nodedata)
{
    CLTpye *node; //要加入的节点

    /* 判断是否能为node节点分配内存空间 */
    if(!(node = (CLTpye*)=malloc(sizeof(CLTpye))))
    {
        printf("申请内存失败\n");
        return NULL;
    }

    /* 插入头节点 */
    else
    {
        node->nodedata = nodedata; //保存数据
        node->nextnode = head; //指向头指针的地址
        head = node; //头指针新增的节点

        return head;
    }
}


/**
 * @brief 
 *      查找节点，即在链表结构中查找需要的元素。
 * @param head  要查找的指针
 * @param cont  要查找的内容
 * @return CLTpye* 
 */
CLTpye *CLT_FindNode(CLTpye *head,char cont)
{
    CLTpye *FNode;

    FNode = head; //保存头指针

    /* 节点有效 */
    while(FNode)
    {
        /* 判断查找的关键是否与链表中的数据相同 */
        if(strcmp(FNode->nodedata.cont,cont) == 0)
        {
            return FNode;
        }

        FNode = FNode->nextnode; //继续查找
    }

    return NULL; //节点无效返回NULL
}


/**
 * @brief 
 *      插入节点，即在链表中间部分的指定位置增加一个节点。
 *      1. 首先分配内存空间，保存新增的节点。
 *      2. 找到要插入的逻辑位置，也就是位于哪两个节点之间。
 *      3. 修改插入位置节点的指针，使其指向新增节点，而使新增节点指向原插入位置所指向的结点。
 * @param head      要插入的头指针
 * @param findcont  要插入的关键字位置
 * @param nodedata  要插入的内容
 * @return CLTpye* 
 */
CLTpye *CLT_InsertNode(CLTpye *head,CLTpye *findcont,Data nodedata)
{
    CLTpye *node,nodetemp; // 要插入的节点和存储找到的插入节点的位置

    /* 判断是否能为node节点分配内存空间 */
    if(!(node = (CLTpye*)=malloc(sizeof(CLTpye))))
    {
        printf("申请内存失败\n");
        return NULL;
    }

    node->nodedata = nodedata; //保存插入节点的数据
    nodetemp = CLT_FindNode(head,findcont); //保存要插入节点的位置

    /* 插入节点 */
    if(nodetemp)
    {
        node->nextnode = nodetemp->nextnode; //新插入的节点的地址指等于插入位置的地址
        nodetemp->nextnode = node; //将关键字的节点指向新插入的节点
    }

    /* 插入失败 */
    else
    {
        printf("未找到正确的插入位置\n");
        free(node); //释放内存
    }

    return head;
}


/**
 * @brief 
 *      删除某个节点，即将链表中的某个节点数据删除。
 *      1. 查找需要删除的节点。
 *      2. 使前一节点指向当前节点的下一节点。
 *      3. 删除节点。
 * @param head  要删除的节点
 * @param cont  删除的位置
 * @return CLTpye* 
 */
CLTpye *CLT_DeleteNode(CLTpye *head,char cont)
{
    CLTpye *node,*temp; //表示当前节点指针和临时节点指针

    temp = head; 
    node = head; 

    /* 循环链表 */
    while(temp)
    {
        /* 找到要删除额节点 */
        if(strcmp(head->nodedata.cont,cont) == 0)
        {
            node->nextnode = temp->nextnode; //使当前节点的地址等于下一个节点的地址
            free(temp); //释放节点的内存
            return 1; 
        }

        /* 没有找到节点 */
        else
        {
            node = temp; //指向当前节点
            temp = temp->nextnode; //指向下一个节点
        }

        return 0;
    }
}


/**
 * @brief 
 *      计算节点的长度
 * @param head  要计算的节点
 * @return int 
 */
int CLT_Length(CLTpye *head)
{
    CLTpye *temp; //临时节点
    int Length = 0; //节点额长度

    /* 循环链表 */
    while(temp)
    {
        Length++; //长度加一
        temp = temp->nextnode; //指向下一个节点
    }

    return Length; //返回节点的长度
}


/**
 * @brief 
 *      显示所有结点
 * @param head  要显示的节点
 */
void CTL_DsplayAllNode(CLTpye *head)
{
    CLTpye *temp; //临时指针
    Data nodedata; //要显示的数据

    temp = head;

    /* 循环指针显示 */
    while(temp)
    {
        nodedata = temp->nodedata; //获取节点的数据
        printf("%d %s %s\n",nodedata.num,nodedata.cont,nodedata.string);
        tmep = temp->nextnode; //指向下一个指针
    }
}
