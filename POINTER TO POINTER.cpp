#include<iostream>
using namespace std;

int main()
{
	int a=44;
	int *p=&a;
	int **q=&p;

	cout<<&a<<endl;
	cout<<"the address of a is "<<p<<endl;
	cout<<*q;

	return 0;
}
