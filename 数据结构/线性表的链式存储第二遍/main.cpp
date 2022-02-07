#include"linkList.h"
#include<stdio.h>


typedef struct Teacher
{
	LinkListNode node;
	int age;
	char name[64];
}Teacher;

int main()
{
	LinkList* list = NULL;
	Teacher t1, t2, t3, t4, t5;
	t1.age = 21;
	t2.age = 22;
	t3.age = 23;
	t4.age = 24;
	t5.age = 25;

	list = linkList_Create();
	if (list == NULL)
	{
		printf("func main() err,-1");
		return -1;
	}

	//头插
	linkList_Insert(list, (LinkListNode*)&t1, 0);
	linkList_Insert(list, (LinkListNode*)&t2, 0);
	linkList_Insert(list, (LinkListNode*)&t3, 0);
	//尾插
	linkList_Insert(list, (LinkListNode*)&t4, linkList_Length(list));
	linkList_Insert(list, (LinkListNode*)&t5, linkList_Length(list));
	//结果为：23,22,21,24,25

	int len = linkList_Length(list);
	Teacher* tmp=NULL;
	for (int i = 0; i < len; i++)
	{
		tmp = (Teacher*)linkList_Get(list,i);
		printf("%d	", tmp->age);
	}
	printf("\n");

	//
	while (linkList_Length(list) != 0)
	{
		//头删
		tmp = (Teacher*)linkList_Delete(list, 0);
		printf("%d	", tmp->age);

	}
	//结果为：23,22,21,24,25


	printf("\n");


	linkList_Destroy(list);
	return 0;
}