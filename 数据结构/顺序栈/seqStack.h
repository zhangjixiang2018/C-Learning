#pragma once

typedef void SeqStack;

//创建栈
SeqStack* seqStack_Create(int capacity);

//删除栈
void seqStack_Destroy(SeqStack* stack);

//清空栈
void seqStack_Clear(SeqStack* stack);

//获取栈的长度
int seqStack_Length(SeqStack* stack);

//获取栈的容量
int seqStack_Capacity(SeqStack* stack);

//进栈
int seqStack_Push(SeqStack* stack, void* item);

//出栈
void* seqStack_Pop(SeqStack* stack);

//获取栈顶元素
void* seqStack_Top(SeqStack* stack);

