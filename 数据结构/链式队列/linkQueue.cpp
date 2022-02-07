#include"linkQueue.h"
#include"linkList.h"
#include<stdio.h>
#include<string.h>
#include<malloc.h>

//将队列业务节点封装为链表业务节点
//链表节点
typedef struct _tag_LinkQueueNode
{
	LinkListNode next;
	void* item;//队列节点
}LinkQueueNode;

//创建队列,相当于创建链表
LinkQueue* linkQueue_Create()
{
	return linkList_Create();
}


//销毁队列。释放元素的空间，销毁链表。
void linkQueue_Destroy(LinkQueue* queue)
{
	linkQueue_Clear(queue);
	linkList_Destroy(queue);
	return;
}


//清空队列。释放元素的空间，清空链表。
void linkQueue_Clear(LinkQueue* queue)
{
	while (linkList_Length(queue) > 0)
	{
		linkQueue_Retrive(queue);//将队列中元素都取出
	}

	linkList_Clear(queue);
	return;
}


//获取队列的长度，相当于获取链表的长度
int linkQueue_Length(LinkQueue* queue)
{
	return linkList_Length(queue);
}


//添加元素,相当于在链表的尾部插入元素
int linkQueue_Append(LinkQueue* queue, void* item)
{
	int ret = 0;
	LinkQueueNode* queueNode = NULL;
	if (queue == NULL || item == NULL)
	{
		ret = -1;
		printf("func linkQueue_Append() err -1\n");
		return ret;
	}

	queueNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));//开辟队列节点空间
	if (queueNode == NULL)
	{
		ret = -2;
		printf("func linkQueue_Append() err -2\n");
		return ret;
	}
	memset(queueNode, 0, sizeof(LinkQueueNode));

	queueNode->item = item;//将队列业务节点放进链表业务节点

	ret = linkList_Insert(queue, (LinkListNode*)queueNode, linkList_Length(queue));//向队列尾部插入节点

	if (ret != 0)//向队列中添加元素失败
	{
		printf("func linkQueue_Append() err %d\n",ret);
		free(queueNode);
		return ret;
	}

	return ret;
}


//从队列中取回一个元素，相当于从链表头部删除一个元素
void* linkQueue_Retrive(LinkQueue* queue)
{
	LinkQueueNode* queueNode = NULL;
	void* ret = NULL;

	if (queue == NULL )
	{
		printf("func linkQueue_Append() err -1\n");
		return NULL;
	}

	queueNode = (LinkQueueNode*)linkList_Delete(queue, 0);//从链表中删除首元素

	if (queueNode != NULL)
	{
		ret = queueNode->item;//保存队列节点
		free(queueNode);//释放链表节点空间
	}

	return ret;
}


//获取队头元素，相当于获取链表头部元素
void* linkQueue_Header(LinkQueue* queue)
{
	LinkQueueNode* queueNode = NULL;
	void* ret = NULL;

	if (queue == NULL)
	{
		printf("func linkQueue_Header() err -1\n");
		return NULL;
	}

	queueNode = (LinkQueueNode*)linkList_Get(queue, 0);//从链表中获取首元素

	if (queueNode == NULL)
	{
		printf("func linkQueue_Header() err -2\n");
		return NULL;
	}

	ret = queueNode->item;//保存队列节点

	return ret;

}
