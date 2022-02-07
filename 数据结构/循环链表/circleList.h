#pragma once

typedef void CircleList;

/*
�ýṹ���������ʲô��
�ýṹ��������ڵ㣨����ͷ�ڵ����ͨ�ڵ㣩�ĵ�һ�����ڽڵ��а����ýṹ�壬
�Ϳɽ����еĽڵ���������������ʱ����������ͼ
*/
typedef struct _tag_CircleListNode
{
	struct _tag_CircleListNode* next;
}TCircleListNode;

//����ѭ������
CircleList* circleList_Create();

//ɾ��ѭ������
void circleList_Destroy(CircleList* list);

//���ѭ������
void circleList_Clear(CircleList* list);


//��ȡѭ������ĳ���
int circleList_Length(CircleList* list);


//��ѭ������list��posλ�ò���ڵ�node
int circleList_Insert(CircleList* list, TCircleListNode* node, int pos);


//��ȡѭ������lsit��posλ�õĽڵ�
TCircleListNode* circleList_Get(CircleList* list, int pos);


//ɾ��ѭ������List��posλ�õĽڵ�
TCircleListNode* circleList_Delete(CircleList* list, int pos);


//ɾ��ѭ������list�еĽڵ�Node
TCircleListNode* circleList_DeleteNode(CircleList* list, TCircleListNode* node);


//��λƫ��ָ��
TCircleListNode* circleList_Reset(CircleList* list);


//��ȡѭ������list��ǰλ�õĽڵ�
TCircleListNode* circleList_Current(CircleList* list);


//��ƫ��ָ��ָ����һ���ڵ㣬���ص�ǰ�ڵ�
TCircleListNode* circleList_Next(CircleList* list);



