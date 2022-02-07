#include<stdio.h>

//�ϲ�������������������������ϲ�����
//arr[left...mid]Ϊһ�����飬arr[mid+1...right]Ϊһ������
void merge(int* arr, int left, int mid, int right)
{
	int i, j, k;
	int* tmp = new int[right - left + 1];//��ʱ���飬���������������ϲ��ڸ�������
	
	i = left;
	j = mid + 1;
	k = 0;

	//����С�����˳����������������е�Ԫ�����κϲ���tmp��
	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])//�ҳ�С��������tmp��
		{
			tmp[k++] = arr[i++];
		}
		else
		{
			tmp[k++] = arr[j++];
		}
	}

	//������������ʣ�࣬����������ʣ��Ԫ�ط���tmp��
	while(i<=mid) tmp[k++] = arr[i++];
	//������������ʣ�࣬����������ʣ��Ԫ�ط���tmp��
	while(j<=right) tmp[k++] = arr[j++];

	//���ϲ�������鸴�Ƶ�ԭ���飬ʹԭ��������
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
	//���left==right��˵��������ֻ��һ��Ԫ�أ�����Ҫ������
	if (left < right)
	{
		mid = (left + right) / 2;//
		//����������������
		mergeSort(arr, left, mid);
		//���ұ������������
		mergeSort(arr, mid + 1, right);
		//�ϲ���������
		merge(arr, left, mid, right);

	}

	return arr;
}

int fundMid(int* arr, int left, int right)
{
	int ipvot = 0;
	int k = 0;
	ipvot = arr[left];//�������Ԫ�أ��趨�±�ΪleftԪ��Ϊ����Ԫ��
	
	while (true)
	{
		k = left;//�����λ�±ꡣ����Ԫ��ǰleftλ���൱�ڿ�λ���������������λ��ֵ
		//rightָ����������С��pivot��Ԫ��
		while (left < right && arr[right] >= ipvot) right--;
		//leftָ��������������pivot��Ԫ��
		while (left < right && arr[left] <= ipvot) left++;

		if (!(left < right)) break;//left��rightָ���غϣ���������

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
		mid = fundMid(arr, left, right);//�ҳ��ź���Ԫ�ص��±�
		quickSort(arr, left, mid - 1);//���ź���Ԫ����ߵ�Ԫ�ؽ�������
		quickSort(arr, mid + 1, right);//���ź���Ԫ���ұߵ�Ԫ�ؽ�������
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