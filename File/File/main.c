#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//���ı���ʽ��ȡ�ļ�
void ReadFileByTXT()
{
	FILE* fid = fopen("txt_out.txt", "r");
	if (fid == NULL)
	{
		printf("��%sʧ��", "txt_out.txt");
		return;
	}

	int index_arr[100] = { 0 };
	double x_pos_arr[100] = { 0.0 };
	double y_pos_arr[100] = { 0.0 };

	int mode = 1;
	printf("modeΪ1�����ַ����벢�����modeΪ2�����ж��������modeΪ3��֪�����ݸ�ʽ�����ж��벢���\n");
	scanf("%d", &mode);
	if (mode == 1)
	{
		//���ַ����벢ֱ�����
		char ch;  //��ȡ���ַ����ж�׼��Ϊch�����ڽ�����EOF��end of file��
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
			printf("%s\n", line); //���
		}
	}
	else if (mode == 3)
	{
		//֪�����ݸ�ʽ�����ж��벢�洢���
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


//���ı���ʽд���ļ�
void WriteFileByTXT()
{
	//׼������
	int index[50];
	double x_pos[50], y_pos[50];
	for (int i = 0; i < 50; i++)
	{
		index[i] = i;
		x_pos[i] = rand() % 1000 * 0.01;
		y_pos[i] = rand() % 2000 * 0.01;
	}
	//д��txt
	FILE* fid = fopen("txt_out.txt", "w");//��д��ʽ��txt_out.txt
	if (fid == NULL)
	{
		printf("д���ļ�ʧ�ܣ�\n");
		return;
	}
	for (int i = 0; i < 50; i++)
	{
		fprintf(fid, "%03d\t%4.6lf\t%4.6lf\n", index[i], x_pos[i], y_pos[i]);
	}
	fclose(fid);
}


//�Զ����Ʒ�ʽд�ļ�
void WriteFileByData()
{
	//׼������
	double pos[200];
	for (int i = 0; i < 200; i++)
		pos[i] = i;
	//д������
	FILE* fid;
	fid = fopen("binary.txt", "wb");//�Զ����ơ�д��ʽ���ļ�
	if (fid == NULL)
	{
		printf("д���ļ�����");
		return;
	}
	int mode = 1;
	printf("modeΪ1�����д�룻modeΪ2������д��\n");
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


//�Զ����Ʒ�ʽ���ļ�
void ReadFileByData()
{
	FILE* fid;
	fid = fopen("binary.txt", "rb");
	if (fid == NULL)
	{
		printf("��ȡ�ļ�����");
		return;
	}
	int mode = 1;
	printf("modeΪ1��֪��pos�ж��ٸ���modeΪ2����֪��pos�ж��ٸ�\n");
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
		//��ȡ�ļ���С
		fseek(fid, 0, SEEK_END);
		long lSize = ftell(fid);
		rewind(fid);
		//���ٴ洢�ռ�
		int num = lSize / sizeof(double);
		double* pos = (double*)malloc(sizeof(double) * num);
		if (pos == NULL)
		{
			printf("���ٿռ����");
			return;
		}
		fread(pos, sizeof(double), num, fid);
		for (int i = 0; i < num; i++)
			printf("%lf\n", pos[i]);
		free(pos);     //�ͷ��ڴ�
	}
	fclose(fid);
}


int main()
{
	//���ı���ʽ�����ļ�
	printf("******���ı���ʽд�ļ�\n\n");
	WriteFileByTXT();
	printf("******���ı���ʽ���ļ�\n\n");
	ReadFileByTXT();

	//���ı���ʽ�����ļ�
	printf("******�Զ����Ʒ�ʽд�ļ�\n\n");
	writefilebydata();
	printf("******�Զ����Ʒ�ʽ���ļ�\n\n");
	readfilebydata();

	return 0;
}