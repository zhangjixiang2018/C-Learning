#include"seqStack.h"
#include<stdio.h>

void test01()
{
	SeqStack *stack = NULL;
	stack = seqStack_Create(10);
	int tmp[10] = {0};

	if (stack == NULL)
	{
		printf("func test01()  err. -1 \n");
		return;
	}
	
	for (int i = 0; i < 8; i++)
	{
		tmp[i] = i;
		seqStack_Push(stack, &tmp[i]);
	}
	
	printf("stack length : %d\n", seqStack_Length(stack));
	printf("stack capacity : %d\n", seqStack_Capacity(stack));

	int a = *(int*)(seqStack_Top(stack));
	printf("top is %d\n", a);


	while (seqStack_Length(stack))
	{
		a = *(int *)(seqStack_Pop(stack));
		printf("%d	", a);
	}
	printf("\n");

	printf("stack capacity : %d\n", seqStack_Capacity(stack));

	int *b = (int*)(seqStack_Top(stack));
	if(b!=NULL)
	printf("top is %d\n", *b);

	seqStack_Destroy(stack);
}

int main()
{
	test01();

	return 0;
}