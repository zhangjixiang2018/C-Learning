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
	int port = 8888;
	int ret;
	int addrClientLen;
	SOCKET tcpServer;//服务端socket
	SOCKADDR_IN addrServ;//用于保存服务端的网络节点信息
	SOCKET tcpClient;//
	SOCKADDR_IN addrClient;//用于保存客户端的网络节点信息
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	char sendbuf[100];
	char recvbuf[100];

	//初始化WSA
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		puts("初始化失败");
		return -1;
	}

	//创建套接字
	tcpServer = socket(AF_INET, SOCK_STREAM, 0);
	if (tcpServer == INVALID_SOCKET)
	{
		puts("socket error!");
		return -1;
	}

	//进行绑定操作
	addrServ.sin_family = AF_INET;//IPV4协议簇
	addrServ.sin_port = htons(port);//端口，将小段模式转化为大端模式
	addrServ.sin_addr.S_un.S_addr = INADDR_ANY;//ip地址，INADDR_ANY表示绑定电脑上所有网卡IP
	ret = bind(tcpServer, (LPSOCKADDR)&addrServ, sizeof(addrServ));
	if (ret == SOCKET_ERROR)
	{
		printf("连接失败:%d\n", WSAGetLastError());
		return -1;
	}

	//绑定成功，进行监听
	ret = listen(tcpServer, 10);
	if (ret == SOCKET_ERROR)
	{
		puts("socket listen failed");
		printf("连接失败:%d\n", WSAGetLastError());
		return -1;
	}

	
	addrClientLen = sizeof(SOCKADDR);

	while (true)
	{
		tcpClient = accept(tcpServer, (SOCKADDR*)&addrClient, &addrClientLen);
		if (tcpClient == SOCKET_ERROR) {
			printf("等待请求失败:%d", WSAGetLastError());
			break;
		}
		printf("客户端的IP是:[%s]\n", inet_ntoa(addrClient.sin_addr));

		//发送数据
		memset(sendbuf, 0, sizeof(sendbuf));
		sprintf(sendbuf, "hello i'm TCPServer");
		ret = send(tcpClient, sendbuf, strlen(sendbuf), 0);
		if (ret == SOCKET_ERROR)
		{
			printf("发送失败");
			break;
		}

		if ((ret = recv(tcpClient, recvbuf, 100, 0)) > 0)
		{
			recvbuf[ret] = '\0';
			fputs(recvbuf, stdout);
			printf("\n");
			break;
		}
		
	}

	while (1)
	{
		if ((ret = recv(tcpClient, recvbuf, 100, 0)) > 0)
		{
			recvbuf[ret] = '\0';
			printf("client:");
			fputs(recvbuf, stdout);
			printf("\n");
		}

		memset(sendbuf, 0, sizeof(sendbuf));
		puts("plese entry command,Entry EOF Exit:");
		printf("server:");
		s_fgets(sendbuf, 100);
		if (strcmp(sendbuf, "EOF") == 0)
		{
			break;
		}
		else
		{
			send(tcpClient, sendbuf, strlen(sendbuf), 0);
		}
	}


	closesocket(tcpClient);
	closesocket(tcpServer);
	WSACleanup();
	return 0;
}