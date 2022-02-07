#include<stdio.h>

//选择排序，从小到大排
void selectionSort(int* arr, int len)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int k = 0;

	for (i = 0; i < len; i++)
	{
		k = i;//假设当前下标对应的元素最小
		for (j = i + 1; j < len; j++)
		{   //遍历数组，找出最小元素对应的下标保存在k中
			if (arr[j] < arr[k])
			{
				k = j;
			}
		}
		//将最小元素依次放到数组左边
		if (k != i)
		{
			tmp = arr[k];
			arr[k] = arr[i];
			arr[i] = tmp;
		}
	}
}

//插入排序
void insertSort(int* arr, int len)
{
	int i = 0, j = 0;
	int tmp = 0;
	int k = 0;

	for (i = 0; i < len; i++)
	{
		k = i;//待插入位置
		tmp = arr[k];

		for (j = i - 1; (j >= 0) && (arr[j] > tmp); j--)
		{
			//tmp = arr[i];
			arr[j + 1] = arr[j];//元素后移
			k = j;//k需要插入的位置
		}

		arr[k] = tmp;//元素插入
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