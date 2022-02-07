#include<iostream>

using namespace std;



int main()
{

	char* p = NULL;
	int* p1 = (int*)p;


	if (p1 == NULL)
	{
		cout << "NULL" << endl;
	}

	return 0;
}