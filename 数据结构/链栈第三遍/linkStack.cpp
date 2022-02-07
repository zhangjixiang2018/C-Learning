#include"linkList.h"
#include"linkStack.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>

//��ջ�ڵ�ת��Ϊ����ڵ�
typedef struct _tag_LinkStackNode
{
	LinkListNode next;
	void* item;//����ڵ�
}TLinkStackNode;

//������ջ,�൱�ڴ�������
LinkStack* linkStack_Create()
{
	return linkList_Create();
}


//����ջ,1.���ջ��2.��������
void linkStack_Destroy(LinkStack* stack)
{
	linkStack_Clear(stack);
	linkList_Destroy(stack);

}


//���ջ,1.��ջ�е�Ԫ�ض�������2.�������
void linkStack_Clear(LinkStack* stack)
{
	while (linkList_Length(stack) > 0)
	{
		linkStack_Pop(stack);
	}

	linkList_Clear(stack);

	return ;

}


//��ȡջ�ĳ���,�൱�ڻ�ȡ����ĳ���
int linkStack_Length(LinkStack* stack)
{

	return linkList_Length(stack);
}


//��ջ,�൱���������ͷ������Ԫ��
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

	stackNode = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));//��������ڵ�
	if (stackNode == NULL)
	{
		ret = -2;
		printf("func linkStack_Push() err.-2\n");
		return ret;
	}
	memset(stackNode, 0, sizeof(TLinkStackNode));

	//��ջ�ڵ�ת��Ϊ����ڵ�
	stackNode->item = item;

	ret = linkList_Insert(stack, (LinkListNode*)stackNode, 0);//������ڵ����������

	if (ret != 0)//����ʧ��
	{
		printf("func linkStack_Push() err.%d", ret);
		if (stackNode != NULL)
		{
			free(stackNode);//�ͷſռ�

		}
		return ret;
	}

	return ret;

}


//��ջ,�൱���������ͷ��ɾ������
void* linkStack_Pop(LinkStack* stack)
{
	void* ret = NULL;
	TLinkStackNode* stackNode = NULL;

	if (stack == NULL)
	{
		printf("func linkStack_Pop() err.-1\n");
		return NULL;
	}

	stackNode = (TLinkStackNode*)linkList_Delete(stack, 0);//ɾ�������еĵ�һ��Ԫ��
	if (stackNode == NULL)
	{
		printf("func linkStack_Pop() err.-2\n");
		return NULL;
	}

	ret = stackNode->item;//����ջ�ڵ�

	free(stackNode);//�ͷ�����ڵ�ռ�

	return ret;

}


//��ȡջ��Ԫ�أ��൱�ڻ�ȡջ���ĵ�һ��Ԫ��
void* linkStack_Top(LinkStack* stack)
{
	void* ret = NULL;
	TLinkStackNode* stackNode = NULL;

	if (stack == NULL)
	{
		printf("func linkStack_Pop() err.-1\n");
		return NULL;
	}

	stackNode = (TLinkStackNode*)linkList_Get(stack, 0);//��ȡ�����еĵ�һ��Ԫ��
	if (stackNode == NULL)
	{
		printf("func linkStack_Pop() err.-2\n");
		return NULL;
	}

	ret = stackNode->item;//����ջ�ڵ�

	return ret;

}