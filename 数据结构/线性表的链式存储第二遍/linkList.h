#pragma once
typedef void LinkList;
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

//在链式线性表list的pos位置插入节点node
//返回值：返回0插入成功
int linkList_Insert(LinkList* list, LinkListNode* node, int pos);

//获取链式线性表的长度
int linkList_Length(LinkList* list);

//获取链式线性表list的pos位置的元素
LinkListNode* linkList_Get(LinkList* list, int pos);

//删除链式线性表list的pos位置的元素
LinkListNode* linkList_Delete(LinkList* list, int pos);


//


//

