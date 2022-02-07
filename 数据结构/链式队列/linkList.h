#pragma once

typedef void LinkList;

typedef struct LinkListNode
{
	struct LinkListNode* next;
}LinkListNode;

LinkList* linkList_Create();


void linkList_Destroy(LinkList* list);


void linkList_Clear(LinkList* list);


int linkList_Length(LinkList* list);


int linkList_Insert(LinkList* list, LinkListNode* node, int pos);


LinkListNode* linkList_Delete(LinkList* list, int pos);


LinkListNode* linkList_Get(LinkList* list, int pos);

