#pragma once

typedef void SeqStack;

//����ջ
SeqStack* seqStack_Create(int capacity);

//ɾ��ջ
void seqStack_Destroy(SeqStack* stack);

//���ջ
void seqStack_Clear(SeqStack* stack);

//��ȡջ�ĳ���
int seqStack_Length(SeqStack* stack);

//��ȡջ������
int seqStack_Capacity(SeqStack* stack);

//��ջ
int seqStack_Push(SeqStack* stack, void* item);

//��ջ
void* seqStack_Pop(SeqStack* stack);

//��ȡջ��Ԫ��
void* seqStack_Top(SeqStack* stack);

