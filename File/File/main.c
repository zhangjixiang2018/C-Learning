#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//以文本方式读取文件
void ReadFileByTXT()
{
	FILE* fid = fopen("txt_out.txt", "r");
	if (fid == NULL)
	{
		printf("打开%s失败", "txt_out.txt");
		return;
	}

	int index_arr[100] = { 0 };
	double x_pos_arr[100] = { 0.0 };
	double y_pos_arr[100] = { 0.0 };

	int mode = 1;
	printf("mode为1，按字符读入并输出；mode为2，按行读入输出；mode为3，知道数据格式，按行读入并输出\n");
	scanf("%d", &mode);
	if (mode == 1)
	{
		//按字符读入并直接输出
		char ch;  //读取的字符，判断准则为ch不等于结束符EOF（end of file）
		while(EOF != (ch = fgetc(fid)))
			printf("%c", ch);
	}
	else if (mode == 2)
	{
		char line[1024];
		memset(line, 0, 1024);
		while (!feof(fid))
		{
			fgets(line, 1024, fid);
			printf("%s\n", line); //输出
		}
	}
	else if (mode == 3)
	{
		//知道数据格式，按行读入并存储输出
		int index_tmp;
		double x_tmp, y_tmp;
		int i = 0;
		while (!feof(fid))
		{
			fscanf(fid, "%d%lf%lf\n", &index_tmp, &x_tmp, &y_tmp);
			index_arr[i] = index_tmp;
			x_pos_arr[i] = x_tmp;
			y_pos_arr[i] = y_tmp;
		}

		for (int j = 0; j < i; j++)
			printf("%04d\t%4.8lf\t%4.8lf\n", index_arr[j], x_pos_arr[j], y_pos_arr[j]);

	}
	fclose(fid);
}


//以文本方式写入文件
void WriteFileByTXT()
{
	//准备数据
	int index[50];
	double x_pos[50], y_pos[50];
	for (int i = 0; i < 50; i++)
	{
		index[i] = i;
		x_pos[i] = rand() % 1000 * 0.01;
		y_pos[i] = rand() % 2000 * 0.01;
	}
	//写出txt
	FILE* fid = fopen("txt_out.txt", "w");//以写方式打开txt_out.txt
	if (fid == NULL)
	{
		printf("写出文件失败！\n");
		return;
	}
	for (int i = 0; i < 50; i++)
	{
		fprintf(fid, "%03d\t%4.6lf\t%4.6lf\n", index[i], x_pos[i], y_pos[i]);
	}
	fclose(fid);
}


//以二进制方式写文件
void WriteFileByData()
{
	//准备数据
	double pos[200];
	for (int i = 0; i < 200; i++)
		pos[i] = i;
	//写出数据
	FILE* fid;
	fid = fopen("binary.txt", "wb");//以二进制、写方式打开文件
	if (fid == NULL)
	{
		printf("写出文件出错");
		return;
	}
	int mode = 1;
	printf("mode为1，逐个写入；mode为2，逐行写入\n");
	scanf("%d", &mode);
	if (1 == mode)
	{
		for (int i = 0; i < 200; i++)
			fwrite(&pos[i], sizeof(double), 1, fid);
	}
	else if (2 == mode)
	{
		fwrite(pos, sizeof(double), 200, fid);
	}
	fclose(fid);
}


//以二进制方式读文件
void ReadFileByData()
{
	FILE* fid;
	fid = fopen("binary.txt", "rb");
	if (fid == NULL)
	{
		printf("读取文件出错");
		return;
	}
	int mode = 1;
	printf("mode为1，知道pos有多少个；mode为2，不知道pos有多少个\n");
	scanf("%d", &mode);
	if (1 == mode)
	{
		double pos[200];
		fread(pos, sizeof(double), 200, fid);
		for (int i = 0; i < 200; i++)
			printf("%lf\n", pos[i]);
		free(pos);
	}
	else if (2 == mode)
	{
		//获取文件大小
		fseek(fid, 0, SEEK_END);
		long lSize = ftell(fid);
		rewind(fid);
		//开辟存储空间
		int num = lSize / sizeof(double);
		double* pos = (double*)malloc(sizeof(double) * num);
		if (pos == NULL)
		{
			printf("开辟空间出错");
			return;
		}
		fread(pos, sizeof(double), num, fid);
		for (int i = 0; i < num; i++)
			printf("%lf\n", pos[i]);
		free(pos);     //释放内存
	}
	fclose(fid);
}


int main()
{
	//以文本方式操作文件
	printf("******以文本方式写文件\n\n");
	WriteFileByTXT();
	printf("******以文本方式读文件\n\n");
	ReadFileByTXT();

	//以文本方式操作文件
	printf("******以二进制方式写文件\n\n");
	WriteFileByData();
	printf("******以二进制方式读文件\n\n");
	ReadFileByData();

	return 0;
}