#pragma once

template <typename T>
class SeqList
{
public:
	SeqList(int capacity);

	~SeqList();

	int getLen();

	int getCapacity();

	int insert(int pos, T &t);

	int get(int pos, T &t);

	int del(int pos, T &t);

private:
	int len;
	int capacity;
	T *pArray ; //int* node[]  Ö¸ÕëÊı×é
};

