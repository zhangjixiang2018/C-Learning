#include"linkStack.h"
#include<stdio.h>


//�������ܣ����ز�����operator1�����ȼ����Ӽ��������ȼ�Ϊ1���˳����ȼ�Ϊ2
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

//�������ܣ��ж��ַ��Ƿ�Ϊ����
//����ֵ���ַ�Ϊ���ַ���Ϊtrue�����򷵻�Ϊfalse
bool isNumber(char c)
{
	return c >= '0' && c <= '9';
}

//�������ܣ��ж��ַ��Ƿ�Ϊ�����
//����ֵ���ַ�Ϊ���������Ϊtrue�����򷵻�Ϊfalse
bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

//�������ܣ������������ֵ
//����1���Ҳ�����
//����2���������
//����3�������
//����ֵ��������
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

//�������ܣ���׺���ʽ��ֵ
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
		//�����ǰ�ַ�Ϊ�������ջ
		if (isNumber(suffixStr[i]))
		{
			linkStack_Push(stack, (void*)value(suffixStr[i]));
		}
		else if (isOperator(suffixStr[i]))
		{
			int right = (int)linkStack_Pop(stack);//ջ�е����Ҳ�����
			int left = (int)linkStack_Pop(stack);//ջ�е����������
			int result = express(right, left, suffixStr[i]);//���ݷ��Ž�������
			linkStack_Push(stack, (void*)result);//��������ѹ��ջ��
		}
		else
		{
			printf("Invalid expression");//��Ч�ı��ʽ
			break;
		}

		i++;
	}

	ret = (int)linkStack_Pop(stack);

	linkStack_Destroy(stack);

	return ret;
}

//�������ܣ�����׺���ʽת��Ϊ��׺���ʽ
//����1����׺���ʽ
//����2��ת����ĺ�׺���ʽ
//����ֵ��
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
		if (temp >= '0' && temp <= '9')//�ַ�Ϊ����ֱ�����
		{
			printf("%c ", temp);
			suffixStr[i++] = temp;
		}
		if (temp == '(')//
		{
			linkStack_Push(stack, (void*)str);
		}
		if (temp == '+' || temp == '-' || temp == '*' || temp == '/')//�ַ�Ϊ����,�������ȼ����в�ͬ����
		{
			if (linkStack_Length(stack) == 0)//���ջΪ�գ������ֱ�ӽ�ջ
			{
				//����ǰ�ַ���ջ
				linkStack_Push(stack, (void*)str);
				str++;
				continue;
			}

			//�����ȼ����ڻ���ڵ�ǰ���������ջ��Ԫ�ص���
			while( priority(temp) <= priority(*(char*)linkStack_Top(stack)))
			{
				char c = *(char*)linkStack_Pop(stack);//����ջ��Ԫ��
				//���ջ��Ԫ��
				printf("%c ", c);
				suffixStr[i++] = c;
			}
				
			//����ǰ�ַ���ջ
			linkStack_Push(stack, (void*)str);

		}
		if (temp == ')')//�����ţ���ջ�����ŵ����������ֱ��ƥ�䵽�����ţ�_������Ҳ������
		{
			char c = *(char*)linkStack_Pop(stack);//����ջ��Ԫ��
			
			while (c != '(')
			{
				//���ջ��Ԫ��
				printf("%c ", c);
				suffixStr[i++] = c;
				c = *(char*)linkStack_Pop(stack);//����ջ��Ԫ��
			}
			
		}
		str++;
	}

	char c = 0;//����ջ��Ԫ��
	//������������ջ������Ԫ�ص��������
	while (linkStack_Length(stack) > 0)
	{
		c = *(char*)linkStack_Pop(stack);//����ջ��Ԫ��
		//���ջ��Ԫ��
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