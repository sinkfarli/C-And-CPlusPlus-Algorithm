# ReadMe
Author & Note ：影风远sinkfarli

Create Date ：2022.6.12

## 队列结构
队列结构和栈结构类似。

### 什么是队列结构？
队列结构是从数据的运算来分类的，也就是说队列结构具有特殊的运算规则。而从数据的逻辑结构来看，队列结构其实就是一种线性结构。如果从数据的存储结构来进一步划分，队列结构可以分为两类：
- 顺序队列结构：
  即使用一组地址连续的内存单元依次保存队列中的数据。
- 链式队列结构：
  即使用链表形式保存队列中各元素的值。

队列结构中允许对两端进行操作，但是两端的操作不同。在表的一端只能进行删除操作，称为队头；在表的另一端只能进行插入操作，称为队尾。如果队列中没有数据元素，则称为空队列。

从数据的运算角度来分析，队列结构是按照“先进先出”（First In First Out，FIFO）的原则处理结点数据。

其实，队列结构在日常生活中有很多例子。例如银行的电子排号系统，先来的人取的号靠前，后来的人取的号靠后。这样，先来的人将最先得到服务，后来的人将后得到服务，一切按照“先来先服务”的原则。

在硬件的存储类芯片中，有一类根据队列结构构造的芯片，就是FIFO芯片。这类芯片具有一定的容量，其一端作为数据的存入，另一端作为数据的读出。先存入的数据将先被读出。

在队列结构中，数据运算非常简单。一般队列结构的基本操作只有两个：
- 入队列：
  将一个元素添加到队尾（相当于到队列最后排队等候）。
- 出队列：
  将队头的元素取出，同时删除该元素，使后一个元素成为队头。

除此之外，还需要有初始化队列、获取队列长度等简单的操作。接下来看一下如何在C语言中建立顺序队列结构，并完成顺序队列结构的基本运算。