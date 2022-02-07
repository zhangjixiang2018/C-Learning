#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include"winsock2.h"
#include<cstdlib>
#pragma comment(lib,"ws2_32.lib")


//st:Ҫд����ַ�����n:Ҫд��ĳ���
//������ĳ��ȵ���n�����������س���ʱ��������
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
			//�յ��������ж�����ַ�
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
	SOCKET tcpServer;//�����socket
	SOCKADDR_IN addrServ;//���ڱ������˵�����ڵ���Ϣ
	SOCKET tcpClient;//
	SOCKADDR_IN addrClient;//���ڱ���ͻ��˵�����ڵ���Ϣ
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	char sendbuf[100];
	char recvbuf[100];

	//��ʼ��WSA
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		puts("��ʼ��ʧ��");
		return -1;
	}

	//�����׽���
	tcpServer = socket(AF_INET, SOCK_STREAM, 0);
	if (tcpServer == INVALID_SOCKET)
	{
		puts("socket error!");
		return -1;
	}

	//���а󶨲���
	addrServ.sin_family = AF_INET;//IPV4Э���
	addrServ.sin_port = htons(port);//�˿ڣ���С��ģʽת��Ϊ���ģʽ
	addrServ.sin_addr.S_un.S_addr = INADDR_ANY;//ip��ַ��INADDR_ANY��ʾ�󶨵�������������IP
	ret = bind(tcpServer, (LPSOCKADDR)&addrServ, sizeof(addrServ));
	if (ret == SOCKET_ERROR)
	{
		printf("����ʧ��:%d\n", WSAGetLastError());
		return -1;
	}

	//�󶨳ɹ������м���
	ret = listen(tcpServer, 10);
	if (ret == SOCKET_ERROR)
	{
		puts("socket listen failed");
		printf("����ʧ��:%d\n", WSAGetLastError());
		return -1;
	}

	
	addrClientLen = sizeof(SOCKADDR);

	while (true)
	{
		tcpClient = accept(tcpServer, (SOCKADDR*)&addrClient, &addrClientLen);
		if (tcpClient == SOCKET_ERROR) {
			printf("�ȴ�����ʧ��:%d", WSAGetLastError());
			break;
		}
		printf("�ͻ��˵�IP��:[%s]\n", inet_ntoa(addrClient.sin_addr));

		//��������
		memset(sendbuf, 0, sizeof(sendbuf));
		sprintf(sendbuf, "hello i'm TCPServer");
		ret = send(tcpClient, sendbuf, strlen(sendbuf), 0);
		if (ret == SOCKET_ERROR)
		{
			printf("����ʧ��");
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