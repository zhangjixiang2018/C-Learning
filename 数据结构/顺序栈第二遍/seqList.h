#pragma once


typedef void SeqList;
typedef void SeqListNode;

//�������Ա�
SeqList* SeqList_Create(int capacity);

//ɾ�����Ա�
void SeqList_Destroy(SeqList* list);

//������Ա�
void SeqList_Clear(SeqList* list);

//��ȡ���Ա�ĳ���
int SeqList_Length(SeqList* list);

//��ȡ���Ա������
int SeqList_Capacity(SeqList* list);

//�����Ա�list��posλ�ò���һ���ڵ�node
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

//��ȡ���Ա�list��posλ�õĽڵ�
SeqListNode* SeqList_Get(SeqList* list, int pos);

//ɾ�����Ա�list��posλ�õĽڵ�
SeqListNode* SeqList_Delete(SeqList* list, int pos);