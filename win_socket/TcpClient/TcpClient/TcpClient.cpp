#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include"winsock2.h"
#include<cstdlib>
#pragma comment(lib,"ws2_32.lib")


//st:要写入的字符串，n:要写入的长度
//当输入的长度到达n，或者遇到回车符时结束输入
char* s_fgets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);

	if (ret_val)
	{
		find = strchr(st, '\n');

		if (find)
		{
			*find = '\0';
		}
		else
		{
			//收掉命令行中多余的字符
			while (getchar() != '\n')
			{
				continue;
			}
		}

	}
	return ret_val;
}


int main()
{
	SOCKET client_socket;
	SOCKADDR_IN serv_add;
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	char sendbuf[100];
	char recvbuf[100];
	int ret;
	

	//初始化WSA
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		puts("初始化失败");
		return -1;
	}

	//创建客户端套接字
	client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket == INVALID_SOCKET)
	{
		puts("socket fail");
		return -1;
	}

	serv_add.sin_family = AF_INET;
	serv_add.sin_port = htons(8888);
	serv_add.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	if (connect(client_socket, (LPSOCKADDR)&serv_add, sizeof(serv_add)) == SOCKET_ERROR)
	{
		puts("connect error");
		return -1;
	}
	puts("connect success!");
	
	memset(sendbuf, 0, sizeof(sendbuf));
	sprintf(sendbuf, "hello i am client");
	ret = send(client_socket, sendbuf, strlen(sendbuf), 0);
	if (ret == SOCKET_ERROR)
	{
		printf("发送身份命令失败\n");
	}
	else {
		printf("发送身份命令成功\n");
	}

	if ((ret = recv(client_socket, recvbuf, 100, 0)) > 0)
	{
		recvbuf[ret] = '\0';
		fputs(recvbuf, stdout);
		printf("\n");
	}

	
	while (1)
	{

		memset(sendbuf, 0, sizeof(sendbuf));
		puts("plese entry command,Entry EOF Exit:");
		printf("client:");
		s_fgets(sendbuf, 100);
		if (strcmp(sendbuf, "EOF") == 0)
		{
			break;
		}
		else
		{
			send(client_socket, sendbuf, strlen(sendbuf), 0);
		}

		if ((ret = recv(client_socket, recvbuf, 100, 0)) > 0)
		{
			recvbuf[ret] = '\0';
			printf("server:");
			fputs(recvbuf, stdout);
			printf("\n");
		}

		
	}

	


	closesocket(client_socket);
	WSACleanup();

	return 0;
}