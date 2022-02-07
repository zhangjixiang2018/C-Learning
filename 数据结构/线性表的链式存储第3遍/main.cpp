#include<stdio.h>

#include"linkList.h"


typedef struct Teacher
{
	LinkListNode node;
	int age;
	char name[64];
}Teacher;


void showListInfo(LinkList* list)
{
	Teacher*	tmp = NULL;
	printf("list length: %d\n", linkList_Length(list));

	for (int i = 0; i < linkList_Length(list); i++)
	{
		tmp = (Teacher*)linkList_Get(list, i);
		printf("%d	", tmp->age);
	}
	printf("\n");
}
void test01()
{
	LinkList* list;

	list = linkList_Create();

	if (list == NULL)
	{
		printf("func test01() err. -1\n");
		return;
	}

	Teacher t1, t2, t3, t4, t5, t6;
	t1.age = 21;
	t2.age = 22;
	t3.age = 23;
	t4.age = 24;
	t5.age = 25;
	t6.age = 26;


	//头插
	linkList_Insert(list, (LinkListNode*)&t1, 0);
	linkList_Insert(list, (LinkListNode*)&t2, 0);
	linkList_Insert(list, (LinkListNode*)&t3, 0);
	//尾插
	linkList_Insert(list, (LinkListNode*)&t4, linkList_Length(list));
	linkList_Insert(list, (LinkListNode*)&t5, linkList_Length(list));
	//中间插
	linkList_Insert(list, (LinkListNode*)&t6, 2);
	//结果为：3,2,6,1,4,5

	showListInfo(list);

	Teacher* t = NULL;
	//头删
	t = (Teacher*)linkList_Delete(list, 0);
	printf("%d\n", t->age);
	showListInfo(list);

	//尾删
	t = (Teacher*)linkList_Delete(list, linkList_Length(list)-1);
	printf("%d\n", t->age);

	//
	while (linkList_Length(list) != 0)
	{
		//头删
		t = (Teacher*)linkList_Delete(list, 0);
		printf("%d	", t->age);
	}
	printf("\n");

	showListInfo(list);

	linkList_Destroy(list);
}



int main()
{
	test01();
	return 0;
}