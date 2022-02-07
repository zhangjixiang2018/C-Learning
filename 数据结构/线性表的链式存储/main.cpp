#include"linkList.h"
#include<stdio.h>


//链表算法和具体业务节点分离
typedef struct Teacher
{
	LinkListNode node;
	int age;
	char name[64];
}Teacher;

int main()
{
	int i = 0;
	LinkList* list = NULL;
	//LinkListNode* node = NULL;
	Teacher* teacherNode;
	Teacher t1, t2, t3, t4,t5;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;


	//创建链式线性表
	list = linkList_Create();

	if (list == NULL)
	{
		return -1;
	}

	//在链式线性表list的pos位置插入节点Node
	linkList_Insert(list,(LinkListNode*) &t1, 0);
	linkList_Insert(list, (LinkListNode*)&t2, 0);
	linkList_Insert(list, (LinkListNode*)&t3, 0);
	linkList_Insert(list, (LinkListNode*)&t4, 0);
	linkList_Insert(list, (LinkListNode*)&t5, 0);

	//遍历
	for (i = 0; i < linkList_Length(list); i++)
	{
		teacherNode = (Teacher*)linkList_Get(list, 0);
		if (teacherNode != NULL)
		{
			printf("teacher age : %d	", teacherNode->age);
		}
	}
	printf("\n");

	linkList_Delete(list, linkList_Length(list));

	while (linkList_Length(list) > 0)
	{
		teacherNode = (Teacher*)linkList_Delete(list, 0);
		if (teacherNode != NULL)
		{
			printf("teacher age : %d	", teacherNode->age);
		}
	}
	printf("\n");

	linkList_Destroy(list);

	return 0;
}