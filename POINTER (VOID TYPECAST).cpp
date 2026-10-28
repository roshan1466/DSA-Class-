#include <iostream>
using namespace std;
int main()
{	int a=10;
	int *p=&a;
	void *po;
	cout<<"the address of a is "<<p<<endl;
	cout<<"the value of a is "<<*p<<endl;
	po=p;
	cout<<"the new value of a is "<<*(int*)po;
	return 0;
}
