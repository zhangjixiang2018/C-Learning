#include"seqQueue.h"
#include"seqList.h"
#include<stdio.h>

//创建队列，相当于创建顺序线性表
SeqQueue* seqQueue_Create(int capacity)
{
	return SeqList_Create(capacity);
}


//删除队列,相当于删除顺序线性表
void seqQueue_Destory(SeqQueue* queue)
{

	SeqList_Destroy(queue);
}


//清空队列,相当于清空顺序线性表
void seqQueue_Clear(SeqQueue* queue)
{

	SeqList_Clear(queue);
}


//获取队列的长度,相当于获取顺序线性表的长度
int seqQueue_Length(SeqQueue* queue)
{

	return SeqList_Length(queue);
}


//获取队列的容量,相当于获取顺序线性表的容量
int seqQueue_Capacity(SeqQueue* queue)
{
	return SeqList_Capacity(queue);
}


//添加元素,相当于在顺序线性表的尾部插入元素
int seqQueue_Append(SeqQueue* queue, void* item)
{
	int ret = 0;
	ret = SeqList_Insert(queue, (SeqListNode*)item, SeqList_Length(queue));
	return ret;

}


//删除元素,相当于在顺序线性表的头部删除元素
void* seqQueue_Retrive(SeqQueue* queue)
{

	return SeqList_Delete(queue, 0);
}


//获取队头元素
void* seqQueue_Header(SeqQueue* queue)
{

	return SeqList_Get(queue, 0);

}