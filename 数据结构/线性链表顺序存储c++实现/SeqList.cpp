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

	//��������λ��С��0
	if (pos < 0 || pos > this->capacity || this->len == this->capacity)
	{
		ret = -1;
		cout << "func SeqList<T>::insert() err.-1";
		return ret;
	}

	//��������λ�ô������Ա�ĳ��ȣ��������Ա��β������
	if (pos > this->len)
	{
		pos = this->len;
	}

	//��Ԫ�غ���
	for (i = this->len; i > pos; i--)
	{
		this->pArray[i] = this->pArray[i - 1];
	}

	//����Ԫ��
	this->pArray[i] = t;//stlԪ�ر�����ͨ�����ƵĻ���ʵ�ֵģ������Ҫ���Ը��Ʋ��У�(���)

	this->len++;
	return ret;
}

template <typename T>
int SeqList<T>::get(int pos, T& t)
{
	int ret = 0;
	int i = 0;

	//��������λ��С��0
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

	//���ɾ����λ��С��0
	if (pos < 0 || pos>this->len)
	{
		ret = -1;
		cout << "func SeqList<T>::del() err.-1";
		return ret;
	}

	t = this->pArray[pos];//����ɾ���Ľڵ�

	//��Ԫ��ǰ�ƣ����Ǳ�ɾ���Ľڵ�
	for (i = pos+1; i < this->len; i++)
	{
		this->pArray[i-1] = this->pArray[i];
	}

	this->len--;
	return ret;
}
