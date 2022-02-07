#include<stdlib.h>
#include<stdio.h>
#include "queue.h"

//初始化队列
void initializeQueue(Queue* pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

//检查队列是否已满，如果队列已满返回true,否则返回false
bool queueIsFull(const Queue* pq)
{
	return pq->items == MAXNODES;
}

//检查队列是否为空，如果队列为空返回true，否则返回false
bool queueIsEmpty(const Queue* pq)
{
	return pq->items == 0;
}

//返回队列中的项数
int queueItemCount(const Queue* pq)
{
	return pq->items;
}

static void copyToNode(Node* new_node, Item item)
{
	new_node->item = item;
}
//在队列末尾添加项，item是要被添加的项
//创建一个新节点
//把项拷贝到新节点中
//设置节点的next指针为NULL，表示该节点是最后一个节点
//设置当前为节点的next指针指向新节点，把新节点链接到队列中
//把rear指针指向新节点，以便找到最后的节点
//项数加1
bool addItem(Item item, Queue* pq)
{
	Node* new_node;

	if (queueIsFull(pq) == true)//队列已满，不能往队列中继续增加项
	{
		return false;
	}

	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		fprintf(stderr, "Unable to allocate memory!\n");
		exit(1);
	}

	copyToNode(new_node, item);
	new_node->next = NULL;

	if (queueIsEmpty(pq) == true)//队列为空时，项位于队列首端
	{
		pq->front = new_node;	
	}
	else//队列不为空时，将项链接到队列的尾端
	{
		pq->rear->next = new_node;
	}

	pq->rear = new_node;//记录队列尾端的位置
	pq->items++;
	return true;
}

static void copyToItem(Item* pitem, Node* pnode)
{
	*pitem = pnode->item;
}
//从队列的开头删除项。如果队列不为空，队列首端的item将被拷贝到*pitem中，并被删除，且函数返回true
//如果该操作使得队列为空，则重置队列为空，如果队列在操作前为空，该函数返回false。
bool deItem(Item* pitem, Queue* pq)
{
	Node* pt;//临时变量
	if (queueIsEmpty(pq) == true)//队列为空
	{
		return false;
	}

	copyToItem(pitem, pq->front);//取出队列首项

	pt = pq->front;
	pq->front = pq->front->next;//将首指针后移
	free(pt);//释放被移除项的空间
	pq->items--;

	if (pq->items == 0)
	{
		pq->rear = NULL;
	}

	return true;
}

//清空队列  
void emptyQueue(Queue* pq)
{
	Item item;
	while (!queueIsEmpty(pq))
	{
		deItem(&item, pq);
	}
}

