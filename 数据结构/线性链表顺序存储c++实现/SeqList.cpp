#include "SeqList.h"
#include<iostream>

using namespace std;

template <typename T>
SeqList<T>::SeqList(int cap)
{
	pArray = new T[cap];
	this->capacity = cap;
	this->len = 0;

}

template <typename T>
SeqList<T>::~SeqList()
{
	delete[] pArray;
	pArray = NULL;
	this->capacity = 0;
	this->len = 0;
}

template <typename T>
int SeqList<T>::getLen()
{

	return this->len;
}

template <typename T>
int SeqList<T>::getCapacity()
{

	return this->capacity;
}

template <typename T>
int SeqList<T>::insert(int pos, T& t)
{
	int ret = 0;
	int i = 0;

	//如果插入的位置小于0
	if (pos < 0 || pos > this->capacity || this->len == this->capacity)
	{
		ret = -1;
		cout << "func SeqList<T>::insert() err.-1";
		return ret;
	}

	//如果插入的位置大于线性表的长度，则在线性表的尾部插入
	if (pos > this->len)
	{
		pos = this->len;
	}

	//将元素后移
	for (i = this->len; i > pos; i--)
	{
		this->pArray[i] = this->pArray[i - 1];
	}

	//插入元素
	this->pArray[i] = t;//stl元素保存是通过复制的机制实现的，你的类要可以复制才行，(深拷贝)

	this->len++;
	return ret;
}

template <typename T>
int SeqList<T>::get(int pos, T& t)
{
	int ret = 0;
	int i = 0;

	//如果插入的位置小于0
	if (pos < 0 || pos>this->len)
	{
		ret = -1;
		cout << "func SeqList<T>::insert() err.-1";
		return ret;
	}

	t = this->pArray[pos];

	return ret;
}

template <typename T>
int SeqList<T>::del(int pos, T& t)
{
	int ret = 0;
	int i = 0;

	//如果删除的位置小于0
	if (pos < 0 || pos>this->len)
	{
		ret = -1;
		cout << "func SeqList<T>::del() err.-1";
		return ret;
	}

	t = this->pArray[pos];//缓冲删除的节点

	//将元素前移，覆盖被删除的节点
	for (i = pos+1; i < this->len; i++)
	{
		this->pArray[i-1] = this->pArray[i];
	}

	this->len--;
	return ret;
}
