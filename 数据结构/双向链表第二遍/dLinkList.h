#pragma once

typedef void DLinkList;

typedef struct DLinkListNode
{
	struct DLinkListNode* next;
	struct DLinkListNode* pre;
}DLinkListNode;


//��������
DLinkList* dLinkList_Create();


//
void dLinkList_Destroy(DLinkList* list);

//�������
void dLinkList_Clear(DLinkList* list);

//��ȡ����ĳ���
int dLinkList_Length(DLinkList* list);

//
int dLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos);


//ɾ������list��posλ�õĽڵ�
DLinkListNode* dLinkList_Delete(DLinkList* list, int pos);


//��ȡ����list��poeλ�õĽڵ�
DLinkListNode* dLinkList_Get(DLinkList* list, int pos);


//��λ�α�ָ�룬��������λ֮��Ľڵ�
DLinkListNode* dLinkList_Reset(DLinkList* list);


//ɾ������list�е�node�ڵ�
DLinkListNode* dLinkList_DeleteNode(DLinkList* list, DLinkListNode* node);


//��ȡ�α�ָ�뵱ǰָ��λ�õĵĽڵ�
DLinkListNode* dLinkList_Current(DLinkList* list);


//���α�ָ����ƣ��������ƶ�ǰ�Ľڵ�
DLinkListNode* dLinkList_Next(DLinkList* list);


//���α�ָ��ǰ�ƣ��������ƶ�ǰ�Ľڵ�
DLinkListNode* dLinkList_Pre(DLinkList* list);
