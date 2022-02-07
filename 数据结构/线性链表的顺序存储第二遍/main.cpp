#include"seqList.h"
#include<stdio.h>

typedef struct Teacher
{
	int age;
	char name[64];
}Teacher;

int main()
{
	SeqList* list = NULL;

	Teacher t1, t2, t3, t4, t5;
	t1.age = 21;
	t2.age = 22;
	t3.age = 23;
	t4.age = 24;
	t5.age = 25;


	list = seqList_Create(10);//创建容量为10的顺序链表
	if (list == NULL)
	{
		printf("func main() err,create list fail. -1\n");
		return -1;
	}

	//头插
	seqList_Insert(list, (SeqListNode*)&t1, 0);
	seqList_Insert(list, (SeqListNode*)&t2, 0);
	seqList_Insert(list, (SeqListNode*)&t3, 0);
	//尾插
	seqList_Insert(list, (SeqListNode*)&t4, seqList_Length(list));
	seqList_Insert(list, (SeqListNode*)&t5, seqList_Length(list));
	//结果为：23,22,21,24,25

	
	int len = seqList_Length(list);
	Teacher* tmpTeacher = NULL;
	//遍历
	for (int i = 0; i < len; i++)
	{
		tmpTeacher = (Teacher*)seqList_Get(list, i);
		printf("%d	", tmpTeacher->age);
	}
	printf("\n");

	printf("list length is   %d\n", seqList_Length(list));
	printf("list capacity is   %d\n", seqList_Capacity(list));

	//删除节点
	while (seqList_Length(list) != 0)
	{
		//头删
		tmpTeacher = (Teacher*)seqList_Delete(list, 0);
		printf("%d	", tmpTeacher->age);
	}
	printf("\n");

	
	//复位链表
	seqList_Clear(list);
	printf("list length is   %d\n", seqList_Length(list));
	printf("list capacity is   %d\n", seqList_Capacity(list));

	seqList_Insert(list, (SeqListNode*)&t1, 0);
	seqList_Insert(list, (SeqListNode*)&t2, 0);
	seqList_Insert(list, (SeqListNode*)&t3, 0);
	seqList_Insert(list, (SeqListNode*)&t1, 0);
	seqList_Insert(list, (SeqListNode*)&t2, 0);
	seqList_Insert(list, (SeqListNode*)&t3, 0);
	seqList_Insert(list, (SeqListNode*)&t1, 0);
	seqList_Insert(list, (SeqListNode*)&t2, 0);
	seqList_Insert(list, (SeqListNode*)&t3, 0);
	seqList_Insert(list, (SeqListNode*)&t1, 0);
	seqList_Insert(list, (SeqListNode*)&t2, 0);
	seqList_Insert(list, (SeqListNode*)&t3, 0);

	seqList_Destroy(list);
	return 0;
}