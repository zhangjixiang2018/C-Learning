#pragma once
typedef void SeqQueue;

//创建队列
SeqQueue* seqQueue_Create(int capacity);


//删除队列
void seqQueue_Destory(SeqQueue* queue);


//清空队列
void seqQueue_Clear(SeqQueue* queue);


//获取队列的长度
int seqQueue_Length(SeqQueue* queue);


//获取队列的容量
int seqQueue_Capacity(SeqQueue* queue);


//添加元素
int seqQueue_Append(SeqQueue* queue, void* item);


//删除元素
void* seqQueue_Retrive(SeqQueue* queue);


//获取队头元素
void* seqQueue_Header(SeqQueue* queue);
