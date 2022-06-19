/**
 * @file LinkedList.cpp
 * @author 影风远sinkfarli
 * @brief 
 *      以链表的形式表示二叉树
 * @version 0.1
 * @date 2022-06-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "stdio.h"
#include "LinkedList.h"


#define MAXLength 20 //最大长度


typedef char Data; //定义数据类型


/**
 * @brief 二叉树的数据结构      
 */
typedef struct CBT{
    Data data; //节点数据
    CBT *left; //左子树节点指针
    CBT *right; //右子树节点指针
}CBTType;


/**
 * @brief 
 *      首先要初始化二叉树。
 *      在这里，在程序中只需将一个结点设置为二叉树的根结点。
 * @return CBTType* 
 */
CBTType *InitTree()
{
    CBTType *node; //二叉树

    /* 内存申请 */ 
    if(node = (CBTType *)malloc(sizeof(CBTType)))
    {
        printf("输入根节点的数据\n");
        sacnf("%s",&node->data);

        node->left = NULL; 
        node->right = NULL;

        /* 二叉树的节点不为空 */
        if(node != NULL)
        {
            return node;
        }
        else
        {
            return NULL
        }
    }

    return NULL;
}


/**
 * @brief 
 *      查找结点就是遍历二叉树中的每一个结点，逐个比较数据，当找到目标数据时将返回该数据所在结点的指针。
 *      程序中，首先判断根结点是否为空，然后分别向左右子树递归查找。
 *      如果当前结点的数据与查找数据相等，则返回当前结点的指针。
 * @param node 查找的节点指针
 * @param data 查找的数据
 * @return CBTType* 
 */
CBTType *FindNode(CBTType *node,Data data)
{
    CBTType *ptr;

    /* 判断这个二叉树是否为空 */
    if(node == NULL)
    {
        return NULL;
    }
    else
    {
        if(node->data == data)
        {
            return node;
        }
        /* 向左右查找 */
        else
        {
            if(ptr = FindNode(node->left,data))
            {
                return ptr;
            }
            else if(ptr = FindNode(node->right,data))
            {
                return ptr;
            }
            else
            {
                return NULL;
            }
        }
    }
}



/**
 * @brief 
 *      添加结点就是在二叉树中添加结点数据。
 *      添加结点时除了要输入结点数据外，还需要指定其父结点，以及添加的结点是作为左子树还是作为右子树。
 * @param node 要添加的节点
 */
void AddNode(CBTType *node)
{
    CBTType *pnode,parent;
    Data data;
    char menusel; //menu selection菜单选择

        /* 内存申请 */ 
    if(pnode = (CBTType *)malloc(sizeof(CBTType)))
    {
        printf("输入二叉树节点的数据\n");
        fflush(stdin);  //清理输入缓冲区
        scanf("%s",&node->data);
        pnode->left = NULL; //设置该节点的左右指针为空
        pnode->right = NULL;

        printf("输入该二叉树的父节点数据\n");
        fflush(stdin);  //清理输入缓冲区
        scanf("%s",&data);
        parent = FindNode(node,data); //查找指定的节点数据

        /* 如果未找到 */
        if(!parent)
        {
            printf("未找到节点\n");
            free(pnode); //是否要加入节点的空间
            return 0;
        }


        printf("1.添加该节点的左子树\n 2.添加该节点的右子树\n");
        do
        {
            menusel = getch(); //输入选择
            menusel -= 0;

            /* 判断是否选择对 */
            if(menusel == 1 ||menusel == 2)
            {
                /* 是否存在父节点 */
                if(parent == NULL)
                {
                    printf("不存在父节点，请先设置父节点\n");
                }

                /* 存在父节点 */
                else
                {
                    switch(menusel)
                    {
                        /* 添加左节点 */
                        case 1:
                            if(parent->letf)
                            {
                                printf("左节点不是空节点！\n")
                            }
                            else
                            {
                                parent->letf = pnode;
                            }
                            break;

                        /* 添加右节点 */
                        case 2:
                            if(parent->right)
                            {
                                printf("右节点不是空节点！\n")
                            }
                            else
                            {
                                parent->right = pnode;
                            }
                            break;

                        default:
                            printf("无效参数\n");
                    }
                }
            }

        } while (menusel !=1 && menusel !=2);    
    }
}


/**
 * @brief 
 *      获取左子树就是返回当前结点的左子树结点的值。
 * @param node 要获取的节点
 * @return CBTType* 
 */
CBTType *LeftNode(CBTType *node)
{
    if(node)
    {
        return node->letf;
    }
    else
    {
        return NULL;
    }
}


/**
 * @brief 
 *      获取右子树就是返回当前结点的右子树结点的值。
 * @param node 要获取的节点
 * @return CBTType* 
 */
CBTType *RightNode(CBTType *node)
{
    if(node)
    {
        return node->right;
    }
    else
    {
        return NULL;
    }
}


/**
 * @brief 
 *      判断空树就是判断一个二叉树结构是否为空。
 *      如果是空树，则表示该二叉树结构中没有数据。
 *      该函数检查二叉树是否为空，为空则返回1，否则返回0。
 * @param node 要判断的树指针
 * @return int 
 */
int IsEmpty(CBTType *node)
{
    if(node)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


/**
 * @brief 
 *      计算二叉树深度就是计算二叉树中结点的最大层数。
 *      采用递归算法来实现。
 * @param node 
 * @return int 
 */
int Depth(CBTType *node)
{
    int depleft,depright;

    /* 判断是否为空树，空树深度为0 */
    if(node == NULL)
    {
        return 0;
    }

    else
    {
        depleft = Depth(node->left);    //左子树深度（递归调用）
        depright = Depth(node->right);  //右子树深度（递归调用）

        if(depleft > depright)
        {
            return depleft + 1;
        }
        else
        {
            return depright + 1 ;
        }
    }
}


/**
 * @brief 
 *      清空二叉树就是将二叉树变成一个空树，这里也需要使用递归算法来实现。
 * @param node 要清空的树指针
 */
void Clear(CBTType *node)
{
    if(node)
    {
        Clear(node->left);
        Clear(node->right);
        free(node);
        node = NULL
    }
}


/**
 * @brief 
 *      显示结点数据就是显示当前结点的数据内容。
 * @param node 要显示节点的指针
 */
void DisplayNodeData(CBTType *node)
{
    printf("%s",node->data);
}


/**
 * @brief 
 *      按层遍历算法是最直观的遍历算法。
 *      首先处理第1层即根结点，再处理第1根结点的左右子树，也就是第2层……这样循环处理，即可逐层遍历。
 * @param Node      需要遍历的二叉树根结点
 * @param NodeData  一个需要对结点进行操作的函数
 */
void LevelTree(CBTType *Node,void (*NodeData)(CBTType *p))
{
    CBTType *p;
    CBTType *q[MAXLength]; //定义一个顺序栈
    int head = 0,tail = 0;

    /* 如果队首指针不为空 */
    if(Node)
    {
        tail = (tail + 1) % MAXLength; //计算循环队尾序号
        q[tail] = Node; //将二叉树根指针进队
    }

    /* 列表不为空，进行循环计算 */
    while(head != tail)
    {
        head = (head + 1) % MAXLength; //计算循环队列的队首序号
        p = q[head]; //获取队首元素
        NodeData(p); //处理队首元素

        /* 如果存在左子树 */
        if(p->left != NULL)
        {
            tail = (tail + 1) % MAXLength; //计算循环队列的队尾序号
            q[tail] = p->left; //将左子树指针进队
        }

        /* 如果存右左子树 */
        if(p->right != NULL)
        {
            tail = (tail + 1) % MAXLength; //计算循环队列的队尾序号
            q[tail] = p->right; //将右子树指针进队
        }        
    }
}


/**
 * @brief 
 *      先序遍历算法就是先按中序遍历左子树，再访问根结点，最后按中序遍历右子树。
 *      程序中可以按照递归的思路来遍历整个二叉树。
 * @param Node      需要遍历的二叉树根结点
 * @param NodeData  需要对结点进行操作的函数
 */
void DLRTree(CBTType *Node,void (*NodeData)(CBTType *p))
{
    if(Node)
    {
        NodeData(Node); //显示节点的数据

        DLRTree(Node->left,NodeData);
        DLRTree(Node->right,NodeData);        
    }
}

/**
 * @brief 
 *      中序遍历算法就是先访问根结点，再按先序遍历左子树，最后按先序遍历右子树。
 *      程序中可以按照递归的思路来遍历整个二叉树。
 * @param Node      需要遍历的二叉树根结点
 * @param NodeData  需要对结点进行操作的函数
 */
void LDRTree(CBTType *Node,void (*NodeData)(CBTType *p))
{
    if(Node)
    {
        DLRTree(Node->left,NodeData); //中序遍历左子树
        
         NodeData(Node); //显示节点的数据

        DLRTree(Node->right,NodeData); //中序遍历右子树
    }
}


/**
 * @brief 
 *      后序遍历算法就是先按后序遍历左子树，再按后序遍历右子树，最后访问根结点。
 *      程序中可以按照递归的思路来遍历整个二叉树。
 * @param Node      需要遍历的二叉树根结点
 * @param NodeData  需要对结点进行操作的函数
 */
void LRDTree(CBTType *Node,void (*NodeData)(CBTType *p))
{
        DLRTree(Node->left,NodeData); //后序遍历左子树
        DLRTree(Node->right,NodeData); //后序遍历右子树

        NodeData(Node); //显示节点的数据   
}