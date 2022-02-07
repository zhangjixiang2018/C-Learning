#pragma once

typedef void LinkQueue;


//创建队列
LinkQueue* linkQueue_Create();


//销毁队列
void linkQueue_Destroy(LinkQueue* queue);


//清空队列
void linkQueue_Clear(LinkQueue* queue);


//获取队列的长度
int linkQueue_Length(LinkQueue* queue);


//向队列中添加一个元素
int linkqueue_Insert(LinkQueue* queue, void* item);


//出队列
void* linkQueue_Retrive(LinkQueue* queue);


//获取队头元素
void* linkQueue_Header(LinkQueue* queue);

