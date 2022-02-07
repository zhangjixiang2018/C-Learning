#include<stdio.h>
#include"linkStack.h"


typedef struct Person
{
	int age;
	char name[64];
}Person;

void test01()
{
	LinkStack* stack = NULL;
	stack = linkStack_Create();//创建栈
	if (stack == NULL)
	{
		printf("func test01() err -1\n");
		return;
	}

	Person p1, p2, p3, p4, p5;
	p1.age = 21;
	p2.age = 22;
	p3.age = 23;
	p4.age = 24;
	p5.age = 25;


	//入栈
	linkStack_Push(stack, (void*)&p1);
	linkStack_Push(stack, (void*)&p2);
	linkStack_Push(stack, (void*)&p3);
	linkStack_Push(stack, (void*)&p4);
	linkStack_Push(stack, (void*)&p5);

	printf("stack length is : %d \n", linkStack_Length(stack));

	Person* p=NULL;

	printf("获取栈顶元素\n");
	p = (Person*)linkStack_Top(stack);
	printf("%d\n", p->age);

	printf("出栈\n");
	while (linkStack_Length(stack) > 0)
	{
		p = (Person*)linkStack_Pop(stack);
		printf("%d\n", p->age);

	}

}

int main()
{
	test01();
	return 0;
}