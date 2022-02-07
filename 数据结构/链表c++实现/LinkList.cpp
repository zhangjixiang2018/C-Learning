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

	//容错，如果插入的长度大于链表的长度，则在链表尾端插入
	if (pos > this->len)
	{
		pos = this->len;
	}


	node->t = t;//保存t
	current = this->header;//current指向头节点
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	node->next = current->next;//让node连接后续节点
	current->next = node;//让current连接新节点

	this->len++;

	return 0;

}

//函数功能：删除链表pos位置的节点，并将该节点缓存在t中
template <typename T>
int LinkList<T> ::del(int pos, T& t)
{
	Node<T>* current = NULL;
	Node<T>* node = NULL;

	//删除位置大于链表长度
	if (pos >= len)
	{
		cout << "func listList del err,-1" << endl;
		return -1;
	}

	current = this->header;//current指向头节点

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	node = current->next;//缓存要删除的节点
	t = node->t;//缓存删除节点的数据域

	current->next = node->next;//当前节点连接删除节点的后一个节点

	delete node;//释放被删除节点的空间

	this->len--;

	return 0;
}

template <typename T>
int LinkList<T> ::get(int pos, T& t)
{
	Node<T>* current = NULL;

	//获取位置大于链表长度
	if (pos >= len)
	{
		cout << "func listList get err,-1" << endl;
		return -1;
	}

	current = this->header;//current指向头节点

	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}

	t = current->next->t;

	return 0;
}
