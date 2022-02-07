# 文件读写
 
 ## 1.概述
 该源码包含以文本方式和二进制方式读写文件。
 
 - 文本方式：每一个字节存放的是一个ASCII码，代表一个字符。
 
 - 二进制方式：将内存中的数据按照其在内存中的存储形式原样存放在磁盘上。
 
 ## 2. 以文本方式读取文件
使用fprintf()函数向文件中写入如下图内容

![图片](https://user-images.githubusercontent.com/44158103/152794130-5a287c14-268d-4071-8010-ba2637e02d4a.png)

代码

``` c
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
```
