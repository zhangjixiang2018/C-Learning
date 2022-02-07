#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include"linkList.h"


typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

//创建链式线性表
LinkList* linkList_Create()
{
	TLinkList* ret = NULL;

	ret = (TLinkList*)malloc(sizeof(TLinkList));
	memset(ret, 0, sizeof(TLinkList));
	ret->header.next = NULL;
	ret->length = 0;

	return ret;
}


//删除链式线性表
void linkList_Destroy(LinkList* list)
{
	TLinkList* tList = NULL;
	if (list == NULL)
	{
		return;
	}
	free(list);

	return ;

}


//清空链式线性表
void linkList_Clear(LinkList* list)
{
	TLinkList* tList = NULL;
	if (list == NULL)
	{
		return;
	}
	tList = (TLinkList*)list;

	tList->length = 0;
	tList->header.next = NULL;
	return;
}


//获取链式线性表的长度
int linkList_Length(LinkList* list)
{
	TLinkList* tList = NULL;
	int ret = 0;
	if (list == NULL)
	{
		ret = -1;
		printf("func linkList_Length() err : %d\n", ret);
		return ret;
	}
	tList = (TLinkList*)list;

	return tList->length;

}


//在链式线性表list的pos位置插入节点Node
int linkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	TLinkList* tList = NULL;
	LinkListNode* current = NULL;
	int ret = 0;
	int i = 0;

	if (list == NULL || node == NULL || pos<0)
	{
		ret = -1;
		printf("func linkList_Insert err : %d\n", ret);
		return ret;
	}
	tList = (TLinkList*)list;

	current = &(tList->header);//让辅助指针变量指向链表的头部

	//使current指向要插位置的前一个节点
	//current->next != NULL 防止插入的位置比链表长度大
	for (i = 0; i < pos && current->next != NULL; i++)
	{
		current = current->next;
	}

	node->next = current->next;//让node连接后续链表
	current->next = node;//让前面的链表连接新的node节点

	tList->length++;

	return 0;

}


//获取链式线性表list的pos位置的节点
LinkListNode* linkList_Get(LinkList* list, int pos)
{
	TLinkList* tList = NULL;
	LinkListNode* current = NULL;
	int i = 0;

	if (list == NULL || pos < 0)
	{
		current = NULL;
		printf("func linkList_Get err : %d\n", -1);
		return NULL;
	}

	tList = (TLinkList*)list;
	current = &(tList->header);//让辅助指针变量指向链表的头部

	//获取的位置比链表长度大，
	if (pos > tList->length)
	{
		printf("func linkList_Get() err : %d\n", -2);
		return NULL;
	}

	//使current指向要插位置的前一个节点
	for (i = 0; i < pos; i++)
	{
		current = current->next;
	}


	return current->next;

}

//删除链式线性表list的pos位置的节点
LinkListNode* linkList_Delete(LinkList* list, int pos)
{
	TLinkList* tList = NULL;
	LinkListNode* current = NULL;
	LinkListNode* ret = NULL;
	int i = 0;

	if (list == NULL || pos < 0)
	{
		printf("func linkList_Length() err : %d\n",-1);
		return NULL;
	}
	tList = (TLinkList*)list;

	current = &(tList->header);//让辅助指针变量指向链表的头部

	//删除的位置比链表长度大，
	if (pos >= tList->length)
	{
		printf("func linkList_Delete() err : %d\n", -2);
		return NULL;
	}

	//使current指向要插位置的前一个节点
	for (i = 0; i < pos; i++)
	{
		current = current->next;
	}

	ret = current->next;//保存被删除的节点
	current->next = ret->next;//让前面的链表连接新的node节点

	tList->length--;

	return ret;

}
