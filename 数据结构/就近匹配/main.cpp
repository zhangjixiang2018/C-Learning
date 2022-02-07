#include"linkStack.h"
#include<stdio.h>

int isLeft(char c)
{
	int ret = 0;

	switch (c)
	{
	case '(':
	case '{':
	case '<':
	case '[':
	case '\'':
	case '\"':

		ret = 1;
		break;
	default:
		break;
	}
	return ret;
}

int isRight(char c)
{
	int ret = 0;

	switch (c)
	{
	case ')':
	case '}':
	case '>':
	case ']':
	case '\'':
	case '\"':

		ret = 1;
		break;
	default:
		break;
	}
	return ret;
}


int match(char left, char right)
{
	int ret = 0;

	switch (left)
	{
	case '(':
		if (right == ')')
		{
			ret = 1;
		}
		break;

	case '{':
		if (right == '}')
		{
			ret = 1;
		}
		break;

	case '<':
		if (right == '>')
		{
			ret = 1;
		}
		break;

	case '[':
		if (right == ']')
		{
			ret = 1;
		}
		break;
		
	default:
		break;
	}
	return ret;
}
void scanner(const char* code)
{
	LinkStack* stack = linkStack_Create();
	int i = 0;

	if (stack == NULL)
	{
		printf("func scanner() err. -1\n");
		return;
	}

	while(code[i] != '\0')
	{
		if (isLeft(code[i]))
		{
			linkStack_Push(stack, (void*)&code[i]);
		}

		if (isRight(code[i]))
		{
			char* tmp = (char*)linkStack_Pop(stack);//µ¯³öÕ»¶¥ÔªËØ

			if (tmp != NULL)
			{
				if (!match(*tmp, code[i]))
				{
					//Æ¥ÅäÊ§°Ü£¬¼´×óÖµºÍÓÒÖµ²»Æ¥Åä
					printf("%c does not match£¡\n",code[i]);
					return;
				}
			}
			else
			{
				printf("func scanner() err.-1\n");
				return;
			}
		}
		i++;
	}

	if (linkStack_Length(stack) != 0)
	{
		printf("the code is err\n");
	}
	else
	{
		printf("the code no problem\n");
	}
}


int main()
{
	const char* code = "#include<stdio.h> int main(){int a[4][4]; int(*p)[4]; p=a[0];return0;}";
	scanner(code);//É¨Ãè×Ö·û´®
	return 0;
}
