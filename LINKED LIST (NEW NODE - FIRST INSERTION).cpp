
#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
	int data;
	struct node* next;
};

struct node *start = NULL, *ptr;
int val;

void display()
{
	ptr = start;

	while (ptr != NULL) {
		cout << ptr->data << "->";
		ptr = ptr->next;
	}

	cout << "NULL";
}

void createnode()
{
	cout << "input value to insert ";
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

void createnodebeg()
{
	cout << "input value to insert ";
	cin >> val;

	struct node* newnode =
	    (struct node*)malloc(sizeof(struct node));

	newnode->data = val;
	newnode->next = start;
	start = newnode;
}

int main()
{
	int n;

	cout << "Number of nodes ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		createnode();
	}

	cout << "Existing linked list is ";
	display();

	cout << "\nNow inserting a new value at first \n";
	createnodebeg();

	cout << "After insertion at first ";
	display();

	cout << "\nFreeing memory.....";
	ptr = start;

	while (ptr != NULL) {
		struct node* nextnode = ptr->next;
		free(ptr);
		ptr = nextnode;
	}

	start = NULL;
	return 0;
}
