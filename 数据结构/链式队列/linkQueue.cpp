#include"linkQueue.h"
#include"linkList.h"
#include<stdio.h>
#include<string.h>
#include<malloc.h>

//������ҵ��ڵ��װΪ����ҵ��ڵ�
//����ڵ�
typedef struct _tag_LinkQueueNode
{
	LinkListNode next;
	void* item;//���нڵ�
}LinkQueueNode;

//��������,�൱�ڴ�������
LinkQueue* linkQueue_Create()
{
	return linkList_Create();
}


//���ٶ��С��ͷ�Ԫ�صĿռ䣬��������
void linkQueue_Destroy(LinkQueue* queue)
{
	linkQueue_Clear(queue);
	linkList_Destroy(queue);
	return;
}


//��ն��С��ͷ�Ԫ�صĿռ䣬�������
void linkQueue_Clear(LinkQueue* queue)
{
	while (linkList_Length(queue) > 0)
	{
		linkQueue_Retrive(queue);//��������Ԫ�ض�ȡ��
	}

	linkList_Clear(queue);
	return;
}


//��ȡ���еĳ��ȣ��൱�ڻ�ȡ����ĳ���
int linkQueue_Length(LinkQueue* queue)
{
	return linkList_Length(queue);
}


//���Ԫ��,�൱���������β������Ԫ��
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

	queueNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));//���ٶ��нڵ�ռ�
	if (queueNode == NULL)
	{
		ret = -2;
		printf("func linkQueue_Append() err -2\n");
		return ret;
	}
	memset(queueNode, 0, sizeof(LinkQueueNode));

	queueNode->item = item;//������ҵ��ڵ�Ž�����ҵ��ڵ�

	ret = linkList_Insert(queue, (LinkListNode*)queueNode, linkList_Length(queue));//�����β������ڵ�

	if (ret != 0)//����������Ԫ��ʧ��
	{
		printf("func linkQueue_Append() err %d\n",ret);
		free(queueNode);
		return ret;
	}

	return ret;
}


//�Ӷ�����ȡ��һ��Ԫ�أ��൱�ڴ�����ͷ��ɾ��һ��Ԫ��
void* linkQueue_Retrive(LinkQueue* queue)
{
	LinkQueueNode* queueNode = NULL;
	void* ret = NULL;

	if (queue == NULL )
	{
		printf("func linkQueue_Append() err -1\n");
		return NULL;
	}

	queueNode = (LinkQueueNode*)linkList_Delete(queue, 0);//��������ɾ����Ԫ��

	if (queueNode != NULL)
	{
		ret = queueNode->item;//������нڵ�
		free(queueNode);//�ͷ�����ڵ�ռ�
	}

	return ret;
}


//��ȡ��ͷԪ�أ��൱�ڻ�ȡ����ͷ��Ԫ��
void* linkQueue_Header(LinkQueue* queue)
{
	LinkQueueNode* queueNode = NULL;
	void* ret = NULL;

	if (queue == NULL)
	{
		printf("func linkQueue_Header() err -1\n");
		return NULL;
	}

	queueNode = (LinkQueueNode*)linkList_Get(queue, 0);//�������л�ȡ��Ԫ��

	if (queueNode == NULL)
	{
		printf("func linkQueue_Header() err -2\n");
		return NULL;
	}

	ret = queueNode->item;//������нڵ�

	return ret;

}
