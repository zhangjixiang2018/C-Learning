#include"linkList.h"
#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

//创建链式线性表
LinkList* linkList_Create()
{
	TLinkList* ret;

	ret = (TLinkList*)malloc(sizeof(TLinkList));
	if (ret == NULL)
	{
		printf("func linkList_Create() err -1\n");
		return ret;
	}
	memset(ret, 0, sizeof(TLinkList));


	return ret;
}

//删除链式线性表
void linkList_Destroy(LinkList* list)
{
	TLinkList* tlist;
	if (list == NULL)
	{
		printf("func linkList_Destroy() err -1\n");
		return ;
	}
	tlist = (TLinkList*)list;
	free(tlist);
	return;
}

//清空链式线性表
void linkList_Clear(LinkList* list)
{
	TLinkList* tlist = (TLinkList*)list;
	if (tlist == NULL)
	{
		printf("func linkList_Clear() err -1\n");
		return;
	}
	
	tlist->length = 0;
	tlist->header.next = NULL;

	return;

}

//在链式线性表list的pos位置插入节点node
//返回值：返回0插入成功
int linkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	TLinkList* tlist = (TLinkList*)list;
	LinkListNode* current = NULL;
	if (tlist == NULL || node == NULL ||pos<0)
	{
		printf("func linkList_Insert() err -1\n");
		return -1;
	}

	//容错1，如果插入的位置比链表的长度大，将插入的位置设为链表的长度
	if (pos > tlist->length)
	{
		pos = tlist->length;
	}

	current = &(tlist->header);

	//将临时指针指向要插入节点的前一个节点
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	//将节点插入链表
	node->next = current->next;
	current->next = node;

	tlist->length++;
	return 0;

}

//获取链式线性表的长度
int linkList_Length(LinkList* list)
{
	TLinkList* tlist = (TLinkList*)list;
	if (tlist == NULL )
	{
		printf("func linkList_Length() err -1\n");
		return -1;
	}

	return tlist->length;

}

//获取链式线性表list的pos位置的元素
LinkListNode* linkList_Get(LinkList* list, int pos)
{
	TLinkList* tlist = (TLinkList*)list;
	LinkListNode* ret = NULL;
	if (tlist == NULL || pos < 0)
	{
		printf("func linkList_Get() err -1\n");
		return NULL;
	}

	//容错，如果插入的位置比链表的长度大，将插入的位置设为链表的长度
	if (pos > tlist->length)
	{
		printf("func linkList_Get() err -2\n");
		return NULL;
	}

	ret = &(tlist->header);

	//将临时指针指向要获取节点的前一个节点
	for (int i = 0; i < pos; i++)
	{
		ret = ret->next;
	}

	return ret->next;

}

//删除链式线性表list的pos位置的元素
LinkListNode* linkList_Delete(LinkList* list, int pos)
{
	TLinkList* tlist = (TLinkList*)list;
	LinkListNode* ret = NULL;
	LinkListNode* current = NULL;

	if (tlist == NULL || pos < 0)
	{
		printf("func linkList_Delete() err -1\n");
		return NULL;
	}

	//容错1，如果删除的位置比链表的长度大
	if (pos > tlist->length)
	{
		printf("func linkList_Delete() err -2\n");
		return NULL;
	}

	current = &(tlist->header);

	//将临时指针指向要删除节点的前一个节点
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	ret = current->next;//缓存要删除的节点
	current->next = ret->next;//删除节点，不懂就画图
	tlist->length--;

	return ret;

}