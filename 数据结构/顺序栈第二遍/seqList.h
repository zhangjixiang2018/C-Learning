#pragma once


typedef void SeqList;
typedef void SeqListNode;

//创建线性表
SeqList* SeqList_Create(int capacity);

//删除线性表
void SeqList_Destroy(SeqList* list);

//清空线性表
void SeqList_Clear(SeqList* list);

//获取线性表的长度
int SeqList_Length(SeqList* list);

//获取线性表的容量
int SeqList_Capacity(SeqList* list);

//在线性表list的pos位置插入一个节点node
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

//获取线性表list中pos位置的节点
SeqListNode* SeqList_Get(SeqList* list, int pos);

//删除线性表list中pos位置的节点
SeqListNode* SeqList_Delete(SeqList* list, int pos);