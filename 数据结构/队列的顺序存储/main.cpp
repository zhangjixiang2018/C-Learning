#include"seqQueue.h"
#include<stdio.h>

void test01()
{
	SeqQueue* queue = NULL;
	int a[10] = { 0 };

	//创建容量为10的队列
	queue = seqQueue_Create(10);
	if (queue == NULL)
	{
		printf("func test01() err.-1\n");
		return;
	}

	//向队列中插入元素
	for (int i = 0; i < 10; i++)
	{
		a[i] = i * 10 + 1;
		seqQueue_Append(queue, &a[i]);
	}

	printf("队列的大小为：%d\n", seqQueue_Length(queue));
	printf("队列头部元素为：%d", *((int *)seqQueue_Header(queue)) );

	printf("获取队列中的所有元素\n");
	while (seqQueue_Length(queue) > 0)
	{
		printf("%d	", *((int*)seqQueue_Retrive(queue)) );
	}
	printf("\n");

	printf("队列的大小为：%d\n", seqQueue_Length(queue));

	printf("队列头部元素为：%d", ((int*)seqQueue_Header(queue)));

	seqQueue_Capacity(queue);
}


int main()
{
	test01();
	return 0;
}
