#pragma once
#include<stdio.h>
#include<string.h>
#include<malloc.h>


typedef void DlinkList;
typedef struct DlinkListNode
{
	struct DlinkListNode* next;
	struct DlinkListNode* pre;

}DlinkListNode;

//1.����˫������
DlinkList* dLinkList_Create();

//2.ɾ��˫������
void dLinkList_Destroy(DlinkList* list);

//3.���˫������
void dLinkList_Clear(DlinkList* list);


//4.��ȡ˫������ĳ���
int dLinkList_Length(DlinkList* list);


//5.��˫������List��posλ�ò���ڵ�node
int dLinkList_Insert(DlinkList* list, DlinkListNode* node, int pos);

//6.ɾ��˫������list��posλ�õĽڵ�
DlinkListNode* dLinkList_Delete(DlinkList* list, int pos);

//7.��ȡ˫������list��posλ�õĽڵ�
DlinkListNode* dLinkList_Get(DlinkList* list, int pos);


//8.ɾ��˫������list�е�node�ڵ�
DlinkListNode* dLinkList_DeleteNode(DlinkList* list, DlinkListNode* node);


//9.�����α�ָ�룬���������ú�Ľڵ�
DlinkListNode* dLinkList_Reset(DlinkList* list);

//10.��ȡ�α�ָ�뵱ǰָ��Ľڵ�
DlinkListNode* dLinkList_Current(DlinkList* list);


//11.���α�ָ�����һ�����������ƶ�ǰָ��Ľڵ�
DlinkListNode* dLinkList_Next(DlinkList* list);


//12.���α�ָ��ǰ��һ�����������ƶ�ǰָ��Ľڵ�
DlinkListNode* dLinkList_Pre(DlinkList* list);
