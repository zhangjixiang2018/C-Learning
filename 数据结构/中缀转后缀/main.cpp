#include"linkStack.h"
#include<stdio.h>


//函数功能：返回操作符operator1的优先级，加减返回优先级为1，乘除优先级为2
int priority(char operator1)
{
	int ret = 0;
	if (operator1 == '+' || operator1 == '-')
	{
		ret = 1;
	}
	if (operator1 == '*' || operator1 == '/')
	{
		ret = 2;
	}
	
	return ret;
}

//函数功能：判断字符是否为数字
//返回值：字符为数字返回为true，否则返回为false
bool isNumber(char c)
{
	return c >= '0' && c <= '9';
}

//函数功能：判断字符是否为运算符
//返回值：字符为运算符返回为true，否则返回为false
bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

//函数功能：根据运算符求值
//参数1：右操作数
//参数2：左操作数
//参数3：运算符
//返回值：运算结果
int express(int rigth, int left, char op)
{
	int ret = 0;
	switch (op)
	{
	case '+':
		ret =  left + rigth;
		break;

	case '-':
		ret =  left - rigth;
		break;

	case '*':
		ret =  left * rigth;
		break;

	case '/':
		ret =  left / rigth;
		break;

	default:
		break;
	}
	
	return ret;
}

int value(char c)
{
	return (c - '0');
}

//函数功能：后缀表达式求值
int compute(char* suffixStr)
{
	LinkStack* stack = NULL;
	int i = 0;
	int ret = 0;

	stack = linkStack_Create();
	if (stack == NULL)
	{
		printf("func transform() err -1\n");
		return ret;
	}

	while (suffixStr[i] != '\0')
	{
		//如果当前字符为数字则进栈
		if (isNumber(suffixStr[i]))
		{
			linkStack_Push(stack, (void*)value(suffixStr[i]));
		}
		else if (isOperator(suffixStr[i]))
		{
			int right = (int)linkStack_Pop(stack);//栈中弹出右操作数
			int left = (int)linkStack_Pop(stack);//栈中弹出左操作符
			int result = express(right, left, suffixStr[i]);//根据符号进行运算
			linkStack_Push(stack, (void*)result);//将运算结果压入栈中
		}
		else
		{
			printf("Invalid expression");//无效的表达式
			break;
		}

		i++;
	}

	ret = (int)linkStack_Pop(stack);

	linkStack_Destroy(stack);

	return ret;
}

//函数功能：将中缀表达式转化为后缀表达式
//参数1：中缀表达式
//参数2：转化后的后缀表达式
//返回值：
void transform(const char* str,char* suffixStr)
{
	LinkStack* stack = NULL;
	char temp = 0;
	int i = 0;

	stack = linkStack_Create();
	if (stack == NULL)
	{
		printf("func transform() err -1\n");
		return;
	}


	while (*str != '\0')
	{
		temp = *str;
		if (temp >= '0' && temp <= '9')//字符为数字直接输出
		{
			printf("%c ", temp);
			suffixStr[i++] = temp;
		}
		if (temp == '(')//
		{
			linkStack_Push(stack, (void*)str);
		}
		if (temp == '+' || temp == '-' || temp == '*' || temp == '/')//字符为符号,根据优先级进行不同操作
		{
			if (linkStack_Length(stack) == 0)//如果栈为空，运算符直接进栈
			{
				//将当前字符进栈
				linkStack_Push(stack, (void*)str);
				str++;
				continue;
			}

			//将优先级大于或等于当前的运算符的栈顶元素弹出
			while( priority(temp) <= priority(*(char*)linkStack_Top(stack)))
			{
				char c = *(char*)linkStack_Pop(stack);//弹出栈顶元素
				//输出栈顶元素
				printf("%c ", c);
				suffixStr[i++] = c;
			}
				
			//将当前字符进栈
			linkStack_Push(stack, (void*)str);

		}
		if (temp == ')')//右括号：将栈顶符号弹出并输出，直到匹配到左括号（_左括号也弹出）
		{
			char c = *(char*)linkStack_Pop(stack);//弹出栈顶元素
			
			while (c != '(')
			{
				//输出栈顶元素
				printf("%c ", c);
				suffixStr[i++] = c;
				c = *(char*)linkStack_Pop(stack);//弹出栈顶元素
			}
			
		}
		str++;
	}

	char c = 0;//弹出栈顶元素
	//遍历结束：将栈中所有元素弹出并输出
	while (linkStack_Length(stack) > 0)
	{
		c = *(char*)linkStack_Pop(stack);//弹出栈顶元素
		//输出栈顶元素
		printf("%c ", c);
		suffixStr[i++] = c;
	}
	printf("\n");
}

int main()
{
	char suffixStr[128] = {0};

	transform("8+(3-1)*5", suffixStr);

	printf("%s\n", suffixStr);


	int ret = compute(suffixStr);
	printf("result:%d\n", ret);
	return 0;
}