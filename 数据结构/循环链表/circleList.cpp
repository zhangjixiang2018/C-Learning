#include"circleList.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>

/*
�ýṹ���������ʲô��
�ýṹ����ͷ�ڵ㣬ͨ���ýڵ�����ҵ����������൱���������ڡ�
*/
typedef struct _tag_CircleList
{
	TCircleListNode header; //Ϊʲô����TCircleListNode* header��
	TCircleListNode* slider;//�α�ָ��
	int length;
}TCircleList;

//����ѭ������
CircleList* circleList_Create()
{
	TCircleList* list = NULL;

	list = (TCircleList*)malloc(sizeof(TCircleList));
	
	if (list == NULL)
	{	
		printf("func circleList_Create() err: -1\n");
		return NULL;
	}
	memset(list, 0, sizeof(TCircleList));
	list->header.next = NULL;
	list->slider = NULL;
	list->length = 0;

	return list;
}

//ɾ��ѭ������
void circleList_Destroy(CircleList* list)
{
	if (list == NULL)
	{
		printf("func circleList_Destroy() err: -1\n");
		return;
	}

	free(list);
	return;
}

//���ѭ������
void circleList_Clear(CircleList* list)
{
	TCircleList* tmp = NULL;
	if (list == NULL)
	{
		printf("func circleList_Clear() err: -1\n");
		return;
	}
	tmp = (TCircleList*)list;


	tmp->header.next = NULL;
	tmp->slider = NULL;
	tmp->length = NULL;
	return;

}


//��ȡѭ������ĳ���
int circleList_Length(CircleList* list)
{
	TCircleList* tmp = NULL;
	if (list == NULL)
	{
		printf("func circleList_Length err: -1\n");
		return -1;
	}
	tmp = (TCircleList*)list;

	return tmp->length;
}


//��ѭ������list��posλ�ò���ڵ�node
int circleList_Insert(CircleList* list, TCircleListNode* node, int pos)
{
	TCircleListNode* current = NULL;
	TCircleList* tmp = NULL;
	int ret = 0, i = 0;
	
	if (list == NULL || node == NULL || pos<0)
	{
		ret = -1;
		printf("func circleList_Insert() err: -1\n");
		return ret;
	}
	tmp = (TCircleList*)list;

	current = &(tmp->header);


	for (i = 0; (i < pos)&&(current->next != NULL); i++)
	{
		current = current->next;
	}

	node->next = current->next;
	current->next = node;

	//����һ�β���ڵ�
	if (tmp->length == 0)
	{
		tmp->slider = node;
	}
	tmp->length++;

	//�������ͷ�����룬��Ҫ��β�ڵ��nextָ�����Ľڵ�
	//��ͷ�巨 current��Ȼָ��ͷ��
	//��ԭ���ǣ���0����û�����ߣ�
	if (current == &(tmp->header))
	{
		//��ȡ���һ���ڵ�
		TCircleListNode* last = (TCircleListNode*)circleList_Get(list, tmp->length - 1);
		last->next = current->next;
	}

	

	return ret;
}


//��ȡѭ������lsit��posλ�õĽڵ�
TCircleListNode* circleList_Get(CircleList* list, int pos)
{
	TCircleList* tmp = NULL;
	TCircleListNode* current = NULL;
	
	int i = 0;

	if (list == NULL || pos < 0)
	{
		printf("func  circleList_Get err: -1\n");
		return NULL;
	}
	tmp = (TCircleList*)list;

	current = &(tmp->header);
	for (i = 0; i < pos; i++)
	{
		current = current->next;
	}

	return current->next;
}


//ɾ��ѭ������List��posλ�õĽڵ㣬���ر�ɾ���Ľڵ�
TCircleListNode* circleList_Delete(CircleList* list, int pos)
{
	TCircleList* tmp = NULL;
	TCircleListNode* current = NULL;
	TCircleListNode* ret = NULL;
	int i = 0;

	if (list == NULL || pos<0)
	{
		printf("func  circleList_Delete err: -1\n");
		return NULL;
	}
	tmp = (TCircleList*)list;

	if (tmp->length<=0)
	{
		printf("func  circleList_Delete err: -2\n");
		return NULL;
	}

	current = &(tmp->header);
	for (i = 0; i < pos; i++)
	{
		current = current->next;
	}

	//��ɾ����һ��Ԫ�أ���β�ڵ�ָ��ɾ���ڵ��next
	TCircleListNode* last = NULL;
	if (current == &(tmp->header))
	{
		last = (TCircleListNode*)circleList_Get(list, tmp->length - 1);
	}

	ret = current->next;
	current->next = ret->next;
	tmp->length--;

	if (last != NULL)
	{
		tmp->header.next = ret->next;//���ࣿ
		last->next = ret->next;
	}

	//��ɾ����Ԫ��Ϊ�α���ָλ��
	if (tmp->slider == ret)
	{
		tmp->slider = ret->next;
	}

	//��ɾ��Ԫ�غ�������Ϊ0
	if (tmp->length == 0)
	{
		tmp->header.next = NULL;
		tmp->slider = NULL;
	}

	return ret;

}


//ɾ��ѭ������list�еĽڵ�Node,���ر�ɾ���Ľڵ�
TCircleListNode* circleList_DeleteNode(CircleList* list, TCircleListNode* node)
{
	TCircleListNode* current = NULL;
	TCircleListNode* ret = NULL;
	TCircleList* slist = (TCircleList*)list;
	int i = 0;

	if (slist != NULL && node != NULL)
	{
		current = &(slist->header);

		for (i = 0; i < slist->length; i++)
		{	//�ҵ�Ҫɾ���Ľڵ�
			if (current->next == node)
			{
				ret = current->next;
				break;
			}
			current = current->next;
		}

		//�ҵ�Ҫɾ���Ľڵ����λ��ȥɾ��
		if (ret != NULL)
		{
			circleList_Delete(list, i);
		}
	}

	return ret;
}


//��λ�α�ָ�룬�����α�ָ�����ú�ָ��Ľڵ�
TCircleListNode* circleList_Reset(CircleList* list)
{
	TCircleListNode* ret = NULL;
	TCircleList* slist = (TCircleList*)list;

	if (slist != NULL)
	{
		slist->slider = slist->header.next;
		ret = slist->slider;
	}
	return ret;

}


//��ȡѭ������list��ǰλ�õĽڵ�
TCircleListNode* circleList_Current(CircleList* list)
{
	TCircleListNode* ret = NULL;
	TCircleList* slist = (TCircleList*)list;

	if (slist != NULL)
	{
		ret = slist->slider;
	}

	return ret;
}


//��ƫ��ָ��ָ����һ���ڵ㣬���ص�ǰ�ڵ�
TCircleListNode* circleList_Next(CircleList* list)
{
	TCircleListNode* ret = NULL;
	TCircleList* slist = (TCircleList*)list;

	if (slist != NULL )
	{
		ret = slist->slider;
		slist->slider = ret->next;
	}

	return ret;

}
