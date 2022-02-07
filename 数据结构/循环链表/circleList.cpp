#include"circleList.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>

/*
该结构体的作用是什么？
该结构体是头节点，通过该节点可以找到整个链表，相当于链表的入口。
*/
typedef struct _tag_CircleList
{
	TCircleListNode header; //为什么不是TCircleListNode* header？
	TCircleListNode* slider;//游标指针
	int length;
}TCircleList;

//创建循环链表
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

//删除循环链表
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

//清空循环链表
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


//获取循环链表的长度
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


//向循环链表list的pos位置插入节点node
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

	//若第一次插入节点
	if (tmp->length == 0)
	{
		tmp->slider = node;
	}
	tmp->length++;

	//如果是在头部插入，需要将尾节点的next指向插入的节点
	//若头插法 current仍然指向头部
	//（原因是：跳0步，没有跳走）
	if (current == &(tmp->header))
	{
		//获取最后一个节点
		TCircleListNode* last = (TCircleListNode*)circleList_Get(list, tmp->length - 1);
		last->next = current->next;
	}

	

	return ret;
}


//获取循环链表lsit中pos位置的节点
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


//删除循环链表List中pos位置的节点，返回被删除的节点
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

	//若删除第一个元素，将尾节点指向被删除节点的next
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
		tmp->header.next = ret->next;//多余？
		last->next = ret->next;
	}

	//若删除的元素为游标所指位置
	if (tmp->slider == ret)
	{
		tmp->slider = ret->next;
	}

	//若删除元素后，链表长度为0
	if (tmp->length == 0)
	{
		tmp->header.next = NULL;
		tmp->slider = NULL;
	}

	return ret;

}


//删除循环链表list中的节点Node,返回被删除的节点
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
		{	//找到要删除的节点
			if (current->next == node)
			{
				ret = current->next;
				break;
			}
			current = current->next;
		}

		//找到要删除的节点根据位置去删除
		if (ret != NULL)
		{
			circleList_Delete(list, i);
		}
	}

	return ret;
}


//置位游标指针，返回游标指针重置后指向的节点
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


//获取循环链表list当前位置的节点
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


//将偏移指针指向下一个节点，返回当前节点
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
