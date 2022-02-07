#include"seqStack.h"
#include"seqList.h"
#include<stdio.h>

//����˳��ջ���൱�ڴ���˳���
SeqStack* seqStack_Create(int capacity)
{
	return SeqList_Create(capacity);
}


//ɾ��˳��ջ���൱��ɾ��˳���
void seqStack_Destroy(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("func seqStack_Destroy() err.-1\n");
		return;
	}
	SeqList_Destroy(stack);
}


//���˳��ջ���൱�����˳���
void seqStack_Clear(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("func seqStack_Clear() err.-1\n");
		return;
	}
	SeqList_Clear(stack);
}

//��ȡ˳��ջ���������൱�ڻ�ȡ˳���ĵ�����
int seqStack_Capacity(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("func seqStack_Clear() err.-1\n");
		return -1;
	}

	return SeqList_Capacity(stack);
}



//��ȡ˳��ջ�ĳ��ȣ��൱�ڻ�ȡ˳���ĵĳ���
int seqStack_Length(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("func seqStack_Clear() err.-1\n");
		return -1;
	}

	return SeqList_Length(stack);
}


//��ջ���൱����˳����β������Ԫ��
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


//��ջ���൱����˳����β��ɾ���ڵ�
void* seqStack_Pop(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("func seqStack_Pop() err.-1\n");
		return NULL;
	}

	return SeqList_Delete(stack, SeqList_Length(stack) - 1);
}


//��ȡջ���ڵ㣬�൱�ڻ�ȡ˳����β���ڵ�
void* seqStack_Top(SeqStack* stack)
{
	if (stack == NULL)
	{
		printf("func seqStack_Pop() err.-1\n");
		return NULL;
	}

	return SeqList_Get(stack, SeqList_Length(stack) - 1);
}