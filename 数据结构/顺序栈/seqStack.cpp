#include"seqStack.h"
#include<stdio.h>
#include"seqList.h"

//创建栈,相当于创建顺序线性表
SeqStack* seqStack_Create(int capacity)
{

	return SeqList_Create(capacity);
}

//删除栈，相当于删除建顺序线性表
void seqStack_Destroy(SeqStack* stack)
{
	SeqList_Destroy(stack);
	return ;
}

//清空栈，相当于清空建顺序线性表
void seqStack_Clear(SeqStack* stack)
{
	SeqList_Clear(stack);
	return ;

}

//获取栈的长度，相当于获取顺序线性表的长度
int seqStack_Length(SeqStack* stack)
{
	
	return SeqList_Length(stack);

}

//获取栈的容量，相当于获取顺序线性表的容量
int seqStack_Capacity(SeqStack* stack)
{
	return SeqList_Capacity(stack);

}

//进栈，相当于在顺序线性表的尾部插入元素
int seqStack_Push(SeqStack* stack, void* item)
{
	
	return SeqList_Insert(stack, item, SeqList_Length(stack));

}

//出栈，相当于在顺序线性表的尾部删除元素
void* seqStack_Pop(SeqStack* stack)
{
	
	return SeqList_Delete(stack, SeqList_Length(stack) - 1);

}

//获取栈顶元素，获取顺序线性表的尾部元素
void* seqStack_Top(SeqStack* stack)
{
	return SeqList_Get(stack, SeqList_Length(stack) - 1);

}