#include"linkList.h"
#include"linkStack.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>

//将栈节点转化为链表节点
typedef struct _tag_LinkStackNode
{
	LinkListNode next;
	void* item;//链表节点
}TLinkStackNode;

//创建链栈,相当于创建链表
LinkStack* linkStack_Create()
{
	return linkList_Create();
}


//销毁栈,1.清空栈，2.销毁链表
void linkStack_Destroy(LinkStack* stack)
{
	linkStack_Clear(stack);
	linkList_Destroy(stack);

}


//清空栈,1.将栈中的元素都弹出，2.清空链表
void linkStack_Clear(LinkStack* stack)
{
	while (linkList_Length(stack) > 0)
	{
		linkStack_Pop(stack);
	}

	linkList_Clear(stack);

	return ;

}


//获取栈的长度,相当于获取链表的长度
int linkStack_Length(LinkStack* stack)
{

	return linkList_Length(stack);
}


//进栈,相当于在链表的头部插入元素
int linkStack_Push(LinkStack* stack, void* item)
{
	int ret = 0;
	TLinkStackNode* stackNode = NULL;

	if (stack == NULL || item == NULL)
	{
		ret = -1;
		printf("func linkStack_Push() err.-1\n");
		return ret;
	}

	stackNode = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));//创建链表节点
	if (stackNode == NULL)
	{
		ret = -2;
		printf("func linkStack_Push() err.-2\n");
		return ret;
	}
	memset(stackNode, 0, sizeof(TLinkStackNode));

	//将栈节点转化为链表节点
	stackNode->item = item;

	ret = linkList_Insert(stack, (LinkListNode*)stackNode, 0);//将链表节点插入链表中

	if (ret != 0)//插入失败
	{
		printf("func linkStack_Push() err.%d", ret);
		if (stackNode != NULL)
		{
			free(stackNode);//释放空间

		}
		return ret;
	}

	return ret;

}


//出栈,相当于在链表的头部删除数据
void* linkStack_Pop(LinkStack* stack)
{
	void* ret = NULL;
	TLinkStackNode* stackNode = NULL;

	if (stack == NULL)
	{
		printf("func linkStack_Pop() err.-1\n");
		return NULL;
	}

	stackNode = (TLinkStackNode*)linkList_Delete(stack, 0);//删除链表中的第一个元素
	if (stackNode == NULL)
	{
		printf("func linkStack_Pop() err.-2\n");
		return NULL;
	}

	ret = stackNode->item;//保存栈节点

	free(stackNode);//释放链表节点空间

	return ret;

}


//获取栈顶元素，相当于获取栈顶的第一个元素
void* linkStack_Top(LinkStack* stack)
{
	void* ret = NULL;
	TLinkStackNode* stackNode = NULL;

	if (stack == NULL)
	{
		printf("func linkStack_Pop() err.-1\n");
		return NULL;
	}

	stackNode = (TLinkStackNode*)linkList_Get(stack, 0);//获取链表中的第一个元素
	if (stackNode == NULL)
	{
		printf("func linkStack_Pop() err.-2\n");
		return NULL;
	}

	ret = stackNode->item;//保存栈节点

	return ret;

}