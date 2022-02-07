#pragma once

typedef void CircleList;

typedef struct CircleListNode
{
	struct CircleListNode* next;
}CircleListNode;

//1.����ѭ������
CircleList* circleList_Create();

//2.ɾ��ѭ������
void circleList_Destroy(CircleList* list);

//3.���ѭ������
void circleList_Clear(CircleList* list);


//4.��ȡѭ������ĳ���
int circleList_Length(CircleList* list);


//5.��ѭ������list�е�posλ�ò���ڵ�node
int circleList_Insert(CircleList* list, CircleListNode* node, int pos);


//6.��ȡѭ������list�е�posλ�õĽڵ�
CircleListNode* circleList_Get(CircleList* list, int pos);


//7.ɾ��ѭ������list�е�posλ�õĽڵ㣬�����ظýڵ�
CircleListNode* circleList_Delete(CircleList* list, int pos);


//8.ɾ��ѭ������list�е�node�ڵ㣬�����ظýڵ㣬�α�ָ��ָ����һ���ڵ�
CircleListNode* circleList_DeleteNode(CircleList* list, CircleListNode* node);


//9.��ȡѭ������list��ǰλ�õĽڵ�
CircleListNode* circleList_Current(CircleList* list);


//10.���α�ָ����ƣ��������ƶ�ǰ�Ľڵ�
CircleListNode* circleList_Next(CircleList* list);


//11.�����α�ָ��,�����������α�ָ����α�ָ��ָ��Ľڵ�
CircleListNode* circleList_Reset(CircleList* list);
