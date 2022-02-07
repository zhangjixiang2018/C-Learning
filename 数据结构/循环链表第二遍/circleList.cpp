#include"circleList.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct _tag_CircleList
{
	CircleListNode header;
	CircleListNode* slider;
	int length;
}TCircleList;

//1.����ѭ������
CircleList* circleList_Create()
{
	TCircleList* ret;

	ret = (TCircleList*)malloc(sizeof(TCircleList));

	if (ret == NULL)
	{
		printf("func circleList_Create() err. -1");
		return ret;
	}
	memset(ret, 0, sizeof(TCircleList));
	
	return ret;
}

//2.ɾ��ѭ������
void circleList_Destroy(CircleList* list)
{
	TCircleList* tlist = (TCircleList*)list;
	if (tlist == NULL)
	{
		printf("funccircleList_Destroy() err. -1");
		return ;
	}

	free(tlist);
	return ;

}

//3.���ѭ������
void circleList_Clear(CircleList* list)
{
	TCircleList* tlist = (TCircleList*)list;
	if (tlist == NULL)
	{
		printf("func circleList_Clear() err. -1");
		return;
	}

	tlist->length = 0;
	tlist->slider = NULL;
	tlist->header.next = NULL;
	return;
}


//4.��ȡѭ������ĳ���
int circleList_Length(CircleList* list)
{
	TCircleList* tlist = (TCircleList*)list;
	if (tlist == NULL)
	{	//����Ϊ�գ�����-1
		printf("func circleList_Length() err. -1");
		return -1;
	}

	return tlist->length;
}


//5.��ѭ������list�е�posλ�ò���ڵ�node
int circleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* current = NULL;
	CircleListNode* last = NULL;


	if (tlist == NULL || node == NULL || pos<0)
	{
		printf("func circleList_Insert() err. -1");
		return -1;
	}
	//�ݴ�1�������λ�ô��ڳ���
	if (pos > tlist->length)
	{
		printf("func circleList_Insert() err. -2");
		return -2;
	}

	current = &(tlist->header);//currentָ��ͷ���

	//current->next != NULL���������٣���������������в���ڵ�
	for (int i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}

	node->next = current->next;//��node���Ӻ�������
	current->next = node;//��ǰ������������µ�node�ڵ�

	//�ݴ�2 ����ǵ�һ�β��룬���α�ָ��ָ���һ���ڵ�
	if (tlist->length == 0)
	{
		tlist->slider = node;
	}
	tlist->length++;

	//�ݴ�3 �����ͷ������
	//currentû���ƶ�˵������ͷ������
	if (current == &(tlist->header))
	{
		//��β�ڵ��nextָ���²���Ľڵ�
		//����д���������״�����������ӽڵ�ʱ�����Լ�ָ���Լ�,��������������ж�.
		//������ȡβ�ڵ�Ĳ���д�ڲ���ڵ�֮ǰ����Ҫ�������������ж��Ƿ��ǵ�һ�β���ڵ�
		last = circleList_Get(list, tlist->length - 1);//��ȡβ�ڵ�
		last->next = current->next;
		
	}

	
	return 0;
}


//6.��ȡѭ������list�е�posλ�õĽڵ�
CircleListNode* circleList_Get(CircleList* list, int pos)
{

	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if (tlist == NULL || pos < 0)
	{
		printf("func circleList_Get() err. -1");
		return NULL;
	}
	

	ret = &(tlist->header);//currentָ��ͷ���

	//current->next != NULL���������٣��������״��������в���ڵ�
	for (int i = 0; (i < pos) && (ret->next != NULL); i++)
	{
		ret = ret->next;
	}

	return ret->next;

}


//7.ɾ��ѭ������list�е�posλ�õĽڵ㣬�����ظýڵ�
CircleListNode* circleList_Delete(CircleList* list, int pos)
{

	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* current = NULL;
	CircleListNode* last = NULL;
	CircleListNode* ret = NULL;

	if (tlist == NULL || pos < 0 || tlist->length < 0)
	{
		printf("func  circleList_Delete() err. -1");
		return NULL;
	}
	//�ݴ�1��ɾ����λ�ô��ڳ���
	if (pos > tlist->length)
	{
		printf("func  circleList_Delete() err. -2");
		return NULL;
	}

	current = &(tlist->header);//currentָ��ͷ���

	//current->next != NULL���������٣��������״��������в���ڵ�
	for (int i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}

	//�ݴ�2 ���ɾ�����ǵ�һ���ڵ�
	//currentû���ƶ�˵������ͷ��ɾ��
	if (current == &(tlist->header))
	{
		//last��Ϊ��˵������Ϊ�գ���β�ڵ��nextָ��ɾ���Ľڵ����һ���ڵ㣬���γɻ�
		last = circleList_Get(list, tlist->length - 1);//��ȡβ�ڵ�
	}

	ret = current->next;//����Ҫɾ���Ľڵ�
	current->next = ret->next;//
	tlist->length--;

	/*
	��������д������дɾ�����һ��Ԫ��ʱ����ȡβ�ڵ�ʱ�����쳣������ֻ�ܽ���ȡβ�ڵ��
	��β�ڵ�ָ��ɾ���Ľڵ����һ���ڵ�ֿ����ҽ���ȡβ�ڵ�Ҫ��tlist->length--֮ǰ��
	//���ɾ�����ǵ�һ���ڵ�
	//currentû���ƶ�˵������ͷ��ɾ��
	if (current == &(tlist->header))
	{
		//last��Ϊ��˵������Ϊ�գ���β�ڵ��nextָ��ɾ���Ľڵ����һ���ڵ㣬���γɻ�
		last = circleList_Get(list, tlist->length - 1);//��ȡβ�ڵ�
		if (last != NULL)
		{
			last->next = current->next;
		}
	}*/

	//�ݴ�3 last��Ϊ��˵������Ϊ�գ���β�ڵ��nextָ��ɾ���Ľڵ����һ���ڵ㣬���γɻ�
	if (last != NULL)
	{
		last->next = current->next;
	}

	//�ݴ�4 ��ɾ���Ľڵ�Ϊ�α�ָ��ָ���λ�ã���ָ�����
	if (ret = tlist->slider)
	{
		tlist->slider = tlist->slider->next;
	}

	//�ݴ�5 ��ɾ��Ԫ�غ�������Ϊ0
	if (tlist->length == 0)
	{
		tlist->header.next = NULL;
		tlist->slider = NULL;
	}
	return ret;
}


//8.ɾ��ѭ������list�е�node�ڵ㣬�����ظýڵ�
CircleListNode* circleList_DeleteNode(CircleList* list, CircleListNode* node)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;

	if (tlist != NULL)
	{
		CircleListNode* current = (CircleListNode*)tlist;

		//����node��ѭ�������е�λ��i
		for (i = 0; i < tlist->length; i++)
		{
			if (current->next == node)
			{
				ret = current->next;
				break;
			}

			current = current->next;
		}

		//���ret�ҵ�������iȥɾ��	
		if (ret != NULL)
		{
			circleList_Delete(tlist, i);
		}
		
	}

	return ret;

}


//9.��ȡѭ������list��ǰλ�õĽڵ�
CircleListNode* circleList_Current(CircleList* list)
{
	TCircleList* tlist = (TCircleList*)list;

	if (tlist == NULL)
	{
		printf("func  circleList_Current() err. -2");
		return NULL;
	}

	return tlist->slider;
}


//10.���α�ָ����ƣ��������ƶ�ǰ�Ľڵ�
CircleListNode* circleList_Next(CircleList* list)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;


	if ((tlist == NULL) && (tlist->slider != NULL))
	{
		printf("func circleList_Next() err. -2");
		return NULL;
	}

	ret = tlist->slider;
	tlist->slider = tlist->slider->next;

	return ret;

}


//11.�����α�ָ��,�����������α�ָ����α�ָ��ָ��Ľڵ�
CircleListNode* circleList_Reset(CircleList* list)
{

	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;


	if (tlist == NULL)
	{
		printf("func  circleList_Reset() err. -2");
		return NULL;
	}

	tlist->slider = tlist->header.next;
	ret = tlist->slider;

	return ret;

}