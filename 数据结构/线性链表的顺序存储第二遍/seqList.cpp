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

//1.根据容量创建顺序链表
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


	//根据capacity的大小为节点分配空间
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


//2.删除顺序链表
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
		free(tlist->node);//后创建先释放
	}
	free(tlist);
	return ;
}


//3.清空顺序链表
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


//4.向顺序链表list的pos位置插入节点node
//返回值：返回0 表示插入成功
int seqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	TSeqList* tlist = (TSeqList*)list;

	if (tlist == NULL || node == NULL || pos<0)
	{
		printf("func seqList_Insert() err.-1\n");
		return -1;
	}
	
	//链表已满无法插入
	if (tlist->listCapacity <= tlist->listLength)
	{
		printf("func seqList_Insert() err.-2\n");
		return -2;
	}
	//容错，当插入的位置比链表的长度大时，让节点查到链表的尾部
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


//5.获取顺序链表list的长度
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


//6.获取顺序链表list的容量
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

//7.删除顺序链表List中pos位置的节点
SeqListNode* seqList_Delete(SeqList* list, int pos)
{
	TSeqList* tlist = (TSeqList*)list;
	SeqListNode* ret;

	if (tlist == NULL || pos<0)
	{
		printf("func seqList_Delete() err.-1\n");
		return NULL;
	}

	//容错，当删除的位置比链表的长度大时
	if (tlist->listLength < pos)
	{
		printf("func seqList_Delete() err.-2\n");
		return NULL;
	}

	ret = tlist->node[pos];//缓存删除的节点

	//节点前移，填补删除的节点
	for (int i = pos; i < tlist->listLength; i++)
	{
		tlist->node[i] = tlist->node[i + 1];
	}

	tlist->listLength--;

	return ret;

}


//8..获取顺序链表list中pos位置的节点
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