#include<stdio.h>

//合并函数，将左右两个有序数组合并起来
//arr[left...mid]为一个数组，arr[mid+1...right]为一个数组
void merge(int* arr, int left, int mid, int right)
{
	int i, j, k;
	int* tmp = new int[right - left + 1];//临时数组，将左数组和右数组合并在该数组中
	
	i = left;
	j = mid + 1;
	k = 0;

	//按从小到大的顺序将左数组和右数组中的元素依次合并到tmp中
	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])//找出小的数放入tmp中
		{
			tmp[k++] = arr[i++];
		}
		else
		{
			tmp[k++] = arr[j++];
		}
	}

	//若左数组中有剩余，则将左数组中剩余元素放入tmp中
	while(i<=mid) tmp[k++] = arr[i++];
	//若右数组中有剩余，则将右数组中剩余元素放入tmp中
	while(j<=right) tmp[k++] = arr[j++];

	//将合并后的数组复制到原数组，使原数组有序
	j = left;
	for (i = 0; i < k; i++)
	{
		arr[j++] = tmp[i];
	}
	delete[] tmp;
}


int* mergeSort(int* arr, int left, int right)
{
	int mid = 0;
	//如果left==right，说明数组中只有一个元素，不需要再排序
	if (left < right)
	{
		mid = (left + right) / 2;//
		//对左边数组进行排序
		mergeSort(arr, left, mid);
		//对右边数组进行排序
		mergeSort(arr, mid + 1, right);
		//合并左右数组
		merge(arr, left, mid, right);

	}

	return arr;
}

int fundMid(int* arr, int left, int right)
{
	int ipvot = 0;
	int k = 0;
	ipvot = arr[left];//缓存待排元素，设定下标为left元素为待排元素
	
	while (true)
	{
		k = left;//缓存空位下标。搜索元素前left位置相当于空位，搜索后往这个空位填值
		//right指针向左搜索小于pivot的元素
		while (left < right && arr[right] >= ipvot) right--;
		//left指针向右搜索大于pivot的元素
		while (left < right && arr[left] <= ipvot) left++;

		if (!(left < right)) break;//left、right指针重合，结束搜索

		arr[k] = arr[right];
		arr[right] = arr[left];
	}

	arr[k] = arr[left];
	arr[left] = ipvot;

	return left;
}

void quickSort(int* arr, int left, int right)
{
	int mid = 0;

	if (left < right)
	{
		mid = fundMid(arr, left, right);//找出排好序元素的下标
		quickSort(arr, left, mid - 1);//对排好序元素左边的元素进行排序
		quickSort(arr, mid + 1, right);//对排好序元素右边的元素进行排序
	}

	return;
}



int main()
{
	int arr[] = { 4,5,2,8,7,9,3,6,0,1};

	//int arr[] = { 2,3,1,4,5};

	int len = sizeof(arr) / sizeof(int);
	printf("len = %d\n", len);

	for (int i = 0; i < len; i++)
	{
		printf("%d	", arr[i]);
	}
	printf("\n");


	//mergeSort(arr, 0, len-1);
	quickSort(arr, 0, len - 1);

	for (int i = 0; i < len; i++)
	{
		printf("%d	", arr[i]);
	}


	printf("\n");

	return 0;
}