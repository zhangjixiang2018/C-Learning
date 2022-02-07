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

//创建链表
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


//删除链表
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


//清空链表
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

//获取链表的长度
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


//向链表list中的pos位置插入节点node
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

	//容错，如果要插入的位置大于链表的长度，则链表尾部插入
	if (pos > circleLinkList_Length(list))
	{
		printf("func circleList_Insert() err. -2");
		return -2;
	}

	current = &(tlist->header);//current指向头指针

	for (int i = 0; i < pos; i++)
	{   //current指向要插入位置的前一个位置
		current = current->next;
	}

	//last = circleLinkList_Get(list,circleLinkList_Length(list)-1);//获取尾节点

	node->next = current->next;//node节点连接后续节点
	current->next = node;//current节点连接node节点

	/*
	//如果current没移动，说明是在头部插入
	if (current == &(tlist->header))
	{
		if (last != NULL)//last为空说明是首次插入，需将node的next指向自己，以此来形成循环链表
		{				//last不为空说明是不是首次插入，需将last的next指向node，以此来形成循环链表
			last->next = node;
		}
		else
		{
			node->next = node;
		}
	}*/

	//如果是第一次插入，则将游标指针指向node
	if (tlist->length == 0)
	{
		tlist->slider = node;
	}

	tlist->length++;


	//current没有移动说明是在头部插入
	if (current == &(tlist->header))
	{
		//将尾节点的next指向新插入的节点
		//这种写法保护了首次向链表中添加节点时，让自己指向自己,而不用做其余的判断.
		//若将获取尾节点的操作写在插入节点之前，则要做其他操作来判断是否是第一次插入节点
		last = circleLinkList_Get(list, tlist->length - 1);//获取尾节点
		last->next = current->next;

	}

	return 0;
}


//删除list中pos位置的节点，并返回该节点
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

	//容错，如果要删除的位置大于链表的长度
	if (pos > circleLinkList_Length(list))
	{
		printf("func circleLinkList_Insert().-2\n");
		return NULL;
	}

	current = &(tlist->header);//current指向头指针

	for (int i = 0; i < pos; i++)
	{   //current指向要删除位置的前一个位置
		current = current->next;
	}

	last = circleLinkList_Get(list, circleLinkList_Length(list)-1);//获取尾节点

	ret = current->next;//缓存要删除的节点
	current->next = ret->next;//current连接后续节点


	//如果current没移动，说明是在头部删除，在头部删除需要尾节点的next指向被删除节点的下一个节点
	if (current == &(tlist->header) && last != NULL)
	{
		last->next = ret->next;
	}

	tlist->length--;

	//若删除的节点为游标指针指向的位置，则将指针后移
	if (ret = tlist->slider)
	{
		tlist->slider = tlist->slider->next;
	}

	//如果list的节点都被删除，则将链表手动清空，不让循环链表无法删掉最后一个节点
	if (tlist->length == 0)
	{
		tlist->header.next = NULL;
		tlist->slider = NULL;
	}

	return ret;
}


//获取list中pos位置的节点
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


	current = &(tlist->header);//current指向头指针

	for (int i = 0; i < pos; i++)
	{   //current指向要删除位置的前一个位置
		current = current->next;
	}

	ret = current->next;

	return ret;
}


//删除List中node节点，并返回删除的节点
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

	current = &(tlist->header);//current指向头指针

	//在链表中找到node节点的位置
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
		//通过节点的位置删除节点
		ret = circleLinkList_Delete(list, i);
	}
	

	return ret;

}


//复位游标指针，并返回复位后的位置
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


//返回游标指针当前指向的节点
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


//将游标指正向后移动一个位置，并返回移动前的位置
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