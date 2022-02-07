#include"linkStack.h"
#include"linkList.h"
#include<stdio.h>
#include<malloc.h>

//将栈节点转化为链表节点
typedef struct _tag_LinkStackNode
{
	LinkListNode next;
	void* item;//栈节点
}TLinkStackNode;

//创建栈
LinkStack* linkStack_Create()
{
	return linkList_Create();
}


//删除栈
void linkStack_Destroy(LinkStack* stack)
{
	linkStack_Clear(stack);
	linkList_Destroy(stack);
}


//清空栈，相当于清空链表，另外还需要栈中元素的空间都释放掉
void linkStack_Clear(LinkStack* stack)
{
	TLinkStackNode* stackNode = NULL;

	if (stack == NULL)
	{
		printf("func linkStack_Push() err.-1\n");
		return;
	}

	while (linkList_Length(stack) > 0)
	{
		linkStack_Pop(stack);//将栈中的元素都出栈，以释放栈中元素的空间
	}

	//清空链表
	linkList_Clear(stack);
}

//获取栈大小
int linkStack_Length(LinkStack* stack)
{
	if (stack == NULL)
	{
		printf("func linkStack_Push() err.-1\n");
		return -1;
	}

	return linkList_Length(stack);
}

//进栈,相当于在链表的头部插入元素
int linkStack_Push(LinkStack* stack, void* item)
{
	TLinkStackNode* stackNode = NULL;
	int ret = 0;

	if (stack == NULL || item==NULL )
	{
		printf("func linkStack_Push() err.-1\n");
		return -1;
	}

	//将栈节点转化为链表节点
	stackNode = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
	if (stackNode == NULL)
	{
		printf("func linkStack_Push() err.-2\n");
		return -2;
	}
	stackNode->item = item;//将业务节点放入链表节点

	ret = linkList_Insert(stack, (LinkListNode*)stackNode, 0);

	if (ret != 0)
	{
		printf("func linkStack_Push() err.-3\n");
		if (stackNode != NULL)
		{
			free(stackNode);
		}
	}

	return ret;
}


//出栈
//相当于在链表头部删除元素，还需要释放删除的元素的空间
void* linkStack_Pop(LinkStack* stack)
{
	TLinkStackNode* stackNode = NULL;
	void* ret = NULL;

	if (stack == NULL)
	{
		printf("func linkStack_Pop() err -1\n ");
		return NULL;
	}

	stackNode = (TLinkStackNode*)linkList_Delete(stack, 0);
	if (stackNode == NULL)
	{
		return NULL;
	}

	ret = stackNode->item;//保存栈节点

	free(stackNode);//释放链表节点的空间

	return ret;

}


//获取栈顶元素，相当于获取链表的第一个节点
void* linkStack_Top(LinkStack* stack)
{
	TLinkStackNode* stackNode = NULL;
	void* ret = NULL;

	if (stack == NULL)
	{
		printf("func linkStack_Pop() err -1\n ");
		return NULL;
	}

	stackNode = (TLinkStackNode*)linkList_Get(stack, 0);
	if (stackNode == NULL)
	{
		return NULL;
	}

	ret = stackNode->item;//保存栈节点

	return ret;
}
