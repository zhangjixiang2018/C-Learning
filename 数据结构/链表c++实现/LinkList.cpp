#include "LinkList.h"
#include<string.h>
#include<iostream>

using namespace std;

template <typename T>
LinkList<T> ::LinkList()
{
	this->header = new Node<T>;
	this->header->next = NULL;
	this->len = 0;

}

template <typename T>
LinkList<T> ::~LinkList()
{
	cout << "~LinkList()" << endl;
	T t;
	while (this->len > 0)
	{
		del(0, t);
	}

	delete this->header;
	

	
}

template <typename T>
void LinkList<T> ::clear()
{
	T t;
	while (this->len > 0)
	{
		del(0, t);
	}

	delete this->header;

	this->header = new Node<T>;
	this->header->next = NULL;
	this->len = 0;


}

template <typename T>
int LinkList<T> ::getLen()
{

	return this->len;
}

template <typename T>
int LinkList<T> ::insert(T& t, int pos)
{
	Node<T>* current;
	Node<T>* node = new Node<T>;

	if (node == NULL)
	{
		cout << "func LinkList insert err -2" << endl;
		return -2;
	}

	memset(node, 0, sizeof(Node<T>));

	if (pos < 0)
	{
		cout << "func LinkList insert err -1" << endl;
		return -1;
	}

	//�ݴ��������ĳ��ȴ�������ĳ��ȣ���������β�˲���
	if (pos > this->len)
	{
		pos = this->len;
	}


	node->t = t;//����t
	current = this->header;//currentָ��ͷ�ڵ�
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	node->next = current->next;//��node���Ӻ����ڵ�
	current->next = node;//��current�����½ڵ�

	this->len++;

	return 0;

}

//�������ܣ�ɾ������posλ�õĽڵ㣬�����ýڵ㻺����t��
template <typename T>
int LinkList<T> ::del(int pos, T& t)
{
	Node<T>* current = NULL;
	Node<T>* node = NULL;

	//ɾ��λ�ô���������
	if (pos >= len)
	{
		cout << "func listList del err,-1" << endl;
		return -1;
	}

	current = this->header;//currentָ��ͷ�ڵ�

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	node = current->next;//����Ҫɾ���Ľڵ�
	t = node->t;//����ɾ���ڵ��������

	current->next = node->next;//��ǰ�ڵ�����ɾ���ڵ�ĺ�һ���ڵ�

	delete node;//�ͷű�ɾ���ڵ�Ŀռ�

	this->len--;

	return 0;
}

template <typename T>
int LinkList<T> ::get(int pos, T& t)
{
	Node<T>* current = NULL;

	//��ȡλ�ô���������
	if (pos >= len)
	{
		cout << "func listList get err,-1" << endl;
		return -1;
	}

	current = this->header;//currentָ��ͷ�ڵ�

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	t = current->next->t;

	return 0;
}
