#pragma once
typedef void LinkList;
typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode* next;
}LinkListNode;

//������ʽ���Ա�
LinkList* linkList_Create();

//ɾ����ʽ���Ա�
void linkList_Destroy(LinkList* list);

//�����ʽ���Ա�
void linkList_Clear(LinkList* list);

//����ʽ���Ա�list��posλ�ò���ڵ�node
//����ֵ������0����ɹ�
int linkList_Insert(LinkList* list, LinkListNode* node, int pos);

//��ȡ��ʽ���Ա�ĳ���
int linkList_Length(LinkList* list);

//��ȡ��ʽ���Ա�list��posλ�õ�Ԫ��
LinkListNode* linkList_Get(LinkList* list, int pos);

//ɾ����ʽ���Ա�list��posλ�õ�Ԫ��
LinkListNode* linkList_Delete(LinkList* list, int pos);


//


//

