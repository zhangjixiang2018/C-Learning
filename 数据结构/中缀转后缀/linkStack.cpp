#include"linkStack.h"
#include"linkList.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>

//将栈节点封装为链表节点
typedef struct LinkStackNode
{
	LinkListNode node;
	void* item;//栈节点
}LinkStackNode;

//创建栈
//相当于创建链表
LinkStack* linkStack_Create()
{
	return linkList_Create();
}


//删除栈
//先清空栈，再Destory链表
void linkStack_Destroy(LinkStack* stack)
{
	linkStack_Clear(stack);
	linkList_Destroy(stack);
}

//清空栈
//相当于清空链表，涉及到元素的生命周期管理，需要栈中的元素出栈并释放内存然后在清空链表
void linkStack_Clear(LinkStack* stack)
{
	LinkStackNode* sNode = NULL;
	void* tmp = NULL;

	if (stack == NULL)
	{
		printf("func linkStack_Clear() err. -1\n");
		return ;
	}

	//将栈中的元素都出栈
	while (linkList_Length(stack) > 0)
	{
		linkStack_Pop(stack);
	}

	//清空栈
	linkList_Clear(stack);
}


//获取栈的大小
//相当于获取链表的大小
int linkStack_Length(LinkStack* stack)
{
	return linkList_Length(stack);
}


//进栈
//相当于在链表的头部插入节点，尾部插入的话需要移动大量元素。
//需要将栈业务节点转换为链表业务节点，链表节点要在堆上，注意生命周期
int linkStack_Push(LinkStack* stack, void* item)
{
	LinkStackNode* sNode = NULL;
	int ret = 0;

	if (stack == NULL || item == NULL)
	{
		printf("func linkStack_Push() err.-1\n");
		return -1;
	}

	sNode = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (sNode == NULL)
	{
		printf("func linkStack_Push() err.-2\n");
		return -2;
	}
	memset(sNode, 0, sizeof(LinkStackNode));

	sNode->item = item;//将栈节点存储到链表节点

	ret = linkList_Insert(stack, (LinkListNode*)sNode, 0);//将节点插入到链表
	if (ret != 0)
	{
		printf("func linkStack_Push() err.-3\n");
		if (sNode != NULL)
		{
			free(sNode);
		}
		return ret;
	}
	return 0;
}


//出栈
//相当于从链表的头部删除元素
//需要释放空间
void* linkStack_Pop(LinkStack* stack)
{
	LinkStackNode* sNode = NULL;
	void* ret = NULL;//栈的业务节点

	if (stack == NULL)
	{
		printf("func linkStack_Pop() err. -1\n");
		return NULL;
	}

	sNode = (LinkStackNode*)linkList_Delete(stack, 0);//删除链表头部元素，返回栈节点元素
	if (sNode == NULL)
	{
		return NULL;
	}

	ret = sNode->item;//保存业务节点

	free(sNode);//释放栈节点开辟的空间
	return ret;
}


//获取栈顶元素
//相当于获取链表头部元素
void* linkStack_Top(LinkStack* stack)
{
	LinkStackNode* sNode = NULL;
	void* ret = NULL;

	if (stack == NULL)
	{
		printf("func linkStack_Top() err. -1\n");
		return NULL;
	}

	sNode = (LinkStackNode*)linkList_Get(stack, 0);
	if (sNode == NULL)
	{
		return NULL;
	}

	ret = sNode->item;

	return ret;
}
