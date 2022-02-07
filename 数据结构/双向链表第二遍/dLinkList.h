#pragma once

typedef void DLinkList;

typedef struct DLinkListNode
{
	struct DLinkListNode* next;
	struct DLinkListNode* pre;
}DLinkListNode;


//创建链表
DLinkList* dLinkList_Create();


//
void dLinkList_Destroy(DLinkList* list);

//清空链表
void dLinkList_Clear(DLinkList* list);

//获取链表的长度
int dLinkList_Length(DLinkList* list);

//
int dLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos);


//删除链表list中pos位置的节点
DLinkListNode* dLinkList_Delete(DLinkList* list, int pos);


//获取链表list中poe位置的节点
DLinkListNode* dLinkList_Get(DLinkList* list, int pos);


//置位游标指针，并返回置位之后的节点
DLinkListNode* dLinkList_Reset(DLinkList* list);


//删除链表list中的node节点
DLinkListNode* dLinkList_DeleteNode(DLinkList* list, DLinkListNode* node);


//获取游标指针当前指向位置的的节点
DLinkListNode* dLinkList_Current(DLinkList* list);


//将游标指针后移，并返回移动前的节点
DLinkListNode* dLinkList_Next(DLinkList* list);


//将游标指针前移，并返回移动前的节点
DLinkListNode* dLinkList_Pre(DLinkList* list);
