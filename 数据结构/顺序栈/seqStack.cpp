#include"seqStack.h"
#include<stdio.h>
#include"seqList.h"

//����ջ,�൱�ڴ���˳�����Ա�
SeqStack* seqStack_Create(int capacity)
{

	return SeqList_Create(capacity);
}

//ɾ��ջ���൱��ɾ����˳�����Ա�
void seqStack_Destroy(SeqStack* stack)
{
	SeqList_Destroy(stack);
	return ;
}

//���ջ���൱����ս�˳�����Ա�
void seqStack_Clear(SeqStack* stack)
{
	SeqList_Clear(stack);
	return ;

}

//��ȡջ�ĳ��ȣ��൱�ڻ�ȡ˳�����Ա�ĳ���
int seqStack_Length(SeqStack* stack)
{
	
	return SeqList_Length(stack);

}

//��ȡջ���������൱�ڻ�ȡ˳�����Ա������
int seqStack_Capacity(SeqStack* stack)
{
	return SeqList_Capacity(stack);

}

//��ջ���൱����˳�����Ա��β������Ԫ��
int seqStack_Push(SeqStack* stack, void* item)
{
	
	return SeqList_Insert(stack, item, SeqList_Length(stack));

}

//��ջ���൱����˳�����Ա��β��ɾ��Ԫ��
void* seqStack_Pop(SeqStack* stack)
{
	
	return SeqList_Delete(stack, SeqList_Length(stack) - 1);

}

//��ȡջ��Ԫ�أ���ȡ˳�����Ա��β��Ԫ��
void* seqStack_Top(SeqStack* stack)
{
	return SeqList_Get(stack, SeqList_Length(stack) - 1);

}