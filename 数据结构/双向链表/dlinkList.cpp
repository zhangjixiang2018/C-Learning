#include"dlinkList.h"


typedef struct _tag_DLinkListNode
{
	DlinkListNode header;
	DlinkListNode* slider;
	int length;

}TDLinkListNode;

//1.创建双向链表
DlinkList* dLinkList_Create()
{
	TDLinkListNode* tlist;

	tlist = (TDLinkListNode*)malloc(sizeof(TDLinkListNode));
	if (tlist == NULL)
	{
		printf("func dLinkList_Create() err. -1 \n");
		return NULL;
	}
	memset(tlist, 0, sizeof(TDLinkListNode));

	return tlist;
}

//2.删除双向链表
void dLinkList_Destroy(DlinkList* list)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	if (tlist == NULL)
	{
		printf("func ddLinkList_Destroy() err. -1 \n");
		return;
	}
	free(tlist);
}

//3.清空双向链表
void dLinkList_Clear(DlinkList* list)
{

	TDLinkListNode* tlist = (TDLinkListNode*)list;
	if (tlist == NULL)
	{
		printf("func ddLinkList_Destroy() err. -1 \n");
		return;
	}

	tlist->header.next = NULL;
	tlist->slider = NULL;
	tlist->length = 0;
}


//4.获取双向链表的长度
int dLinkList_Length(DlinkList* list)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	if (tlist == NULL)
	{
		printf("func dLinkList_Length() err. -1 \n");
		return -1;
	}

	return tlist->length;
}


//5.向双向链表List的pos位置插入节点node
int dLinkList_Insert(DlinkList* list, DlinkListNode* node, int pos)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	DlinkListNode* current = NULL;
	DlinkListNode* next = NULL;


	if (tlist == NULL || node == NULL || pos < 0)
	{
		printf("func dLinkList_Insert err. -1\n");
		return -1;
	}
	//容错  如果插入的位置大于链表的长度，则在链表尾端插入
	if (pos > tlist->length)
	{
		pos = tlist->length;
	}

	current = &(tlist->header);//current指针指向头结点
	//current指针移动到pos-1位置
	for (int i = 0; (i < pos)&&(current->next!=NULL); i++)
	{
		current = current->next;
	}

	next = current->next;

	current->next = node;//让current指针连接node
	node->next = next;//让node连接后续节点
	
	if (next != NULL)
	{
		next->pre = node;//让next指针连接node
	}

	//当链表插入第一个元素，需特殊处理
	// 特殊处理，当不为头部插入时，将node的pre指向current，
	//当为头部插入时node->pre为空
	node->pre = current;//让node连接前面的节点
	if (current == &(tlist->header))
	{								
		node->pre = NULL;//让node连接前面的节点
	}

	if (tlist->length == 0)
	{
		tlist->slider = node;//当插入第一个节点时，处理游标
	}
	

	tlist->length++;

	return 0;
}

//6.删除双向链表list的pos位置的节点
DlinkListNode* dLinkList_Delete(DlinkList* list, int pos)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	DlinkListNode* current = NULL;
	DlinkListNode* next = NULL;
	DlinkListNode* ret = NULL;


	if (tlist == NULL ||  pos < 0)
	{
		printf("func dLinkList_Delete（） err. -1\n");
		return NULL;
	}
	//容错  如果删除的位置大于链表的长度
	if (pos >= tlist->length)
	{
		printf("func dLinkList_Delete（） err. -2\n");
		return NULL;
	}

	current = &(tlist->header);//current指针指向头结点
	//current指针移动到pos-1位置
	for (int i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}

	ret = current->next;
	next = ret->next;

	current->next = next;//让current指针连接后续节点
	if (next != NULL)
	{
		next->pre = ret->pre;//让next指针连接前续节点
	}

	//如果删除的是游标指向的节点，将游标后移
	if (ret == tlist->slider)
	{
		tlist->slider = ret->next;
	}

	tlist->length--;
	return ret;
}

//7.获取双向链表list的pos位置的节点
DlinkListNode* dLinkList_Get(DlinkList* list, int pos)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	DlinkListNode* current = NULL;
	DlinkListNode* ret = NULL;


	if (tlist == NULL || pos < 0)
	{
		printf("func dLinkList_Get（） err. -1\n");
		return NULL;
	}
	//容错  如果获取的位置大于链表的长度
	if (pos > tlist->length)
	{
		printf("func dLinkList_Get（） err. -2\n");
		return NULL;
	}

	current = &(tlist->header);//current指针指向头结点
	//current指针移动到pos-1位置
	for (int i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}

	ret = current->next;
	

	return ret;
}


//8.删除双向链表list中的node节点
//如果链表中不存在node节点，返回NULL，删除成功返回node
DlinkListNode* dLinkList_DeleteNode(DlinkList* list, DlinkListNode* node)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	DlinkListNode* current = NULL;
	DlinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL || node==NULL)
	{
		printf("func dLinkList_DeleteNode（） err. -1\n");
		return NULL;
	}
	
	current = &(tlist->header);//current指针指向头结点
	//遍历链表，找到node节点的位置，通过位置删除node节点
	for (i = 0; i<tlist->length; i++)
	{
		if (current->next == node)
		{
			ret = current->next;
			break;
		}
		current = current->next;
	}

	if (ret != NULL)
	{
		dLinkList_Delete(list, i);
	}

	return ret;
}


//9.重置游标指针，并返回重置后的节点
DlinkListNode* dLinkList_Reset(DlinkList* list)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	DlinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL)
	{
		printf("func dLinkList_Reset（） err. -1\n");
		return NULL;
	}

	tlist->slider = tlist->header.next;
	ret = tlist->slider;

	return ret;
}

//10.获取游标指针当前指向的节点
DlinkListNode* dLinkList_Current(DlinkList* list)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	DlinkListNode* ret = NULL;
	int i = 0;

	if (tlist == NULL)
	{
		printf("func dLinkList_Current（） err. -1\n");
		return NULL;
	}

	ret = tlist->slider;

	return ret;
}


//11.将游标指针后移一个，并返回移动前指向的节点
DlinkListNode* dLinkList_Next(DlinkList* list)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	DlinkListNode* ret = NULL;

	if (tlist == NULL)
	{
		printf("func dLinkList_Reset（） err. -1\n");
		return NULL;
	}

	if (tlist->slider != NULL)
	{
		ret = tlist->slider;
		tlist->slider = tlist->slider->next;
	}
	
	return ret;
}


//12.将游标指针前移一个，并返回移动前指向的节点
DlinkListNode* dLinkList_Pre(DlinkList* list)
{
	TDLinkListNode* tlist = (TDLinkListNode*)list;
	DlinkListNode* ret = NULL;

	if (tlist == NULL)
	{
		printf("func dLinkList_Reset（） err. -1\n");
		return NULL;
	}

	if (tlist->slider != NULL)
	{
		ret = tlist->slider;
		tlist->slider = tlist->slider->pre;
	}

	return ret;
}
