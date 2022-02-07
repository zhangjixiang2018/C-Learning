#pragma once

typedef void LinkList;

/*
�ýṹ���������ʲô��
�ýṹ��������ڵ㣨����ͷ�ڵ����ͨ�ڵ㣩�ĵ�һ�����ڽڵ��а����ýṹ�壬
�Ϳɽ����еĽڵ���������������ʱ����������ͼ
*/
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

//��ȡ��ʽ���Ա�ĳ���
int linkList_Length(LinkList* list);


//����ʽ���Ա�list��posλ�ò���ڵ�Node
int linkList_Insert(LinkList* list, LinkListNode* node, int pos);

//��ȡ��ʽ���Ա�list��posλ�õĽڵ�
LinkListNode* linkList_Get(LinkList* list, int pos);

//ɾ����ʽ���Ա�list��posλ�õĽڵ�
LinkListNode* linkList_Delete(LinkList* list, int pos);
