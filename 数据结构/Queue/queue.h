#ifndef QUEUE_H_
#define QUEUE_H_
#define MAXNODES 10;//队列最大节点数

typedef struct item
{
	long	arrive;//顾客到达的时间
	int		process_time;//顾客咨询时间长度
}Item;

typedef struct node
{
	Item item;
	struct node* next;
}Node;

typedef struct queue
{
	Node* front; //指向队列首项的指针
	Node* rear; //指向队列尾项的指针
	int items;//队列中的项数
}Queue;

void initializeQueue(Queue* pq);//初始化队列
bool queueIsFull(const Queue* pq);//检查队列是否已满，如果队列已满返回true,否则返回false
bool queueIsEmpty(const Queue* pq);//检查队列是否为空，如果队列为空返回true，否则返回false
int queueItemCount(const Queue* pq);//返回队列中的项数
bool addItem(Item item , Queue* pq);//在队列末尾添加项，item是要被添加的项
//从队列的开头删除项。如果队列不为空，队列首端的item将被拷贝到*pitem中，并被删除，且函数返回true
//如果该操作使得队列为空，则重置队列为空，如果队列在操作前为空，该函数返回false。
bool deItem(Item* pitem, Queue* pq);
void emptyQueue(Queue* pq);//清空队列  
                                   

#endif // !QUEUE_H_

