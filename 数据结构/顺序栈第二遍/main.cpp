#include"seqStack.h"
#include<stdio.h>

typedef struct Person
{
	int age;
	char name[64];
}Person;

void test0()
{
	SeqStack* stack = NULL;

	Person p1, p2, p3, p4, p5;
	p1.age = 21;
	p2.age = 22;
	p3.age = 23;
	p4.age = 24;
	p5.age = 25;

	stack = seqStack_Create(10);
	if (stack == NULL)
	{
		printf("func test01() err.-1\n");
		return;
	}

	//进栈
	seqStack_Push(stack, &p1);
	seqStack_Push(stack, &p2);
	seqStack_Push(stack, &p3);
	seqStack_Push(stack, &p4);
	seqStack_Push(stack, &p5);

	printf("stack length : %d\n", seqStack_Length(stack));
	printf("stack capacity : %d\n", seqStack_Capacity(stack));

	//获取栈顶元素
	Person* p = NULL;
	p = (Person*)(seqStack_Top(stack));
	printf("person->age %d\n", p->age);

	//出栈
	while (seqStack_Length(stack))
	{
		p = (Person*)(seqStack_Pop(stack));
		printf("%d	", p->age);
	}
	printf("\n");

	printf("stack capacity : %d\n", seqStack_Capacity(stack));

	p = (Person*)(seqStack_Pop(stack));
	if (p != NULL)
		printf("%d	", p->age);

	seqStack_Destroy(stack);
}


int main()
{
	test0();
	return 0;
}