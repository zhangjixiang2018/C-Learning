#pragma once

typedef void CircleList;

typedef struct CircleListNode
{
	struct CircleListNode* next;
}CircleListNode;

//1.创建循环链表
CircleList* circleList_Create();

//2.删除循环链表
void circleList_Destroy(CircleList* list);

//3.清空循环链表
void circleList_Clear(CircleList* list);


//4.获取循环链表的长度
int circleList_Length(CircleList* list);


//5.在循环链表list中的pos位置插入节点node
int circleList_Insert(CircleList* list, CircleListNode* node, int pos);


//6.获取循环链表list中的pos位置的节点
CircleListNode* circleList_Get(CircleList* list, int pos);


//7.删除循环链表list中的pos位置的节点，并返回该节点
CircleListNode* circleList_Delete(CircleList* list, int pos);


//8.删除循环链表list中的node节点，并返回该节点，游标指针指向下一个节点
CircleListNode* circleList_DeleteNode(CircleList* list, CircleListNode* node);


//9.获取循环链表list当前位置的节点
CircleListNode* circleList_Current(CircleList* list);


//10.将游标指针后移，并返回移动前的节点
CircleListNode* circleList_Next(CircleList* list);


//11.重置游标指针,并返回重置游标指针后游标指针指向的节点
CircleListNode* circleList_Reset(CircleList* list);
