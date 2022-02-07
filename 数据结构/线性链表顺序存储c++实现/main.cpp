#include<iostream>
#include"SeqList.cpp"

using  namespace std;

struct Teacher
{
	int age;
	char name[60];
};

void test01()
{
	Teacher t1, t2, t3, t4, t5, tmp;
	SeqList<Teacher> tList(10);
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;

	//�����Ա��ͷ������Ԫ��
	tList.insert(0, t1);
	tList.insert(0, t2);
	tList.insert(0, t3);
	tList.insert(0, t4);
	tList.insert(0, t5);

	//�������Ա�
	for (int i = 0; i < tList.getLen(); i++)
	{
		tList.get(i, tmp);
		cout << tmp.age << "  ";
	}
	cout << endl;

	//ɾ�����Ա��е�Ԫ��
	while (tList.getLen() > 0)
	{
		tList.del(0, tmp);
		cout << tmp.age << "  ";
	}
	cout << endl;


}

void test02()
{
	Teacher t1, t2, t3, t4, t5;
	Teacher *p1, *p2, *p3, *p4, *p5, *tmp;

	SeqList<Teacher*> tList(10);
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;

	//���������⣬�����Ͽ������� tList.insert(0, &t1);������������������
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;
	p4 = &t4;
	p5 = &t5;


	//�����Ա��ͷ������Ԫ��
	tList.insert(0, p1);
	tList.insert(0, p2);
	tList.insert(0, p3);
	tList.insert(0, p4);
	tList.insert(0, p5);

	//�������Ա�
	for (int i = 0; i < tList.getLen(); i++)
	{
		tList.get(i, tmp);
		cout << tmp->age << "  ";
	}
	cout << endl;

	//ɾ�����Ա��е�Ԫ��
	while (tList.getLen() > 0)
	{
		tList.del(0, tmp);
		cout << tmp->age << "  ";
	}
	cout << endl;


}


int main()
{
	//test01();
	test02();

	return 0;
}