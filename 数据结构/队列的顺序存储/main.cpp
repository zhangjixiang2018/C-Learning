#include"seqQueue.h"
#include<stdio.h>

void test01()
{
	SeqQueue* queue = NULL;
	int a[10] = { 0 };

	//��������Ϊ10�Ķ���
	queue = seqQueue_Create(10);
	if (queue == NULL)
	{
		printf("func test01() err.-1\n");
		return;
	}

	//������в���Ԫ��
	for (int i = 0; i < 10; i++)
	{
		a[i] = i * 10 + 1;
		seqQueue_Append(queue, &a[i]);
	}

	printf("���еĴ�СΪ��%d\n", seqQueue_Length(queue));
	printf("����ͷ��Ԫ��Ϊ��%d", *((int *)seqQueue_Header(queue)) );

	printf("��ȡ�����е�����Ԫ��\n");
	while (seqQueue_Length(queue) > 0)
	{
		printf("%d	", *((int*)seqQueue_Retrive(queue)) );
	}
	printf("\n");

	printf("���еĴ�СΪ��%d\n", seqQueue_Length(queue));

	printf("����ͷ��Ԫ��Ϊ��%d", ((int*)seqQueue_Header(queue)));

	seqQueue_Capacity(queue);
}


int main()
{
	test01();
	return 0;
}
