#pragma once
typedef void SeqQueue;

//��������
SeqQueue* seqQueue_Create(int capacity);


//ɾ������
void seqQueue_Destory(SeqQueue* queue);


//��ն���
void seqQueue_Clear(SeqQueue* queue);


//��ȡ���еĳ���
int seqQueue_Length(SeqQueue* queue);


//��ȡ���е�����
int seqQueue_Capacity(SeqQueue* queue);


//���Ԫ��
int seqQueue_Append(SeqQueue* queue, void* item);


//ɾ��Ԫ��
void* seqQueue_Retrive(SeqQueue* queue);


//��ȡ��ͷԪ��
void* seqQueue_Header(SeqQueue* queue);
