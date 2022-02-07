#include"seqStack.h"
#include"seqList.h"
#include<stdio.h>

//创建顺序栈，相当于创建顺序表
SeqStack* seqStack_Create(int capacity)
{
	return SeqList_Create(capacity);
}


//删除顺序栈，相当于删除顺序表
void seqStack_Destroy(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("func seqStack_Destroy() err.-1\n");
		return;
	}
	SeqList_Destroy(stack);
}


//清空顺序栈，相当于清空顺序表
void seqStack_Clear(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("func seqStack_Clear() err.-1\n");
		return;
	}
	SeqList_Clear(stack);
}

//获取顺序栈的容量，相当于获取顺序表的的容量
int seqStack_Capacity(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("func seqStack_Clear() err.-1\n");
		return -1;
	}

	return SeqList_Capacity(stack);
}



//获取顺序栈的长度，相当于获取顺序表的的长度
int seqStack_Length(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("func seqStack_Clear() err.-1\n");
		return -1;
	}

	return SeqList_Length(stack);
}


//进栈，相当于在顺序表的尾部插入元素
int seqStack_Push(SeqStack* stack, void* node)
{
	int ret=0;
	if (stack == NULL || node == NULL)
	{
		printf("func seqStack_Push() err.-1\n");
		return -1;
	}

	ret = SeqList_Insert(stack, node, SeqList_Length(stack));

	return ret;
}


//出栈，相当于在顺序表的尾部删除节点
void* seqStack_Pop(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("func seqStack_Pop() err.-1\n");
		return NULL;
	}

	return SeqList_Delete(stack, SeqList_Length(stack) - 1);
}


//获取栈顶节点，相当于获取顺序表的尾部节点
void* seqStack_Top(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("func seqStack_Pop() err.-1\n");
		return NULL;
	}

	return SeqList_Get(stack, SeqList_Length(stack) - 1);
}