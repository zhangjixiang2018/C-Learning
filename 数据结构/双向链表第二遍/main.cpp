#include"dlinkList.h"
#include<stdio.h>

typedef struct Value
{
	DLinkListNode node;
	int v;
}Value;

void test01()
{

	DLinkList* list = NULL;
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


	list = dLinkList_Create();
	if (list == NULL)
	{
		printf("func main() err,-1");
		return;
	}

	//ͷ��
	dLinkList_Insert(list, (DLinkListNode*)&v1, 0);
	dLinkList_Insert(list, (DLinkListNode*)&v2, 0);
	dLinkList_Insert(list, (DLinkListNode*)&v3, 0);
	//β��
	dLinkList_Insert(list, (DLinkListNode*)&v4, dLinkList_Length(list));
	dLinkList_Insert(list, (DLinkListNode*)&v5, dLinkList_Length(list));
	//���Ϊ��3,2,1,4,5

	struct Value* pv;
#if 1
	
	for (i = 0; i < dLinkList_Length(list); i++)
	{
		struct Value* pv = (struct Value*)dLinkList_Get(list, i);
		printf("%d	", pv->v);
	}
	printf("\n");

	//ͷɾ
	pv = (struct Value*)dLinkList_Delete(list, 0);
	printf("%d	\n", pv->v);
	for (i = 0; i < dLinkList_Length(list); i++)
	{
		struct Value* pv = (struct Value*)dLinkList_Get(list, i);
		printf("%d	", pv->v);
	}
	printf("\n");


	printf("βɾ\n");
	//pv = NULL;
	pv = (struct Value*)dLinkList_Delete(list, dLinkList_Length(list) - 1);

	printf("%d	\n", pv->v);
	for (i = 0; i < dLinkList_Length(list); i++)
	{
		struct Value* pv = (struct Value*)dLinkList_Get(list, i);
		printf("%d	", pv->v);
	}
	printf("\n");
#endif

	for (i = 0; i < dLinkList_Length(list); i++)
	{
		struct Value* pv = (struct Value*)dLinkList_Get(list, i);
		printf("%d	", pv->v);
	}
	printf("\n");


	//
	dLinkList_Reset(list);//��λ�α�ָ��
	int len = dLinkList_Length(list);
	for (int i = 0; i < len - 1; i++)
	{	//ͨ���α�ָ�����,next��ʽ
		pv = (struct Value*)dLinkList_Next(list);
		printf("%d	", pv->v);
	}
	printf("\n");

	len = dLinkList_Length(list);
	for (int i = 0; i < len; i++)
	{	//ͨ���α�ָ�������ָ��ǰ�Ʒ�ʽ
		pv = (struct Value*)dLinkList_Pre(list);
		printf("%d	", pv->v);
	}
	dLinkList_Destroy(list);

}

int main()
{
	test01();
	return 0;
}