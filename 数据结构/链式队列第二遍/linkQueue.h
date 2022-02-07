#pragma once

typedef void LinkQueue;


//��������
LinkQueue* linkQueue_Create();


//���ٶ���
void linkQueue_Destroy(LinkQueue* queue);


//��ն���
void linkQueue_Clear(LinkQueue* queue);


//��ȡ���еĳ���
int linkQueue_Length(LinkQueue* queue);


//����������һ��Ԫ��
int linkqueue_Insert(LinkQueue* queue, void* item);


//������
void* linkQueue_Retrive(LinkQueue* queue);


//��ȡ��ͷԪ��
void* linkQueue_Header(LinkQueue* queue);

