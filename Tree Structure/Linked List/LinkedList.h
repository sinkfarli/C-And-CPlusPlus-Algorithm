/**
 * @file LinkedList.h
 * @author 影风远sinkfarli
 * @brief 
 *      以链表的形式表示二叉树
 * @version 0.1
 * @date 2022-06-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef LINKEDLIST_H
#define LINKEDLIST_H


CBTType *InitTree(); //初始化二叉树
CBTType *FindNode(CBTType *node,Data data); //查找结点
void AddNode(CBTType *node); //添加结点
CBTType *LeftNode(CBTType *node); //获取左子树
CBTType *RightNode(CBTType *node); //获取右子树
int IsEmpty(CBTType *node); // 判断空树
int Depth(CBTType *node); //计算二叉树深度
void Clear(CBTType *node); //清空二叉树
void DisplayNodeData(CBTType *node); //显示结点数据
void LevelTree(CBTType *Node,void (*NodeData)(CBTType *p)); //按层遍历算法
void DLRTree(CBTType *Node,void (*NodeData)(CBTType *p)); //先序遍历算法
void LDRTree(CBTType *Node,void (*NodeData)(CBTType *p)); //中序遍历算法
void LRDTree(CBTType *Node,void (*NodeData)(CBTType *p)); //后序遍历算法


#endif