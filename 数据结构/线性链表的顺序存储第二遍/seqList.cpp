#include"seqList.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct _tag_SeqList
{
	int listLength;
	int listCapacity;
	unsigned int** node;
}TSeqList;

//1.������������˳������
SeqList* seqList_Create(int capacity)
{
	TSeqList* ret = NULL;

	ret = (TSeqList*)malloc(sizeof(TSeqList));
	if (ret == NULL)
	{
		printf("func seqList_Create() err,Fail in malloc ret memory. -1\n");
		return ret;
	}
	memset(ret, 0, sizeof(TSeqList));


	//����capacity�Ĵ�СΪ�ڵ����ռ�
	ret->node = (unsigned int**)malloc(sizeof(unsigned int*) * capacity);
	if (ret->node == NULL)
	{
		printf("func seqList_Create() err,Fail in malloc node memory. -2\n");
		return ret;
	}

	ret->listCapacity = capacity;
	ret->listLength = 0;
	return ret;
}


//2.ɾ��˳������
void seqList_Destroy(SeqList* list)
{
	TSeqList* tlist = (TSeqList*)list;

	if (tlist == NULL)
	{
		printf("func seqList_Destroy() err.-1\n");
		return;
	}

	if (tlist->node != NULL)
	{
		free(tlist->node);//�󴴽����ͷ�
	}
	free(tlist);
	return ;
}


//3.���˳������
void seqList_Clear(SeqList* list)
{
	TSeqList* tlist = (TSeqList*)list;

	if (tlist == NULL)
	{
		printf("func seqList_Clear() err.-1\n");
		return;
	}

	tlist->listLength = 0;
}


//4.��˳������list��posλ�ò���ڵ�node
//����ֵ������0 ��ʾ����ɹ�
int seqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	TSeqList* tlist = (TSeqList*)list;

	if (tlist == NULL || node == NULL || pos<0)
	{
		printf("func seqList_Insert() err.-1\n");
		return -1;
	}
	
	//���������޷�����
	if (tlist->listCapacity <= tlist->listLength)
	{
		printf("func seqList_Insert() err.-2\n");
		return -2;
	}
	//�ݴ��������λ�ñ�����ĳ��ȴ�ʱ���ýڵ�鵽�����β��
	if (tlist->listLength < pos)
	{
		pos = tlist->listLength;
	}

	for (int i = tlist->listLength; i > pos; i--)
	{
		tlist->node[i] = tlist->node[i - 1];
	}

	tlist->node[pos] = (unsigned int*)node;
	tlist->listLength++;

	return 0;
}


//5.��ȡ˳������list�ĳ���
int seqList_Length(SeqList* list)
{
	TSeqList* tlist = (TSeqList*)list;

	if (tlist == NULL)
	{
		printf("func seqList_Length() err.-1\n");
		return -1;
	}

	return tlist->listLength;

}


//6.��ȡ˳������list������
int seqList_Capacity(SeqList* list)
{
	TSeqList* tlist = (TSeqList*)list;

	if (tlist == NULL)
	{
		printf("func seqList_Capacity() err.-1\n");
		return -1;
	}

	return tlist->listCapacity;

}

//7.ɾ��˳������List��posλ�õĽڵ�
SeqListNode* seqList_Delete(SeqList* list, int pos)
{
	TSeqList* tlist = (TSeqList*)list;
	SeqListNode* ret;

	if (tlist == NULL || pos<0)
	{
		printf("func seqList_Delete() err.-1\n");
		return NULL;
	}

	//�ݴ���ɾ����λ�ñ�����ĳ��ȴ�ʱ
	if (tlist->listLength < pos)
	{
		printf("func seqList_Delete() err.-2\n");
		return NULL;
	}

	ret = tlist->node[pos];//����ɾ���Ľڵ�

	//�ڵ�ǰ�ƣ��ɾ���Ľڵ�
	for (int i = pos; i < tlist->listLength; i++)
	{
		tlist->node[i] = tlist->node[i + 1];
	}

	tlist->listLength--;

	return ret;

}


//8..��ȡ˳������list��posλ�õĽڵ�
SeqListNode* seqList_Get(SeqList* list, int pos)
{
	TSeqList* tlist = (TSeqList*)list;

	if (tlist == NULL || pos < 0)
	{
		printf("func seqList_Get() err.-1\n");
		return NULL;
	}

	return tlist->node[pos];
}