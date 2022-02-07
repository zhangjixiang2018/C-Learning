#include"linkQueue.h"
#include<stdio.h>

void test01()
{
	LinkQueue* queue = NULL;
	int a[10] = { 0 };

	//创建队列
	queue = linkQueue_Create();
	if (queue == NULL)
	{
		printf("func test01() err.-1\n");
		return;
	}

	//元素进队列
	for (int i = 0; i < 10; i++)
	{
		a[i] = i * 10 + 1;
		linkQueue_Append(queue, &a[i]);
	}

	printf("queue length is : %d\n", linkQueue_Length(queue));
	printf("queue header is : %d\n", *((int *)linkQueue_Header(queue)));

	//元素出队列
	int temp = 0;
	while (linkQueue_Length(queue) > 0)
	{
		temp = *(int *)(linkQueue_Retrive(queue));
		printf("%d	", temp);
	}
	printf("\n");

	printf("queue length is : %d\n", linkQueue_Length(queue));
	//printf("queue header is : %d\n", *((int*)linkQueue_Header(queue)));

	//销毁队列
	linkQueue_Destroy(queue);
}


int main()
{
	test01();
	return 0;
}