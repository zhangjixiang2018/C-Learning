#pragma once


template <typename T>
struct Node
{
	T t;
	struct Node* next;
};


template <typename T>
class LinkList
{
public:
	LinkList();

	~LinkList();

	void clear();

	int getLen();

	int insert(T& t, int pos);

	int del(int pos, T &t);

	int get(int pos, T& t);

private:
	int len;//链表长度
	Node<T> *header;//头节点
};

