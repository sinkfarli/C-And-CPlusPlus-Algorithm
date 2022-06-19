/**
 * @file GraphStructure.c
 * @author 影风远sinkfarli
 * @brief 
 *      图结构的算法
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "stdio.h"
#include "GraphStructure.h"


#define MaxNum 20 //最大顶点数
#define MaxValue 65535 //最大值


/**
 * @brief 图结构的数据结构
 */
typedef struct GraphMatrix{
    char Vertex[MaxNum];                //保存顶点信息（序号或字母）
    int CType;                          //图的类型（0：无向图，1. 有向图）
    int VertexNum;                      //顶点的数量
    int EdgeNum;                        //边的数量
    int EdgeWeight[MaxNum][MaxNum];     //保存边的权
    int isTrav[MaxNum];                 //遍历标志
}GraphMatrix;                           //定义邻接矩阵结构


/**
 * @brief 
 *      在使用图结构之前，首先要创建并初始化一个图。
 *      
 *      程序中，由用户输入顶点信息和边的信息。
 *      对于边来说，需要输入的信息包括起始顶点、结束顶点和权值，各项之间以空格分隔。
 *      后判断该图结构是否为无向图，因为无向图还需将边的权值保存到对角位置。
 * 
 * @param GM 指向图结构的指针
 */
void CreateInit(GraphMatrix *GM)
{
    int i,j,k;
    int weight; //权
    char EstartV,EendV; //边的起始顶点

    printf("输入图中个顶点信息\n");
    /* 输入顶点 */
    for(i = 0;i < GM->VertexNum;i++)
    {
        getchar();
        printf("第%d个顶点:",i+1);
        scanf("%c",&(GM->Vertex[1])); //保存到各顶点数组元素中
    }

    printf("输入构成各边的顶点及权值:\n");
    /* 输入边的信息 */
    for(k = 0;k < GM->EdgeNum;k++)
    {
        getchar();
        printf("第%d条边:",k+1);
        scanf("%c %c %d",&EstartV,&EendV,&weight);

        for(i = 0;EstartV != GM->Vertex[i];i++); //在已有的顶点中查找起始点
        for(j = 0;EendV != GM->Vertex[j];j++);   //在已有的顶点中查找终点

        GM->EdgeWeight[i][j] = weight; //对应位置保存权值，表示有一条边

        /* 若是无向图 */
        if(GM->CType == 0)
        {
            GM->EdgeWeight[j][i] = weight; //在对角位置保存权值
        }
    }
}


/**
 * @brief 
 *      清空图就是将一个图结构变成一个空图，这里只需将矩阵中各个元素设置为MaxValue即可。
 * 
 *      程序中，通过双重循环来为矩阵中各个元素赋值MaxValue，表示这是一个空图。
 * 
 * @param GM 指向图结构的指针
 */
void Clear(GraphMatrix *GM)
{
    int i,j;

    /* 清空矩阵 */
    for(i = 0;i < GM->VertexNum;i++)
    {
        for(j = 0;j < GM->VertexNum;j++)
        {
            GM->EdgeWeight[i][j] = MaxValue; //设置矩阵中各元素的值为MaxValue
        }
    }
}


/**
 * @brief 
 *      显示图就是显示图的邻接矩阵，用户可以通过邻接矩阵方便地了解图的顶点和边的结构信息。
 * 
 *      程序中，首先在第1行输出顶点信息。
 *      然后，逐个输出矩阵中的每个元素。
 *      这里用Z表示无穷大MaxValue。
 * 
 * @param GM 指向图结构的指针
 */
void Display(GraphMatrix *GM)
{
    int i,j;

    /* 在第一行输出顶点信息 */
    for(j = 0;j < GM->VertexNum;j++)
    {
        printf("\t%c",GM->VertexNum[j]);
    }
    printf("\n");

    for(i = 0;i < GM->VertexNum;i++)
    {
        printf("%c",GM->Vertex[i]);

        for(j = 0;j < GM->VertexNum;j++)
        {
            if(GM->EdgeWeight[i][j] == MaxValue)
            {
                printf("\tZ"); //用Z表示无穷大
            }
            else
            {
                printf("\t%d",GM->EdgeWeight[i][j]); //输出的权值
            }
        }
        printf("\n");
    }
}


/**
 * @brief 
 *      深度优先遍历算法。
 *      深度优先遍历算法类似于树的先序遍历，具体执行过程如下：
 *          1. 首先，从数组isTrav中选择一个未被访的顶点Vi，将其标记为1，表示已访问。
 *          2. 接着，从Vi的一个未被访问过的邻接点出发进行深度优先遍历。
 *          3. 重复步骤（2），直至图中所有和Vi有路径相通的顶点都被访问过。
 *          4. 重复步骤（1）～（3）的操作，直到图中所有顶点都被访问过。
 *      深度优先遍历算法是一个递归过程。
 * 
 *      程序中通过调用函数DeepTraOne来完成所有顶点的遍历。
 *      函数DeepTraOne从第n个结点开始深度遍历图。
 * 
 * @param GM    指向图结构的指针
 * @param n     顶点编号
 */
void DeepTraOne(GraphMatrix *GM,int n)
{
    int n;
    GM->isTrav[n] = 1; //标记该顶点已处理过
    printf("->%c",GM->Vertex[n]); //输出节点数据

    /* 添加处理节点操作 */
    for(i = 0;i < GM->VertexNum;i++)
    {
        if(GM->EdgeWeight[n][i] != MaxValue && !GM->isTrav[n])
        {
            DeepTraOne(GM,i); //递归进行遍历
        }
    }
}


/**
 * @brief 
 *      函数DeepTra用于执行完整的深度优先遍历，以访问所有的顶点。
 * 
 * @param GM 
 */
void DeepTra(GraphMatrix *GM)
{
    int i;

    /* 清除各顶点遍历的标志 */
    for(i = 0;i < GM->VertexNum;i++)
    {
        GM->isTrav[i] = 0;
    }

    printf("深度优先遍历节点：");
    for(i = 0;i < GM->isTrav;i++)
    {
        /* 若该点来遍历 */
        if(!GM->isTrav[i])
        {
            DeepTraOne(GM,i); //调用函数遍历
        }
    }
    printf("\n");
}

