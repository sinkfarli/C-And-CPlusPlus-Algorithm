/**
 * @file LinkedList.h
 * @author 影风远sinkfarli
 * @brief 
 * @version 0.1
 * @date 2022-06-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef LINKEDLIST_H
#define LINKEDLIST_H


CLTpye *CLT_AddEnd(CLTpye *head,Data nodedata); //追加节点
CLTpye *CLT_AddFirst(CLTpye *head,Data nodedata); //插入头节点
CLTpye *CLT_FindNode(CLTpye *head,char cont); //查找某个节点
CLTpye *CLT_InsertNode(CLTpye *head,CLTpye *findcont,Data nodedata); //插入结点
CLTpye *CLT_DeleteNode(CLTpye *head,char cont); //删除某个节点
int CLT_Length(CLTpye *head); //计算节点的长度
void CTL_DsplayAllNode(CLTpye *head); //显示所有结点


#endif