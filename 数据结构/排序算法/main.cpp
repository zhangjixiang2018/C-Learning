#include<stdio.h>

//ѡ�����򣬴�С������
void selectionSort(int* arr, int len)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int k = 0;

	for (i = 0; i < len; i++)
	{
		k = i;//���赱ǰ�±��Ӧ��Ԫ����С
		for (j = i + 1; j < len; j++)
		{   //�������飬�ҳ���СԪ�ض�Ӧ���±걣����k��
			if (arr[j] < arr[k])
			{
				k = j;
			}
		}
		//����СԪ�����ηŵ��������
		if (k != i)
		{
			tmp = arr[k];
			arr[k] = arr[i];
			arr[i] = tmp;
		}
	}
}

//��������
void insertSort(int* arr, int len)
{
	int i = 0, j = 0;
	int tmp = 0;
	int k = 0;

	for (i = 0; i < len; i++)
	{
		k = i;//������λ��
		tmp = arr[k];

		for (j = i - 1; (j >= 0) && (arr[j] > tmp); j--)
		{
			//tmp = arr[i];
			arr[j + 1] = arr[j];//Ԫ�غ���
			k = j;//k��Ҫ�����λ��
		}

		arr[k] = tmp;//Ԫ�ز���
	}
}

void printArr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d	", arr[i]);
	}
}
int main()
{
	int a[5] = { 3,6,2,4,5 };

	//selectionSort(a, 5);
	insertSort(a, 5);
	printArr(a, 5);
	return 0;
}