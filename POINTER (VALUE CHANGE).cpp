#include <iostream>
using namespace std;
int main()
{	int a=10;
	int *p=&a;
	cout<<"the address of a is "<<p<<endl;
	cout<<"the value of a is "<<*p<<endl;
	*p=55;
	cout<<"the new value of a is "<<*p;
	return 0;
}
