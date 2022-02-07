#pragma once

typedef void SeqList;
typedef void SeqListNode;

//1.根据容量创建顺序链表
SeqList* seqList_Create(int capacity);


//2.删除顺序链表
void seqList_Destroy(SeqList* list);


//3.清空顺序链表
void seqList_Clear(SeqList* list);


//4.向顺序链表list的pos位置插入节点node
int seqList_Insert(SeqList* list, SeqListNode* node, int pos);


//5.获取顺序链表list的长度
int seqList_Length(SeqList* list);


//6.获取顺序链表list的容量
int seqList_Capacity(SeqList* list);

//7..删除顺序链表List中pos位置的节点
SeqListNode* seqList_Delete(SeqList* list, int pos);


//8..获取顺序链表list中pos位置的节点
SeqListNode* seqList_Get(SeqList* list, int pos);

