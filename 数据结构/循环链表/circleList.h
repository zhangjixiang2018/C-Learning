#pragma once

typedef void CircleList;

/*
该结构体的作用是什么？
该结构体是链表节点（包括头节点和普通节点）的第一个域，在节点中包含该结构体，
就可将所有的节点连起来。不懂的时候想想那张图
*/
typedef struct _tag_CircleListNode
{
	struct _tag_CircleListNode* next;
}TCircleListNode;

//创建循环链表
CircleList* circleList_Create();

//删除循环链表
void circleList_Destroy(CircleList* list);

//清空循环链表
void circleList_Clear(CircleList* list);


//获取循环链表的长度
int circleList_Length(CircleList* list);


//向循环链表list的pos位置插入节点node
int circleList_Insert(CircleList* list, TCircleListNode* node, int pos);


//获取循环链表lsit中pos位置的节点
TCircleListNode* circleList_Get(CircleList* list, int pos);


//删除循环链表List中pos位置的节点
TCircleListNode* circleList_Delete(CircleList* list, int pos);


//删除循环链表list中的节点Node
TCircleListNode* circleList_DeleteNode(CircleList* list, TCircleListNode* node);


//置位偏移指针
TCircleListNode* circleList_Reset(CircleList* list);


//获取循环链表list当前位置的节点
TCircleListNode* circleList_Current(CircleList* list);


//将偏移指针指向下一个节点，返回当前节点
TCircleListNode* circleList_Next(CircleList* list);



