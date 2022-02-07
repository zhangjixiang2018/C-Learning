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

//1.创建循环链表
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

//2.删除循环链表
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

//3.清空循环链表
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


//4.获取循环链表的长度
int circleList_Length(CircleList* list)
{
	TCircleList* tlist = (TCircleList*)list;
	if (tlist == NULL)
	{	//链表为空，返回-1
		printf("func circleList_Length() err. -1");
		return -1;
	}

	return tlist->length;
}


//5.在循环链表list中的pos位置插入节点node
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
	//容错1，插入的位置大于长度
	if (pos > tlist->length)
	{
		printf("func circleList_Insert() err. -2");
		return -2;
	}

	current = &(tlist->header);//current指向头结点

	//current->next != NULL条件不能少，可用于向空链表中插入节点
	for (int i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}

	node->next = current->next;//让node连接后续链表
	current->next = node;//让前面的链表连接新的node节点

	//容错2 如果是第一次插入，则将游标指针指向第一个节点
	if (tlist->length == 0)
	{
		tlist->slider = node;
	}
	tlist->length++;

	//容错3 如果在头部插入
	//current没有移动说明是在头部插入
	if (current == &(tlist->header))
	{
		//将尾节点的next指向新插入的节点
		//这种写法保护了首次向链表中添加节点时，让自己指向自己,而不用做其余的判断.
		//若将获取尾节点的操作写在插入节点之前，则要做其他操作来判断是否是第一次插入节点
		last = circleList_Get(list, tlist->length - 1);//获取尾节点
		last->next = current->next;
		
	}

	
	return 0;
}


//6.获取循环链表list中的pos位置的节点
CircleListNode* circleList_Get(CircleList* list, int pos)
{

	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if (tlist == NULL || pos < 0)
	{
		printf("func circleList_Get() err. -1");
		return NULL;
	}
	

	ret = &(tlist->header);//current指向头结点

	//current->next != NULL条件不能少，可用于首次向链表中插入节点
	for (int i = 0; (i < pos) && (ret->next != NULL); i++)
	{
		ret = ret->next;
	}

	return ret->next;

}


//7.删除循环链表list中的pos位置的节点，并返回该节点
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
	//容错1，删除的位置大于长度
	if (pos > tlist->length)
	{
		printf("func  circleList_Delete() err. -2");
		return NULL;
	}

	current = &(tlist->header);//current指向头结点

	//current->next != NULL条件不能少，可用于首次向链表中插入节点
	for (int i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}

	//容错2 如果删除的是第一个节点
	//current没有移动说明是在头部删除
	if (current == &(tlist->header))
	{
		//last不为空说明链表不为空，则将尾节点的next指向被删除的节点的下一个节点，以形成环
		last = circleList_Get(list, tlist->length - 1);//获取尾节点
	}

	ret = current->next;//缓存要删除的节点
	current->next = ret->next;//
	tlist->length--;

	/*
	不能这样写，这样写删除最后一个元素时，获取尾节点时会有异常，所以只能将获取尾节点和
	将尾节点指向被删除的节点的下一个节点分开，且将获取尾节点要在tlist->length--之前。
	//如果删除的是第一个节点
	//current没有移动说明是在头部删除
	if (current == &(tlist->header))
	{
		//last不为空说明链表不为空，则将尾节点的next指向被删除的节点的下一个节点，以形成环
		last = circleList_Get(list, tlist->length - 1);//获取尾节点
		if (last != NULL)
		{
			last->next = current->next;
		}
	}*/

	//容错3 last不为空说明链表不为空，则将尾节点的next指向被删除的节点的下一个节点，以形成环
	if (last != NULL)
	{
		last->next = current->next;
	}

	//容错4 若删除的节点为游标指针指向的位置，则将指针后移
	if (ret = tlist->slider)
	{
		tlist->slider = tlist->slider->next;
	}

	//容错5 若删除元素后，链表长度为0
	if (tlist->length == 0)
	{
		tlist->header.next = NULL;
		tlist->slider = NULL;
	}
	return ret;
}


//8.删除循环链表list中的node节点，并返回该节点
CircleListNode* circleList_DeleteNode(CircleList* list, CircleListNode* node)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;

	if (tlist != NULL)
	{
		CircleListNode* current = (CircleListNode*)tlist;

		//查找node在循环链表中的位置i
		for (i = 0; i < tlist->length; i++)
		{
			if (current->next == node)
			{
				ret = current->next;
				break;
			}

			current = current->next;
		}

		//如果ret找到，根据i去删除	
		if (ret != NULL)
		{
			circleList_Delete(tlist, i);
		}
		
	}

	return ret;

}


//9.获取循环链表list当前位置的节点
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


//10.将游标指针后移，并返回移动前的节点
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


//11.重置游标指针,并返回重置游标指针后游标指针指向的节点
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