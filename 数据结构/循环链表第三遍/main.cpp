#include<stdio.h>
#include"circleLinkList.h"

typedef struct Value
{
	CircleLinkListNode node;
	int v;
};



void test01()
{

	CircleLinkList* list = NULL;
	int i = 0;

	struct Value v1, v2, v3, v4, v5, v6, v7, v8;
	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;
	v6.v = 6;
	v7.v = 7;
	v8.v = 8;


	list = circleLinkList_Create();
	if (list == NULL)
	{
		printf("func main() err,-1");
		return;
	}

	//ͷ��
	circleLinkList_Insert(list, (CircleLinkListNode*)&v1, 0);
	circleLinkList_Insert(list, (CircleLinkListNode*)&v2, 0);
	circleLinkList_Insert(list, (CircleLinkListNode*)&v3, 0);
	//β��
	circleLinkList_Insert(list, (CircleLinkListNode*)&v4, circleLinkList_Length(list));
	circleLinkList_Insert(list, (CircleLinkListNode*)&v5, circleLinkList_Length(list));
	//���Ϊ��3,2,1,4,5

	//��������ȵ�2��������Ƿ�Ϊѭ������
	for (i = 0; i < circleLinkList_Length(list) * 2; i++)
	{
		struct Value* pv = (struct Value*)circleLinkList_Get(list, i);
		if (i == circleLinkList_Length(list)) printf("\n");
		printf("%d	", pv->v);
	}
	printf("\n");


	//�м��
	circleLinkList_Insert(list, (CircleLinkListNode*)&v6, 2);
	circleLinkList_Insert(list, (CircleLinkListNode*)&v7, 5);
	//���Ϊ��3,2,6,1,4,7,5


	circleLinkList_Reset(list);//��λ�α�
	for (i = 0; i < circleLinkList_Length(list) * 2; i++)
	{
		struct Value* pv = (struct Value*)circleLinkList_Next(list);
		if (i == circleLinkList_Length(list)) printf("\n");
		printf("%d	", pv->v);
	}
	printf("\n");

	//ͷɾ
	int len = circleLinkList_Length(list);
	for (i = 0; i < len; i++)
	{
		struct Value* pv = (struct Value*)circleLinkList_Delete(list, 0);
		printf("%d	", pv->v);
	}
	printf("\n");


	circleLinkList_Destroy(list);
}

/*
Լɪ������
*/
void test02()
{
	/*
	CircleLinkList* list = NULL;
	int i = 0;

	struct Value v1, v2, v3, v4, v5, v6, v7, v8, v9;
	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;
	v6.v = 6;
	v7.v = 7;
	v8.v = 8;
	v9.v = 9;

	list = circleLinkList_Create();
	if (list == NULL)
	{
		printf("func main() err,-1");
		return;
	}

	//ͷ��
	circleLinkList_Insert(list, (CircleListNode*)&v1, circleList_Length(list));
	circleLinkList_Insert(list, (CircleListNode*)&v2, circleList_Length(list));
	circleLinkList_Insert(list, (CircleListNode*)&v3, circleList_Length(list));
	circleLinkList_Insert(list, (CircleListNode*)&v4, circleList_Length(list));
	circleLinkList_Insert(list, (CircleListNode*)&v5, circleList_Length(list));
	circleLinkList_Insert(list, (CircleListNode*)&v6, circleList_Length(list));
	circleLinkList_Insert(list, (CircleListNode*)&v7, circleList_Length(list));
	circleLinkList_Insert(list, (CircleListNode*)&v8, circleList_Length(list));
	circleLinkList_Insert(list, (CircleListNode*)&v9, circleList_Length(list));



	//��������ȵ�2��������Ƿ�Ϊѭ������
	for (i = 0; i < circleList_Length(list) * 2; i++)
	{
		struct Value* pv = (struct Value*)circleList_Get(list, i);
		if (i == circleList_Length(list)) printf("\n");
		printf("%d	", pv->v);
	}
	printf("\n");

	circleList_Reset(list);

	struct Value* pv = NULL;
	while (circleList_Length(list) != 0)
	{
		for (i = 0; i < 3; i++)
		{
			circleList_Next(list);
		}
		pv = (struct Value*)circleList_Current(list);
		printf("%d	", pv->v);
		circleList_DeleteNode(list, (CircleListNode*)pv);
	}
	printf("\n");

	*/
}

int main()
{
	test01();
	//test02();

	return 0;
}