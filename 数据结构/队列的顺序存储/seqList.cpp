#include"seqList.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int** node; //int* node[]  ָ������
}TSeqList;

//�������Ա�
SeqList* SeqList_Create(int capacity)
{
	int ret = 0;
	TSeqList* tmp = NULL;

	tmp = (TSeqList*)malloc(sizeof(TSeqList));
	if (tmp == NULL)
	{
		ret = -1;
		printf("func SeqList_Create() err:%d \n ", ret);
		return NULL;
	}
	memset(tmp, 0, sizeof(TSeqList));//��ʼ��������ڴ�ռ�

	//����capacity�Ĵ�С����ڵ�ռ�
	tmp->node = (unsigned int**)malloc(sizeof(unsigned int*) * capacity);
	if (tmp->node == NULL)
	{
		ret = -2;
		printf("func SeqList_Create() err:%d \n ", ret);
		return NULL;
	}

	tmp->capacity = capacity;
	tmp->length = 0;
	return tmp;
}


//ɾ�����Ա�
void SeqList_Destroy(SeqList* list)
{
	int ret = 0;
	TSeqList* tmp = NULL;

	if (list == NULL)
	{
		ret = -1;
		printf("func SeqList_Destroy() err: %d\n", ret);
		return;
	}

	tmp = (TSeqList*)list;
	if (tmp->node != NULL)//���ͷź�����Ŀռ�
	{
		free(tmp->node);
	}
	free(tmp);

}


//������Ա�
void SeqList_Clear(SeqList* list)
{
	int ret = 0;
	TSeqList* tmp = NULL;

	if (list == NULL)
	{
		ret = -1;
		printf("func SeqList_Clear() err: %d\n", ret);
		return;
	}

	tmp = (TSeqList*)list;
	
	tmp->length = 0;
}


//��ȡ���Ա�ĳ���
int SeqList_Length(SeqList* list)
{
	int ret = 0;
	TSeqList* tmp = NULL;

	if (list == NULL)
	{
		ret = -1;
		printf("func SeqList_Length() err: %d\n", ret);
		return ret;
	}

	tmp = (TSeqList*)list;

	return tmp->length;
}


//��ȡ���Ա������
int SeqList_Capacity(SeqList* list)
{
	int ret = 0;
	TSeqList* tmp = NULL;

	if (list == NULL)
	{
		ret = -1;
		printf("func SeqList_Capacity() err: %d\n", ret);
		return ret;
	}

	tmp = (TSeqList*)list;

	return tmp->capacity;
}


//�����Ա�list��posλ�ò���һ���ڵ�node
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos) 
{
	int ret = 0;
	int i = 0;
	TSeqList* tmp = NULL;

	if (list == NULL || node==NULL || pos<0)
	{
		ret = -1;
		printf("func SeqList_Insert() err: %d\n", ret);
		return ret;
	}
	tmp = (TSeqList*)list;

	//��������
	if (tmp->length >= tmp->capacity)
	{
		ret = -2;
		printf("func SeqList_Insert(),tmp->length >= tmp->capacity err: %d\n", ret);
		return ret;
	}

	//�ݴ�����  6������ ����20;�û�pos10λ�ò���..
	if (pos >= tmp->length)
	{
		pos = tmp->length; //
	}

	//��Ԫ�غ���
	for (i = tmp->length; i > pos; i--)
	{
		tmp->node[i] = tmp->node[i-1];
	}

	//����Ԫ��
	tmp->node[pos] = (unsigned int*)node;//
	tmp->length++;

	return 0;
}


//��ȡ���Ա�list��posλ�õĽڵ�
SeqListNode* SeqList_Get(SeqList* list, int pos) 
{
	int ret = 0;
	TSeqList* tmp = NULL;

	if (list == NULL || pos<0)
	{
		ret = -1;
		printf("func SeqList_Capacity() err: %d\n", ret);
		return NULL;
	}

	
	tmp = (TSeqList*)list;

	if (pos >= tmp->length)
	{
		ret = -2;
		printf("func SeqListGet() err: %d\n", ret);
		return NULL;
	}


	return (void *)tmp->node[pos];
}


//ɾ�����Ա�list��posλ�õĽڵ�
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	int ret = 0;
	int i = 0;
	TSeqList* tmp = NULL;
	SeqListNode* node=NULL;

	if (list == NULL || pos < 0)
	{
		ret = -1;
		printf("func SeqList_Delete() err: %d\n", ret);
		return NULL;
	}
	tmp = (TSeqList*)list;

	if (pos >= tmp->length)
	{
		ret = -2;
		printf("func SeqListDelete() err: %d\n", ret);
		return NULL;
	}

	node = (void*)tmp->node[pos];

	for (i = pos; i < tmp->length; i++)
	{
		tmp->node[i] = tmp->node[i + 1];
	}
	tmp->length--;

	return node;
}