#pragma once
typedef void CircleLinkList;
typedef struct CircleLinkListNode
{
	CircleLinkListNode* next;
}CircleLinkListNode;

//��������
CircleLinkList* circleLinkList_Create();


//ɾ������
void circleLinkList_Destroy(CircleLinkList* list);


//�������
void circleLinkList_Clear(CircleLinkList* list);

//��ȡ����ĳ���
int circleLinkList_Length(CircleLinkList* list);


//������list�е�posλ�ò���ڵ�node
int circleLinkList_Insert(CircleLinkList* list, CircleLinkListNode* node, int pos);


//ɾ��list��posλ�õĽڵ㣬�����ظýڵ�
CircleLinkListNode* circleLinkList_Delete(CircleLinkList* list, int pos);


//��ȡlist��posλ�õĽڵ�
CircleLinkListNode* circleLinkList_Get(CircleLinkList* list, int pos);


//ɾ��List��node�ڵ㣬������ɾ���Ľڵ�
CircleLinkListNode* circleLinkList_DeleteNode(CircleLinkList* list, CircleLinkListNode* node);


//��λ�α�ָ�룬�����ظ�λ���λ��
CircleLinkListNode* circleLinkList_Reset(CircleLinkList* list);


//�����α�ָ�뵱ǰָ��Ľڵ�
CircleLinkListNode* circleLinkList_Current(CircleLinkList* list);


//���α�ָ������ƶ�һ��λ�ã��������ƶ����λ��
CircleLinkListNode* circleLinkList_Next(CircleLinkList* list);


