#include"linkStack.h"
#include<stdio.h>

void test01()
{
	int a[10] = { 0 };

	LinkStack* stack = NULL;
	//����ջ
	stack = linkStack_Create();
	if (stack == NULL)
	{
		printf("func test01() err.-1\n");
		return;
	}

	//��ջ
	for (int i = 0; i < 10; i++)
	{
		a[i] = i + 10 + 1;
		linkStack_Push(stack, (void*)&a[i]);
	}

	printf("ջ�ĳ���Ϊ�� %d\n", linkStack_Length(stack));
	printf("ջ��Ԫ��Ϊ�� %d\n", *(int*)linkStack_Top(stack));

	//��ջ
	while (linkStack_Length(stack) > 0)
	{
		printf("%d	", *(int*)linkStack_Pop(stack));
	}
	printf("\n");

	printf("ջ�ĳ���Ϊ�� %d\n", linkStack_Length(stack));

}


int main()
{
	test01();
	return 0;
}