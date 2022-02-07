#pragma once
typedef void CircleLinkList;
typedef struct CircleLinkListNode
{
	CircleLinkListNode* next;
}CircleLinkListNode;

//创建链表
CircleLinkList* circleLinkList_Create();


//删除链表
void circleLinkList_Destroy(CircleLinkList* list);


//清空链表
void circleLinkList_Clear(CircleLinkList* list);

//获取链表的长度
int circleLinkList_Length(CircleLinkList* list);


//向链表list中的pos位置插入节点node
int circleLinkList_Insert(CircleLinkList* list, CircleLinkListNode* node, int pos);


//删除list中pos位置的节点，并返回该节点
CircleLinkListNode* circleLinkList_Delete(CircleLinkList* list, int pos);


//获取list中pos位置的节点
CircleLinkListNode* circleLinkList_Get(CircleLinkList* list, int pos);


//删除List中node节点，并返回删除的节点
CircleLinkListNode* circleLinkList_DeleteNode(CircleLinkList* list, CircleLinkListNode* node);


//复位游标指针，并返回复位后的位置
CircleLinkListNode* circleLinkList_Reset(CircleLinkList* list);


//返回游标指针当前指向的节点
CircleLinkListNode* circleLinkList_Current(CircleLinkList* list);


//将游标指正向后移动一个位置，并返回移动后的位置
CircleLinkListNode* circleLinkList_Next(CircleLinkList* list);


