#include"linkStack.h"
#include<stdio.h>

void test01()
{
	int a[10] = { 0 };

	LinkStack* stack = NULL;
	//创建栈
	stack = linkStack_Create();
	if (stack == NULL)
	{
		printf("func test01() err.-1\n");
		return;
	}

	//进栈
	for (int i = 0; i < 10; i++)
	{
		a[i] = i + 10 + 1;
		linkStack_Push(stack, (void*)&a[i]);
	}

	printf("栈的长度为： %d\n", linkStack_Length(stack));
	printf("栈顶元素为： %d\n", *(int*)linkStack_Top(stack));

	//出栈
	while (linkStack_Length(stack) > 0)
	{
		printf("%d	", *(int*)linkStack_Pop(stack));
	}
	printf("\n");

	printf("栈的长度为： %d\n", linkStack_Length(stack));

}


int main()
{
	test01();
	return 0;
}