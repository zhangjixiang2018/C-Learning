#include"circleLinkList.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct _tag_CircleList
{
	CircleLinkListNode header;
	CircleLinkListNode* slider;
	int length;

}TCircleList;

//��������
CircleLinkList* circleLinkList_Create()
{
	TCircleList* tlist = NULL;

	tlist = (TCircleList*)malloc(sizeof(TCircleList));
	if (tlist == NULL)
	{
		printf("func circleLinkList_Create() err.-1\n");
		return NULL;
	}

	memset(tlist, 0, sizeof(TCircleList));

	return tlist;
}


//ɾ������
void circleLinkList_Destroy(CircleLinkList* list)
{
	TCircleList* tlist = (TCircleList*)list;

	if (tlist == NULL)
	{
		printf("func circleLinkList_Destroy().-1\n");
		return;
	}

	free(tlist);
}


//�������
void circleLinkList_Clear(CircleLinkList* list)
{
	TCircleList* tlist = (TCircleList*)list;

	if (tlist == NULL)
	{
		printf("funccircleLinkList_Clear().-1\n");
		return;
	}
	tlist->header.next = NULL;
	tlist->slider = NULL;
	tlist->length = 0;
	
}

//��ȡ����ĳ���
int circleLinkList_Length(CircleLinkList* list)
{
	TCircleList* tlist = (TCircleList*)list;

	if (tlist == NULL)
	{
		printf("func circleLinkList_Length().-1\n");
		return -1;
	}

	return tlist->length;
}


//������list�е�posλ�ò���ڵ�node
int circleLinkList_Insert(CircleLinkList* list, CircleLinkListNode* node, int pos)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleLinkListNode* current = NULL;
	CircleLinkListNode* last = NULL;


	if (tlist == NULL || node == NULL || pos < 0)
	{
		printf("func circleLinkList_Insert().-1\n");
		return -1;
	}

	//�ݴ����Ҫ�����λ�ô�������ĳ��ȣ�������β������
	if (pos > circleLinkList_Length(list))
	{
		printf("func circleList_Insert() err. -2");
		return -2;
	}

	current = &(tlist->header);//currentָ��ͷָ��

	for (int i = 0; i < pos; i++)
	{   //currentָ��Ҫ����λ�õ�ǰһ��λ��
		current = current->next;
	}

	//last = circleLinkList_Get(list,circleLinkList_Length(list)-1);//��ȡβ�ڵ�

	node->next = current->next;//node�ڵ����Ӻ����ڵ�
	current->next = node;//current�ڵ�����node�ڵ�

	/*
	//���currentû�ƶ���˵������ͷ������
	if (current == &(tlist->header))
	{
		if (last != NULL)//lastΪ��˵�����״β��룬�轫node��nextָ���Լ����Դ����γ�ѭ������
		{				//last��Ϊ��˵���ǲ����״β��룬�轫last��nextָ��node���Դ����γ�ѭ������
			last->next = node;
		}
		else
		{
			node->next = node;
		}
	}*/

	//����ǵ�һ�β��룬���α�ָ��ָ��node
	if (tlist->length == 0)
	{
		tlist->slider = node;
	}

	tlist->length++;


	//currentû���ƶ�˵������ͷ������
	if (current == &(tlist->header))
	{
		//��β�ڵ��nextָ���²���Ľڵ�
		//����д���������״�����������ӽڵ�ʱ�����Լ�ָ���Լ�,��������������ж�.
		//������ȡβ�ڵ�Ĳ���д�ڲ���ڵ�֮ǰ����Ҫ�������������ж��Ƿ��ǵ�һ�β���ڵ�
		last = circleLinkList_Get(list, tlist->length - 1);//��ȡβ�ڵ�
		last->next = current->next;

	}

	return 0;
}


//ɾ��list��posλ�õĽڵ㣬�����ظýڵ�
CircleLinkListNode* circleLinkList_Delete(CircleLinkList* list, int pos)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleLinkListNode* current = NULL;
	CircleLinkListNode* last = NULL;
	CircleLinkListNode* ret = NULL;



	if (tlist == NULL ||  pos < 0 || tlist->length<0)
	{
		printf("func circleLinkList_Insert().-1\n");
		return NULL;
	}

	//�ݴ����Ҫɾ����λ�ô�������ĳ���
	if (pos > circleLinkList_Length(list))
	{
		printf("func circleLinkList_Insert().-2\n");
		return NULL;
	}

	current = &(tlist->header);//currentָ��ͷָ��

	for (int i = 0; i < pos; i++)
	{   //currentָ��Ҫɾ��λ�õ�ǰһ��λ��
		current = current->next;
	}

	last = circleLinkList_Get(list, circleLinkList_Length(list)-1);//��ȡβ�ڵ�

	ret = current->next;//����Ҫɾ���Ľڵ�
	current->next = ret->next;//current���Ӻ����ڵ�


	//���currentû�ƶ���˵������ͷ��ɾ������ͷ��ɾ����Ҫβ�ڵ��nextָ��ɾ���ڵ����һ���ڵ�
	if (current == &(tlist->header) && last != NULL)
	{
		last->next = ret->next;
	}

	tlist->length--;

	//��ɾ���Ľڵ�Ϊ�α�ָ��ָ���λ�ã���ָ�����
	if (ret = tlist->slider)
	{
		tlist->slider = tlist->slider->next;
	}

	//���list�Ľڵ㶼��ɾ�����������ֶ���գ�����ѭ�������޷�ɾ�����һ���ڵ�
	if (tlist->length == 0)
	{
		tlist->header.next = NULL;
		tlist->slider = NULL;
	}

	return ret;
}


//��ȡlist��posλ�õĽڵ�
CircleLinkListNode* circleLinkList_Get(CircleLinkList* list, int pos)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleLinkListNode* current = NULL;
	CircleLinkListNode* ret = NULL;

	if (tlist == NULL || pos < 0)
	{
		printf("func circleLinkList_Get().-1\n");
		return NULL;
	}


	current = &(tlist->header);//currentָ��ͷָ��

	for (int i = 0; i < pos; i++)
	{   //currentָ��Ҫɾ��λ�õ�ǰһ��λ��
		current = current->next;
	}

	ret = current->next;

	return ret;
}


//ɾ��List��node�ڵ㣬������ɾ���Ľڵ�
CircleLinkListNode* circleLinkList_DeleteNode(CircleLinkList* list, CircleLinkListNode* node)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleLinkListNode* current = NULL;
	CircleLinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL || node == NULL)
	{
		printf("func circleLinkList_DeleteNode().-1\n");
		return NULL;
	}

	current = &(tlist->header);//currentָ��ͷָ��

	//���������ҵ�node�ڵ��λ��
	for (i = 0; i < tlist->length; i++)
	{
		if (node == current->next)
		{
			ret = current->next;
			break;
		}
		current = current->next;
	}

	if (ret != NULL)
	{
		//ͨ���ڵ��λ��ɾ���ڵ�
		ret = circleLinkList_Delete(list, i);
	}
	

	return ret;

}


//��λ�α�ָ�룬�����ظ�λ���λ��
CircleLinkListNode* circleLinkList_Reset(CircleLinkList* list)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleLinkListNode* ret = NULL;

	if (tlist == NULL )
	{
		printf("func circleLinkList_Reset().-1\n");
		return NULL;
	}

	tlist->slider = tlist->header.next;
	ret = tlist->slider;

	return NULL;
}


//�����α�ָ�뵱ǰָ��Ľڵ�
CircleLinkListNode* circleLinkList_Current(CircleLinkList* list)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleLinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL)
	{
		printf("func circleLinkList_Reset().-1\n");
		return NULL;
	}

	ret = tlist->slider;

	return ret;

}


//���α�ָ������ƶ�һ��λ�ã��������ƶ�ǰ��λ��
CircleLinkListNode* circleLinkList_Next(CircleLinkList* list)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleLinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL && tlist->slider != NULL)
	{
		printf("func circleLinkList_Next().-1\n");
		return NULL;
	}

	ret = tlist->slider;
	tlist->slider = tlist->slider->next;

	return ret;
}