#include"seqList.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int** node; //int* node[]  指针数组
}TSeqList;

//创建线性表
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
	memset(tmp, 0, sizeof(TSeqList));//初始化分配的内存空间

	//根据capacity的大小分配节点空间
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


//删除线性表
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
	if (tmp->node != NULL)//先释放后申请的空间
	{
		free(tmp->node);
	}
	free(tmp);

}


//清空线性表
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


//获取线性表的长度
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


//获取线性表的容量
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


//在线性表list的pos位置插入一个节点node
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

	//链表已满
	if (tmp->length >= tmp->capacity)
	{
		ret = -2;
		printf("func SeqList_Insert(),tmp->length >= tmp->capacity err: %d\n", ret);
		return ret;
	}

	//容错修正  6个长度 容量20;用户pos10位置插入..
	if (pos >= tmp->length)
	{
		pos = tmp->length; //
	}

	//将元素后移
	for (i = tmp->length; i > pos; i--)
	{
		tmp->node[i] = tmp->node[i-1];
	}

	//插入元素
	tmp->node[pos] = (unsigned int*)node;//
	tmp->length++;

	return 0;
}


//获取线性表list中pos位置的节点
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


//删除线性表list中pos位置的节点
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