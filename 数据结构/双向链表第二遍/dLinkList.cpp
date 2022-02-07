#include"dLinkList.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode* slider;
	int length;
}TDLinkList;

//��������
DLinkList* dLinkList_Create()
{
	TDLinkList* ret = NULL;

	ret = (TDLinkList*)malloc(sizeof(TDLinkList));

	if (ret == NULL)
	{
		printf("func dLinkList_Create() err,-1\n");
		return NULL;
	}

	memset(ret, 0, sizeof(TDLinkList));

	return ret;
}


//
void dLinkList_Destroy(DLinkList* list)
{

	TDLinkList* tlist = NULL;

	tlist = (TDLinkList*)list;

	if (tlist == NULL)
	{
		printf("func dLinkList_Destroy() err,-1\n");
		return;
	}

	free(tlist);
}


//�������
void dLinkList_Clear(DLinkList* list)
{
	TDLinkList* tlist = NULL;

	tlist = (TDLinkList*)list;

	if (tlist == NULL)
	{
		printf("func dLinkList_Clear() err,-1\n");
		return;
	}

	tlist->header.next = NULL;
	tlist->slider = NULL;
	tlist->length = 0;
}


//��ȡ����ĳ���
int dLinkList_Length(DLinkList* list)
{
	TDLinkList* tlist = NULL;

	tlist = (TDLinkList*)list;

	if (tlist == NULL)
	{
		printf("func dLinkList_Clear() err,-1\n");
		return -1;
	}

	return tlist->length;
}

//������list��POSλ�ò���ڵ�Node
int dLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* current = NULL;
	DLinkListNode* next = NULL;


	if (tlist == NULL || node == NULL || pos < 0)
	{

		printf("func dLinkList_Insert() err.-1\n");
		return -1;

	}

	//�ݴ��������λ�ô�������ĳ���ʱ��������β�˲���
	if (pos > tlist->length)
	{
		pos = tlist->length;
	}

	current = &(tlist->header);//currentָ��ָ��ͷ���

	for (int i = 0; i < pos; i++)
	{
		current = current->next;//currentָ��ָ��Ҫ����ڵ��ǰһ���ڵ�
	}

	next = current->next;//nextָ��ָ��Ҫ����λ�õ���һ��λ��

	node->next = next;
	current->next = node;

	if (next != NULL)
	{
		next->pre = node;
	}

	node->pre = current;

	if (current == &(tlist->header))//�������ͷ������
	{
		node->pre = NULL;
	}

	//��һ�β��룬���α�ָ�����Ľڵ�
	if (tlist->length == 0)
	{
		tlist->slider = node;
	}

	tlist->length++;
	return 0;
}


//ɾ������list��posλ�õĽڵ�
DLinkListNode* dLinkList_Delete(DLinkList* list, int pos)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* current = NULL;
	DLinkListNode* next = NULL;
	DLinkListNode* ret = NULL;

	if (tlist == NULL || pos < 0)
	{
		printf("func dLinkList_Delete() err.-1\n");
		return NULL;
	}

	//�ݴ���ɾ����λ�ô�������ĳ���ʱ��
	if (pos >= tlist->length)
	{
		printf("func dLinkList_Delete() err.-2\n");
		return NULL;
	}

	current = &(tlist->header);//currentָ��ָ��ͷ���

	for (int i = 0; i < pos; i++)
	{
		current = current->next;//currentָ��ָ��Ҫɾ���ڵ��ǰһ���ڵ�
	}

	ret = current->next;
	next = ret->next;

	current->next = next;//�ñ�ɾ���ڵ��ǰһ���ڵ����ӱ�ɾ���ڵ�ĺ�һ���ڵ�

	if (next != NULL)
	{
		next->pre = ret->pre;
	}

	//���ɾ�������α�ָ��Ľڵ�,���α����
	if (tlist->slider == ret)
	{
		tlist->slider = tlist->slider->next;
	}

	//
	tlist->length--;


	return ret;
}


//��ȡ����list��poeλ�õĽڵ�
DLinkListNode* dLinkList_Get(DLinkList* list, int pos)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* current = NULL;
	DLinkListNode* ret = NULL;

	if (tlist == NULL || pos < 0)
	{
		printf("func dLinkList_Get() err.-1\n");
		return NULL;
	}

	//�ݴ���ɾ����λ�ô�������ĳ���ʱ��
	if (pos >= tlist->length)
	{
		printf("func ddLinkList_Get err.-2\n");
		return NULL;
	}

	current = &(tlist->header);//currentָ��ָ��ͷ���

	for (int i = 0; i < pos; i++)
	{
		current = current->next;//currentָ��ָ��Ҫɾ���ڵ��ǰһ���ڵ�
	}

	ret = current->next;

	return ret;
}


//��λ�α�ָ�룬��������λ֮��Ľڵ�
DLinkListNode* dLinkList_Reset(DLinkList* list)
{
	TDLinkList* tlist = (TDLinkList*)list;

	if (tlist == NULL)
	{
		printf("func dLinkList_Reset() err.-1\n");
		return NULL;
	}

	tlist->slider = tlist->header.next;

	return tlist->slider;
}


//ɾ������list�е�node�ڵ�
DLinkListNode* dLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* current = NULL;
	DLinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL || node==NULL)
	{
		printf("func dLinkList_Reset() err.-1\n");
		return NULL;
	}

	current = &(tlist->header);

	//��list���ҵ�node�ڵ㣬ͨ��λ��ɾ���ڵ�
	for (i = 0; i < tlist->length; i++)
	{
		current = current->next;
		if (current == node)
		{
			break;
		}
	}
	ret = dLinkList_Delete(list, i);

	return ret;
}


//��ȡ�α�ָ�뵱ǰָ��λ�õĵĽڵ�
DLinkListNode* dLinkList_Current(DLinkList* list)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL)
	{
		printf("func dLinkList_Reset() err.-1\n");
		return NULL;
	}

	
	ret = tlist->slider;
	
	return ret;
}


//���α�ָ����ƣ��������ƶ�ǰ�Ľڵ�
DLinkListNode* dLinkList_Next(DLinkList* list)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL)
	{
		printf("func dLinkList_Reset() err.-1\n");
		return NULL;
	}

	ret = tlist->slider;

	tlist->slider = ret->next;

	return ret;

}


//���α�ָ��ǰ�ƣ��������ƶ�ǰ�Ľڵ�
DLinkListNode* dLinkList_Pre(DLinkList* list)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL)
	{
		printf("func dLinkList_Reset() err.-1\n");
		return NULL;
	}

	ret = tlist->slider;

	tlist->slider = ret->pre;

	return ret;
}