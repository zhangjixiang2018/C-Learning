#include"linkStack.h"
#include"linkList.h"
#include<stdio.h>
#include<malloc.h>

//��ջ�ڵ�ת��Ϊ����ڵ�
typedef struct _tag_LinkStackNode
{
	LinkListNode next;
	void* item;//ջ�ڵ�
}TLinkStackNode;

//����ջ
LinkStack* linkStack_Create()
{
	return linkList_Create();
}


//ɾ��ջ
void linkStack_Destroy(LinkStack* stack)
{
	linkStack_Clear(stack);
	linkList_Destroy(stack);
}


//���ջ���൱������������⻹��Ҫջ��Ԫ�صĿռ䶼�ͷŵ�
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
		linkStack_Pop(stack);//��ջ�е�Ԫ�ض���ջ�����ͷ�ջ��Ԫ�صĿռ�
	}

	//�������
	linkList_Clear(stack);
}

//��ȡջ��С
int linkStack_Length(LinkStack* stack)
{
	if (stack == NULL)
	{
		printf("func linkStack_Push() err.-1\n");
		return -1;
	}

	return linkList_Length(stack);
}

//��ջ,�൱���������ͷ������Ԫ��
int linkStack_Push(LinkStack* stack, void* item)
{
	TLinkStackNode* stackNode = NULL;
	int ret = 0;

	if (stack == NULL || item==NULL )
	{
		printf("func linkStack_Push() err.-1\n");
		return -1;
	}

	//��ջ�ڵ�ת��Ϊ����ڵ�
	stackNode = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
	if (stackNode == NULL)
	{
		printf("func linkStack_Push() err.-2\n");
		return -2;
	}
	stackNode->item = item;//��ҵ��ڵ��������ڵ�

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


//��ջ
//�൱��������ͷ��ɾ��Ԫ�أ�����Ҫ�ͷ�ɾ����Ԫ�صĿռ�
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

	ret = stackNode->item;//����ջ�ڵ�

	free(stackNode);//�ͷ�����ڵ�Ŀռ�

	return ret;

}


//��ȡջ��Ԫ�أ��൱�ڻ�ȡ����ĵ�һ���ڵ�
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

	ret = stackNode->item;//����ջ�ڵ�

	return ret;
}
