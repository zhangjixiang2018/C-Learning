#include"dlinkList.h"
#include<stdio.h>

typedef struct Value
{
	DlinkListNode node;
	int v;
}Value;

void test01()
{

	DlinkList* list = NULL;
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

	//头插
	dLinkList_Insert(list, (DlinkListNode*)&v1, 0);
	dLinkList_Insert(list, (DlinkListNode*)&v2, 0);
	dLinkList_Insert(list, (DlinkListNode*)&v3, 0);
	//尾插
	dLinkList_Insert(list, (DlinkListNode*)&v4, dLinkList_Length(list));
	dLinkList_Insert(list, (DlinkListNode*)&v5, dLinkList_Length(list));
	//结果为：3,2,1,4,5

	struct Value* pv ;
#if 0
	//输出链表长度的2倍，检测是否为循环链表
	for (i = 0; i < dLinkList_Length(list); i++)
	{
		struct Value* pv = (struct Value*)dLinkList_Get(list, i);
		printf("%d	", pv->v);
	}
	printf("\n");

	//头删
	 pv = (struct Value*)dLinkList_Delete(list, 0);
	printf("%d	\n", pv->v);
	for (i = 0; i < dLinkList_Length(list); i++)
	{
		struct Value* pv = (struct Value*)dLinkList_Get(list, i);
		printf("%d	", pv->v);
	}
	printf("\n");


	printf("尾删\n");
	//pv = NULL;
	pv = (struct Value*)dLinkList_Delete(list, dLinkList_Length(list)-1);

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
	dLinkList_Reset(list);//置位游标指针
	int len = dLinkList_Length(list);
	for (int i = 0; i < len-1; i++)
	{	//通过游标指针遍历,next方式
		pv = (struct Value*)dLinkList_Next(list);
		printf("%d	", pv->v);
	}
	printf("\n");

	len = dLinkList_Length(list);
	for (int i = 0; i < len; i++)
	{	//通过游标指针遍历，指针前移方式
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