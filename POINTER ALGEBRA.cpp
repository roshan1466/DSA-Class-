#include<iostream>
using namespace std;

int main()
{
	int arr[5]= {10,20,30,40,50};
	int *p=&arr[0];

	cout<<arr<<endl;
	cout<<p+1<<endl;
	cout<<p+2<<endl;
	cout<<*p+1<<endl;
	cout<<*(p+4)+6<<endl;

	return 0;
}
