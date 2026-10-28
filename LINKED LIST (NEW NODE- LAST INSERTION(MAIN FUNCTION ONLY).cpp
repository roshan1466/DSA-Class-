
#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
	int data;
	struct node* next;
};

int main()
{
	struct node *start = NULL;
	struct node*ptr;
	int n, val;

	cout << "Number of nodes";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "insert node" << i + 1 << "value";
		cin >> val;

		struct node* newnode =
		    (struct node*)malloc(sizeof(struct node));

		newnode->data = val;
		newnode->next = NULL;

		if (start == NULL)
			start = newnode;
		else {
			ptr = start;

			while (ptr->next != NULL)
				ptr = ptr->next;

			ptr->next = newnode;
		}
	}

	cout << "Existing linked list is";
	ptr = start;

	while (ptr != NULL) {
		cout << ptr->data << "->";
		ptr = ptr->next;

		cout << "Value to insert at last";
		cin >> val;

		struct node*newnode =
		    (struct node*)malloc(sizeof(struct node));

		newnode->data = val;
		newnode->next = NULL;

		if (start == NULL)
			start = newnode;
		else {
			ptr = start;

			while (ptr->next != NULL)
				ptr = ptr->next;

			ptr->next = newnode;
		}
	

	cout << "After insertion at last";
	ptr = start;

	while (ptr != NULL)
	{
		cout << ptr->data << "->";
		ptr = ptr->next;
	}

	cout << "NULL"<<endl;
	cout << "Freeing memory...";

	ptr = start;

	while (ptr != NULL) {
		struct node* nextnode = ptr->next;
		free(ptr);
		ptr = nextnode;
	}

	start = NULL;
	return 0;
}}
