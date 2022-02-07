#pragma once
#include<stdio.h>
#include<string.h>
#include<malloc.h>


typedef void DlinkList;
typedef struct DlinkListNode
{
	struct DlinkListNode* next;
	struct DlinkListNode* pre;

}DlinkListNode;

//1.创建双向链表
DlinkList* dLinkList_Create();

//2.删除双向链表
void dLinkList_Destroy(DlinkList* list);

//3.清空双向链表
void dLinkList_Clear(DlinkList* list);


//4.获取双向链表的长度
int dLinkList_Length(DlinkList* list);


//5.向双向链表List的pos位置插入节点node
int dLinkList_Insert(DlinkList* list, DlinkListNode* node, int pos);

//6.删除双向链表list的pos位置的节点
DlinkListNode* dLinkList_Delete(DlinkList* list, int pos);

//7.获取双向链表list的pos位置的节点
DlinkListNode* dLinkList_Get(DlinkList* list, int pos);


//8.删除双向链表list中的node节点
DlinkListNode* dLinkList_DeleteNode(DlinkList* list, DlinkListNode* node);


//9.重置游标指针，并返回重置后的节点
DlinkListNode* dLinkList_Reset(DlinkList* list);

//10.获取游标指针当前指向的节点
DlinkListNode* dLinkList_Current(DlinkList* list);


//11.将游标指针后移一个，并返回移动前指向的节点
DlinkListNode* dLinkList_Next(DlinkList* list);


//12.将游标指针前移一个，并返回移动前指向的节点
DlinkListNode* dLinkList_Pre(DlinkList* list);
