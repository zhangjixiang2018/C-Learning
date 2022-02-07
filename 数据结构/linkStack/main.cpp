#include"linkStack.h"
#include<stdio.h>


void showStackInfo(LinkStack* stack)
{
	int tmp = 0;

	printf("stack len: %d\n", linkStack_Length(stack));

	//����ջ
	for (int i = 0; i < linkStack_Length(stack); i++)
	{
		tmp = *((int *)linkStack_Top(stack));
		printf("%d	", tmp);
	}

	printf("\n");
}

void test01()
{
	int a[10] = { 0 };
	int tmp = 0;

	LinkStack* stack = NULL;

	stack = linkStack_Create();
	if (stack == NULL)
	{
		printf("func test01() err.-1\n");
		return;
	}

	//��ջ
	for (int i = 0; i < 5; i++)
	{
		a[i] = i + 10;
		linkStack_Push(stack, &a[i]);
	}

	//
	showStackInfo(stack);

	while (linkStack_Length(stack) > 0)
	{
		tmp = *((int*)linkStack_Pop(stack));
		printf("%d	", tmp);
	}
	printf("\n");
}

int main()
{
	test01();
	return 0;
}