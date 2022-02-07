#include"seqQueue.h"
#include"seqList.h"
#include<stdio.h>

//�������У��൱�ڴ���˳�����Ա�
SeqQueue* seqQueue_Create(int capacity)
{
	return SeqList_Create(capacity);
}


//ɾ������,�൱��ɾ��˳�����Ա�
void seqQueue_Destory(SeqQueue* queue)
{

	SeqList_Destroy(queue);
}


//��ն���,�൱�����˳�����Ա�
void seqQueue_Clear(SeqQueue* queue)
{

	SeqList_Clear(queue);
}


//��ȡ���еĳ���,�൱�ڻ�ȡ˳�����Ա�ĳ���
int seqQueue_Length(SeqQueue* queue)
{

	return SeqList_Length(queue);
}


//��ȡ���е�����,�൱�ڻ�ȡ˳�����Ա������
int seqQueue_Capacity(SeqQueue* queue)
{
	return SeqList_Capacity(queue);
}


//���Ԫ��,�൱����˳�����Ա��β������Ԫ��
int seqQueue_Append(SeqQueue* queue, void* item)
{
	int ret = 0;
	ret = SeqList_Insert(queue, (SeqListNode*)item, SeqList_Length(queue));
	return ret;

}


//ɾ��Ԫ��,�൱����˳�����Ա��ͷ��ɾ��Ԫ��
void* seqQueue_Retrive(SeqQueue* queue)
{

	return SeqList_Delete(queue, 0);
}


//��ȡ��ͷԪ��
void* seqQueue_Header(SeqQueue* queue)
{

	return SeqList_Get(queue, 0);

}