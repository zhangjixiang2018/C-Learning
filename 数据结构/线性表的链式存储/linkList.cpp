#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include"linkList.h"


typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

//������ʽ���Ա�
LinkList* linkList_Create()
{
	TLinkList* ret = NULL;

	ret = (TLinkList*)malloc(sizeof(TLinkList));
	memset(ret, 0, sizeof(TLinkList));
	ret->header.next = NULL;
	ret->length = 0;

	return ret;
}


//ɾ����ʽ���Ա�
void linkList_Destroy(LinkList* list)
{
	TLinkList* tList = NULL;
	if (list == NULL)
	{
		return;
	}
	free(list);

	return ;

}


//�����ʽ���Ա�
void linkList_Clear(LinkList* list)
{
	TLinkList* tList = NULL;
	if (list == NULL)
	{
		return;
	}
	tList = (TLinkList*)list;

	tList->length = 0;
	tList->header.next = NULL;
	return;
}


//��ȡ��ʽ���Ա�ĳ���
int linkList_Length(LinkList* list)
{
	TLinkList* tList = NULL;
	int ret = 0;
	if (list == NULL)
	{
		ret = -1;
		printf("func linkList_Length() err : %d\n", ret);
		return ret;
	}
	tList = (TLinkList*)list;

	return tList->length;

}


//����ʽ���Ա�list��posλ�ò���ڵ�Node
int linkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	TLinkList* tList = NULL;
	LinkListNode* current = NULL;
	int ret = 0;
	int i = 0;

	if (list == NULL || node == NULL || pos<0)
	{
		ret = -1;
		printf("func linkList_Insert err : %d\n", ret);
		return ret;
	}
	tList = (TLinkList*)list;

	current = &(tList->header);//�ø���ָ�����ָ�������ͷ��

	//ʹcurrentָ��Ҫ��λ�õ�ǰһ���ڵ�
	//current->next != NULL ��ֹ�����λ�ñ������ȴ�
	for (i = 0; i < pos && current->next != NULL; i++)
	{
		current = current->next;
	}

	node->next = current->next;//��node���Ӻ�������
	current->next = node;//��ǰ������������µ�node�ڵ�

	tList->length++;

	return 0;

}


//��ȡ��ʽ���Ա�list��posλ�õĽڵ�
LinkListNode* linkList_Get(LinkList* list, int pos)
{
	TLinkList* tList = NULL;
	LinkListNode* current = NULL;
	int i = 0;

	if (list == NULL || pos < 0)
	{
		current = NULL;
		printf("func linkList_Get err : %d\n", -1);
		return NULL;
	}

	tList = (TLinkList*)list;
	current = &(tList->header);//�ø���ָ�����ָ�������ͷ��

	//��ȡ��λ�ñ������ȴ�
	if (pos > tList->length)
	{
		printf("func linkList_Get() err : %d\n", -2);
		return NULL;
	}

	//ʹcurrentָ��Ҫ��λ�õ�ǰһ���ڵ�
	for (i = 0; i < pos; i++)
	{
		current = current->next;
	}


	return current->next;

}

//ɾ����ʽ���Ա�list��posλ�õĽڵ�
LinkListNode* linkList_Delete(LinkList* list, int pos)
{
	TLinkList* tList = NULL;
	LinkListNode* current = NULL;
	LinkListNode* ret = NULL;
	int i = 0;

	if (list == NULL || pos < 0)
	{
		printf("func linkList_Length() err : %d\n",-1);
		return NULL;
	}
	tList = (TLinkList*)list;

	current = &(tList->header);//�ø���ָ�����ָ�������ͷ��

	//ɾ����λ�ñ������ȴ�
	if (pos >= tList->length)
	{
		printf("func linkList_Delete() err : %d\n", -2);
		return NULL;
	}

	//ʹcurrentָ��Ҫ��λ�õ�ǰһ���ڵ�
	for (i = 0; i < pos; i++)
	{
		current = current->next;
	}

	ret = current->next;//���汻ɾ���Ľڵ�
	current->next = ret->next;//��ǰ������������µ�node�ڵ�

	tList->length--;

	return ret;

}
