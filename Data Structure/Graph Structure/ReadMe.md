# 图结构（Graph Structure）
Author & Note ：影风远sinkfarli

Create Date ：2022.6.15

图（Graph）结构也是一种非线性数据结构，图结构在实际生活中具有非常多的例子。例如，通信网络、交通网络、人际关系网络等都可以归结为图结构。图结构的组织形式比树结构更为复杂。因此，图结构对存储和遍历等操作具有更高的要求。

## 什么是图结构？
树结构的一个基本特点，是数据元素之间具有层次关系，每一层的元素可以和多个下层元素关联，但是只能和一个上层元素关联。如果把这个规则进一步扩展，也就是说，每个数据元素之间可以任意关联，这就构成了一个图结构。正是这种任意关联性，导致了图结构中数据关系的复杂性。研究图结构的一个专门理论工具便是图论。

一个典型的图结构包括如下两个部分：
- 顶点（Vertex）：图中的数据元素。
- 边（Edge）：图中连接这些顶点的线。

所有的顶点构成一个顶点集合，所有的边构成边集合，一个完整的图结构就是由顶点集合和边集合组成。图结构在数学上一般记为如下所示的形式。
$$G=（V，E）或者G=（V（G），E（G））$$
<img src="./../Tree%20Structure/photo/7.png">

其中，V（G）表示图结构中所有顶点的集合，顶点可以用不同的数字或者字母来表示。E（G）是图结构中所有边的集合，每条边由所连接的两个顶点表示。

**注意：图结构中顶点集合V（G）必须为非空，即必须包含一个顶点。而图结构中边集合E（G）可以为空，此时表示没有边。**

例如，对于图2-26所示的图结构，对应的顶点集合和边集合如下：
- V（G）={V1，V2，V3，V4，V5，V6}
- E（G）={（V1，V2），（V1，V3），（V1，V5），（V2，V4），（V3，V5），（V4，V5），（V4，V6），（V5，V6）}


## 图的基本概念
### 1.无向图
如果一个图结构中所有的边都没有方向性，这种图便被称为无向图。

典型的无向图如图2-27所示。由于无向图中的边没有方向性，在表示边时对两个顶点的顺序没有要求。例如顶点V1和顶点V5之间的边，可以表示为（V1，V5），也可以表示为（V5，V1）。
<img src="./../Tree%20Structure/photo/8.png">

### 2.有向图
如果一个图结构中边是有方向性的，这种图便被称为有向图。

典型的有向图如图2-28所示。由于有向图中的边有方向性，所以在表示边时对两个顶点的顺序有所要求。为了与无向图区分，这里采用尖括号表示有向边。例如，<V3，V4>表示从顶点V3到顶点V4的一条边，而<V4，V3>表示从顶点V4到顶点V3的一条边。<V3，V4>和<V4，V3>表示的是两条不同的边。
<img src="./../Tree%20Structure/photo/9.png">

### 3.顶点的度（Degree）
连接顶点的边的数量称为顶点的度。顶点的度在有向图和无向图中具有不同的意义。对于无向图，一个顶点V的度比较简单，是连接该顶点的边的数量，记为D（V）。例如，图2-27所示的无向图中，顶点V4的度为2，而V5的度为3。

对于有向图则稍微复杂一些，根据连接顶点V的边的方向性，一个顶点的度有入度和出度之分。
- 入度是以该顶点为端点的入边数量，记为ID（V）。
- 出度是以该顶点为端点的出边数量，记为OD（V）。

在有向图中，一个顶点V的度便是入度和出度之和，即D（V）=ID（V）+OD（V）。例如，图2-28所示的有向图中，顶点V3的入度为2，出度为1，因此，顶点V3的度为3。

### 4.邻接顶点
邻接顶点是指图结构中一条边的两个顶点。邻接顶点在有向图和无向图中具有不同的意义。对于无向图，邻接顶点比较简单。例如，在图2-27所示的无向图中，顶点V1、V5互为邻接顶点，另外，顶点V1的邻接顶点有顶点V2、顶点V3和顶点V5。

对于有向图则稍微复杂一些，根据连接顶点V的边的方向性，两个顶点分别被称为起始顶点（起点或始点）和结束顶点（终点）。有向图的邻接顶点可分为两类。

入边邻接顶点：连接该顶点的边中的起始顶点。例如，对于组成<V1，V2>这条边的两个顶点，V1是V2的入边邻接顶点。

出边邻接顶点：连接该顶点的边中的结束顶点。例如，对于组成<V1，V2>这条边的两个顶点，V2是V1的出边邻接顶点。

### 5.无向完全图
如果在一个无向图中，每两个顶点之间都存在一条边，那么这种图结构被称为无向完全图。典型的无向完全图如图2-29所示。
<img src="./../Tree%20Structure/photo/10.png">

从理论上可以证明，对于1个包含n个顶点的无向完全图，其总的边数为n（n-1）/2。

### 6.有向完全图
如果在一个有向图中，每两个顶点之间都存在方向相反的两条边，那么这种图结构被称为有向完全图。典型的有向完全图如图2-30所示。
<img src="./../Tree%20Structure/photo/11.png">

从理论上可以证明，对于一个包含n个顶点的有向完全图，其总的边数为n（n-1），是无向完全图的两倍，这个也很好理解，因为每两个顶点之间需要两条边。

### 7.子图
子图的概念类似于子集合，由于一个完整的图结构包括所有的顶点和边，因此任意一个子图的顶点和边都应该是完整图结构的子集合。例如，图2-31中的图（a）为一个无向图结构，图（b）、图（c）和图（d）均为图（a）的子图。
<img src="./../Tree%20Structure/photo/12.png">

这里需要强调的是，只有顶点集合是子集的，或者只有边集合是子集的，都不是子图。

### 8.路径
路径就是图结构中两个顶点之间的连线，路径上边的数量称之为路径长度。两个顶点之间的路径可能途经多个其他顶点，两个顶点之间的路径也可能不止一条，相应的路径长度可能不一样。

典型的图结构中的路径如图2-32所示。粗线部分显示的是顶点V5到V2之间的一条路径，这条路径途经的顶点为V4，途经的边依次为（V5，V4）、（V4，V2），路径长度为2。
<img src="./../Tree%20Structure/photo/13.png">

同样，也可以在该图中找到顶点V5到V2之间的其他路径，分别如下所示。
- 路径（V5，V1）、（V1，V2），途经顶点V1，路径长度为2。
- 路径（V5，V3）、（V3，V1）、（V1，V2），途经顶点V1和V3，路径长度为3。

图结构中的路径还可以细分为如下几种形式。
- 简单路径：在图结构中，如果一条路径上顶点不重复出现，称为简单路径。
- 环：在图结构中，如果路径的第一个顶点和最后一个顶点相同，称为环，有时也称为回路。
- 简单回路：在图结构中，如果除第一个顶点和最后一个顶点相同外，其余各顶点都不重复的回路称为简单回路。

### 9.连通、连通图和连通分量
通过路径的概念，可以进一步研究图结构的连通关系，主要涉及如下几点。

- 如果图结构中两个顶点之间有路径，则这两个顶点是连通的。需要注意连通的两个顶点可以不是邻接顶点，只要有路径连接即可，可以途经多个顶点。
- 如果无向图中任意两个顶点都是连通的，那么这个图便称为连通图。
- 如果无向图中包含两个顶点是不连通的，那么这个图便称为非连通图。
- 无向图的极大连通子图称为该图的连通分量。

从理论上可以证明，对于一个连通图，其连通分量有且只有一个，就是该连通图自身。而对于一个非连通图，则有可能存在多个连通分量。例如，在图2-33所示的图结构中，图（a）为一个非连通图，因为顶点V2和顶点V3之间没有路径。这个非连通图中的连通分量包括两个，分别为图（b）和图（c）。
<img src="./../Tree%20Structure/photo/14.png">

### 10.强连通图和强连通分量
与无向图类似，在有向图中也有连通的概念，主要涉及如下几个。

如果两个顶点之间有路径，也称这两个顶点是连通的。需要注意的是，有向图中边是有方向的。

因此，有时从Vi到Vj是连通的，但从Vj到Vi却不一定连通。

如果有向图中任意两个顶点都是连通的，则称该图为强连通图。如果有向图中包含两个顶点不是连通的，则称该图为非强连通图。

有向图的极大强连通子图称为该图的强连通分量。

从理论上可以证明，强连通图有且只有一个强连通分量，那就是该图自身。而对于一个非强连通图，则有可能存在多个强连通分量。例如，在图2-34所示的图结构中，图（a）为一个非强连通图，因为其中顶点V2和顶点V3之间没有路径。这个非强连通图中的强连通分量包括两个，分别为图（b）和图（c）。
<img src="./../Tree%20Structure/photo/15.png">

### 11.权
前面介绍的图结构的各个边并没有赋予任何含义，而在实际的应用中往往需要将边表示成某种数值，这个数值便是该边的权（Weight）。无向图中加入权值，称为无向带权图；有向图中加入权值，称为有向带权图。典型的无向带权图和有向带权图如图2-35所示。
<img src="./../Tree%20Structure/photo/16.png">

权在实际应用中可以代表各种含义。例如，在交通图中表示道路的长度，在通信网络中表示基站之间的距离，在人际关系中代表亲密程度等。

### 12.网（Network）
网是边上带有权值的图的另一种名称。网的概念与实际应用更为贴切。



