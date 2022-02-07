#include"linkStack.h"
#include"linkList.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>

//��ջ�ڵ��װΪ����ڵ�
typedef struct LinkStackNode
{
	LinkListNode node;
	void* item;//ջ�ڵ�
}LinkStackNode;

//����ջ
//�൱�ڴ�������
LinkStack* linkStack_Create()
{
	return linkList_Create();
}


//ɾ��ջ
//�����ջ����Destory����
void linkStack_Destroy(LinkStack* stack)
{
	linkStack_Clear(stack);
	linkList_Destroy(stack);
}

//���ջ
//�൱����������漰��Ԫ�ص��������ڹ�����Ҫջ�е�Ԫ�س�ջ���ͷ��ڴ�Ȼ�����������
void linkStack_Clear(LinkStack* stack)
{
	LinkStackNode* sNode = NULL;
	void* tmp = NULL;

	if (stack == NULL)
	{
		printf("func linkStack_Clear() err. -1\n");
		return ;
	}

	//��ջ�е�Ԫ�ض���ջ
	while (linkList_Length(stack) > 0)
	{
		linkStack_Pop(stack);
	}

	//���ջ
	linkList_Clear(stack);
}


//��ȡջ�Ĵ�С
//�൱�ڻ�ȡ����Ĵ�С
int linkStack_Length(LinkStack* stack)
{
	return linkList_Length(stack);
}


//��ջ
//�൱���������ͷ������ڵ㣬β������Ļ���Ҫ�ƶ�����Ԫ�ء�
//��Ҫ��ջҵ��ڵ�ת��Ϊ����ҵ��ڵ㣬����ڵ�Ҫ�ڶ��ϣ�ע����������
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

	sNode->item = item;//��ջ�ڵ�洢������ڵ�

	ret = linkList_Insert(stack, (LinkListNode*)sNode, 0);//���ڵ���뵽����
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


//��ջ
//�൱�ڴ������ͷ��ɾ��Ԫ��
//��Ҫ�ͷſռ�
void* linkStack_Pop(LinkStack* stack)
{
	LinkStackNode* sNode = NULL;
	void* ret = NULL;//ջ��ҵ��ڵ�

	if (stack == NULL)
	{
		printf("func linkStack_Pop() err. -1\n");
		return NULL;
	}

	sNode = (LinkStackNode*)linkList_Delete(stack, 0);//ɾ������ͷ��Ԫ�أ�����ջ�ڵ�Ԫ��
	if (sNode == NULL)
	{
		return NULL;
	}

	ret = sNode->item;//����ҵ��ڵ�

	free(sNode);//�ͷ�ջ�ڵ㿪�ٵĿռ�
	return ret;
}


//��ȡջ��Ԫ��
//�൱�ڻ�ȡ����ͷ��Ԫ��
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
