#pragma once

typedef void SeqList;
typedef void SeqListNode;

//1.������������˳������
SeqList* seqList_Create(int capacity);


//2.ɾ��˳������
void seqList_Destroy(SeqList* list);


//3.���˳������
void seqList_Clear(SeqList* list);


//4.��˳������list��posλ�ò���ڵ�node
int seqList_Insert(SeqList* list, SeqListNode* node, int pos);


//5.��ȡ˳������list�ĳ���
int seqList_Length(SeqList* list);


//6.��ȡ˳������list������
int seqList_Capacity(SeqList* list);

//7..ɾ��˳������List��posλ�õĽڵ�
SeqListNode* seqList_Delete(SeqList* list, int pos);


//8..��ȡ˳������list��posλ�õĽڵ�
SeqListNode* seqList_Get(SeqList* list, int pos);

