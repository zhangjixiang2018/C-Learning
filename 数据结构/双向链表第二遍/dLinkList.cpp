#include"dLinkList.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode* slider;
	int length;
}TDLinkList;

//创建链表
DLinkList* dLinkList_Create()
{
	TDLinkList* ret = NULL;

	ret = (TDLinkList*)malloc(sizeof(TDLinkList));

	if (ret == NULL)
	{
		printf("func dLinkList_Create() err,-1\n");
		return NULL;
	}

	memset(ret, 0, sizeof(TDLinkList));

	return ret;
}


//
void dLinkList_Destroy(DLinkList* list)
{

	TDLinkList* tlist = NULL;

	tlist = (TDLinkList*)list;

	if (tlist == NULL)
	{
		printf("func dLinkList_Destroy() err,-1\n");
		return;
	}

	free(tlist);
}


//清空链表
void dLinkList_Clear(DLinkList* list)
{
	TDLinkList* tlist = NULL;

	tlist = (TDLinkList*)list;

	if (tlist == NULL)
	{
		printf("func dLinkList_Clear() err,-1\n");
		return;
	}

	tlist->header.next = NULL;
	tlist->slider = NULL;
	tlist->length = 0;
}


//获取链表的长度
int dLinkList_Length(DLinkList* list)
{
	TDLinkList* tlist = NULL;

	tlist = (TDLinkList*)list;

	if (tlist == NULL)
	{
		printf("func dLinkList_Clear() err,-1\n");
		return -1;
	}

	return tlist->length;
}

//向链表list的POS位置插入节点Node
int dLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* current = NULL;
	DLinkListNode* next = NULL;


	if (tlist == NULL || node == NULL || pos < 0)
	{

		printf("func dLinkList_Insert() err.-1\n");
		return -1;

	}

	//容错，当插入的位置大于链表的长度时，在链表尾端插入
	if (pos > tlist->length)
	{
		pos = tlist->length;
	}

	current = &(tlist->header);//current指正指向头结点

	for (int i = 0; i < pos; i++)
	{
		current = current->next;//current指针指向要插入节点的前一个节点
	}

	next = current->next;//next指针指向要插入位置的下一个位置

	node->next = next;
	current->next = node;

	if (next != NULL)
	{
		next->pre = node;
	}

	node->pre = current;

	if (current == &(tlist->header))//如果是在头部插入
	{
		node->pre = NULL;
	}

	//第一次插入，将游标指向插入的节点
	if (tlist->length == 0)
	{
		tlist->slider = node;
	}

	tlist->length++;
	return 0;
}


//删除链表list中pos位置的节点
DLinkListNode* dLinkList_Delete(DLinkList* list, int pos)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* current = NULL;
	DLinkListNode* next = NULL;
	DLinkListNode* ret = NULL;

	if (tlist == NULL || pos < 0)
	{
		printf("func dLinkList_Delete() err.-1\n");
		return NULL;
	}

	//容错，当删除的位置大于链表的长度时，
	if (pos >= tlist->length)
	{
		printf("func dLinkList_Delete() err.-2\n");
		return NULL;
	}

	current = &(tlist->header);//current指正指向头结点

	for (int i = 0; i < pos; i++)
	{
		current = current->next;//current指针指向要删除节点的前一个节点
	}

	ret = current->next;
	next = ret->next;

	current->next = next;//让被删除节点的前一个节点连接被删除节点的后一个节点

	if (next != NULL)
	{
		next->pre = ret->pre;
	}

	//如果删除的是游标指向的节点,将游标后移
	if (tlist->slider == ret)
	{
		tlist->slider = tlist->slider->next;
	}

	//
	tlist->length--;


	return ret;
}


//获取链表list中poe位置的节点
DLinkListNode* dLinkList_Get(DLinkList* list, int pos)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* current = NULL;
	DLinkListNode* ret = NULL;

	if (tlist == NULL || pos < 0)
	{
		printf("func dLinkList_Get() err.-1\n");
		return NULL;
	}

	//容错，当删除的位置大于链表的长度时，
	if (pos >= tlist->length)
	{
		printf("func ddLinkList_Get err.-2\n");
		return NULL;
	}

	current = &(tlist->header);//current指正指向头结点

	for (int i = 0; i < pos; i++)
	{
		current = current->next;//current指针指向要删除节点的前一个节点
	}

	ret = current->next;

	return ret;
}


//置位游标指针，并返回置位之后的节点
DLinkListNode* dLinkList_Reset(DLinkList* list)
{
	TDLinkList* tlist = (TDLinkList*)list;

	if (tlist == NULL)
	{
		printf("func dLinkList_Reset() err.-1\n");
		return NULL;
	}

	tlist->slider = tlist->header.next;

	return tlist->slider;
}


//删除链表list中的node节点
DLinkListNode* dLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* current = NULL;
	DLinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL || node==NULL)
	{
		printf("func dLinkList_Reset() err.-1\n");
		return NULL;
	}

	current = &(tlist->header);

	//在list中找到node节点，通过位置删除节点
	for (i = 0; i < tlist->length; i++)
	{
		current = current->next;
		if (current == node)
		{
			break;
		}
	}
	ret = dLinkList_Delete(list, i);

	return ret;
}


//获取游标指针当前指向位置的的节点
DLinkListNode* dLinkList_Current(DLinkList* list)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL)
	{
		printf("func dLinkList_Reset() err.-1\n");
		return NULL;
	}

	
	ret = tlist->slider;
	
	return ret;
}


//将游标指针后移，并返回移动前的节点
DLinkListNode* dLinkList_Next(DLinkList* list)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL)
	{
		printf("func dLinkList_Reset() err.-1\n");
		return NULL;
	}

	ret = tlist->slider;

	tlist->slider = ret->next;

	return ret;

}


//将游标指针前移，并返回移动前的节点
DLinkListNode* dLinkList_Pre(DLinkList* list)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL)
	{
		printf("func dLinkList_Reset() err.-1\n");
		return NULL;
	}

	ret = tlist->slider;

	tlist->slider = ret->pre;

	return ret;
}