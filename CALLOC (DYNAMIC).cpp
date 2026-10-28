include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int n;

	cout << "Enter number of students";
	cin >> n;

	int *arr = (int *)calloc(n, sizeof(int));

	if (arr == NULL) {
		cout << "Overflow";
		return 0;
	}

	cout << "Enter " << n << " marks";

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum = sum + arr[i];
	}

	cout << "Total" << sum;

	free(arr);

	return 0;
}
