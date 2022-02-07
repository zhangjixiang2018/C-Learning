#include<iostream>
#include"LinkList.cpp"

using namespace std;

struct Teacher
{
	int age;
	char name[64];
};

int main()
{
	LinkList<Teacher> mylist;

	Teacher t1, t2, t3, t4, t5;
	t1.age = 1;
	t2.age = 2;
	t3.age = 3;
	t4.age = 4;
	t5.age = 5;

	mylist.insert(t1, 0);
	mylist.insert(t2, 0);
	mylist.insert(t3, 0);
	mylist.insert(t4, mylist.getLen());
	mylist.insert(t5, mylist.getLen());
	//3 2 1 4 5

	Teacher tmp;
	for (int i = 0; i < mylist.getLen(); i++)
	{
		mylist.get(i, tmp);
		cout << tmp.age << "	" ;
	}

	cout << endl;

	//Î²É¾
	mylist.del(mylist.getLen()-1, tmp);
	cout << tmp.age << "	" << endl;//5

	mylist.del(2, tmp);
	cout << tmp.age << "	" << endl;//1

	//É¾³ıÔªËØ
	while(mylist.getLen()>0)
	{
		mylist.del(0, tmp);
		cout << tmp.age << "	" ;//3 2 4
	}
	cout << endl;


	mylist.insert(t1, 0);
	mylist.insert(t2, 0);
	mylist.insert(t3, 0);
	mylist.insert(t4, mylist.getLen());
	mylist.insert(t5, mylist.getLen());

	mylist.clear();

	mylist.insert(t1, 0);
	mylist.insert(t2, 0);
	mylist.insert(t3, 0);
	mylist.insert(t4, mylist.getLen());
	mylist.insert(t5, mylist.getLen());

	//É¾³ıÔªËØ
	while (mylist.getLen() > 0)
	{
		mylist.del(0, tmp);
		cout << tmp.age << "	";//3 2 4
	}
	cout << endl;


	return 0;
}

