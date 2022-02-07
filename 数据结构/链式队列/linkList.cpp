#include"linkList.h"
#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;


LinkList* linkList_Create()
{
	TLinkList* tlist = NULL;
	tlist = (TLinkList*)malloc(sizeof(TLinkList));
	if (tlist == NULL)
	{
		printf("func linkList_Create() err.-1\n");
		return NULL;
	}
	memset(tlist, 0, sizeof(TLinkList));

	return tlist;
}


void linkList_Destroy(LinkList* list)
{
	TLinkList* tlist = (TLinkList*)list;
	if (tlist == NULL)
	{
		printf("func linkList_Destroy() err.-1\n");
		return;
	}
	free(list);
	return;
}


void linkList_Clear(LinkList* list)
{
	TLinkList* tlist = (TLinkList*)list;
	if (tlist == NULL)
	{
		printf("func linkList_Clear() err.-1\n");
		return;
	}

	tlist->header.next = NULL;
	tlist->length = 0;

	return;

}


int linkList_Length(LinkList* list)
{
	TLinkList* tlist = (TLinkList*)list;
	if (tlist == NULL)
	{
		printf("func linkList_Length() err.-1\n");
		return -1;
	}
	return tlist->length;

}


int linkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	TLinkList* tlist = (TLinkList*)list;
	LinkListNode* current = NULL;

	if (tlist == NULL || node==NULL || pos<0)
	{
		printf("func linkList_Insert() err.-1\n");
		return -1;
	}
	//�ݴ� ��������Ϊλ�ô�������ĳ��ȣ�����β������
	if (pos > tlist->length)
	{
		pos = tlist->length;
	}

	current = &(tlist->header);//currentָ��ͷ���

	//currentָ�����λ�õ�ǰһ��λ��
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	node->next = current->next;
	current->next = node;

	tlist->length++;
	return 0;

}


LinkListNode* linkList_Delete(LinkList* list, int pos)
{
	TLinkList* tlist = (TLinkList*)list;
	LinkListNode* current = NULL;
	LinkListNode* ret = NULL;


	if (tlist == NULL || pos < 0)
	{
		printf("func linkList_Delete() err.-1\n");
		return NULL;
	}
	//�ݴ� ���ɾ����Ϊλ�ô�������ĳ���
	if (pos >= tlist->length)
	{
		printf("func linkList_Delete() err.-2\n");
		return NULL;
	}

	current = &(tlist->header);//currentָ��ͷ���

	//currentָ�����λ�õ�ǰһ��λ��
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	ret = current->next;//���汻ɾ���Ľڵ�
	current->next = ret->next;//current�ڵ����Ӻ����ڵ�

	tlist->length--;
	return ret;
}


LinkListNode* linkList_Get(LinkList* list, int pos)
{
	TLinkList* tlist = (TLinkList*)list;
	LinkListNode* current = NULL;
	LinkListNode* ret = NULL;


	if (tlist == NULL || pos < 0)
	{
		printf("func linkList_Get() err.-1\n");
		return NULL;
	}
	//�ݴ� ���ɾ����Ϊλ�ô�������ĳ���
	if (pos >= tlist->length)
	{
		printf("func linkList_Get() err.-2\n");
		return NULL;
	}

	current = &(tlist->header);//currentָ��ͷ���

	//currentָ�����λ�õ�ǰһ��λ��
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	ret = current->next;

	return ret;
}
