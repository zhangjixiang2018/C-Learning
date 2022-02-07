#pragma once

typedef void LinkList;

/*
该结构体的作用是什么？
该结构体是链表节点（包括头节点和普通节点）的第一个域，在节点中包含该结构体，
就可将所有的节点连起来。不懂的时候想想那张图
*/
typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode* next;
}LinkListNode;

//创建链式线性表
LinkList* linkList_Create();

//删除链式线性表
void linkList_Destroy(LinkList* list);

//清空链式线性表
void linkList_Clear(LinkList* list);

//获取链式线性表的长度
int linkList_Length(LinkList* list);


//在链式线性表list的pos位置插入节点Node
int linkList_Insert(LinkList* list, LinkListNode* node, int pos);

//获取链式线性表list的pos位置的节点
LinkListNode* linkList_Get(LinkList* list, int pos);

//删除链式线性表list的pos位置的节点
LinkListNode* linkList_Delete(LinkList* list, int pos);
