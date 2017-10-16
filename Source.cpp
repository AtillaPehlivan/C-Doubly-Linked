#include <iostream>
#include<iomanip>
using namespace std;
typedef struct list
{
	int value;
	struct list *prev;
	struct list *next;
}element;

element *head = NULL;
element *last = NULL;

void insertBack(int value);
void display();
void insertion(int position, int value);
void remove(int value);
void deleteByPosition(int position);
void deleteFirst();
void deleteLast();
void listReverse();
void divideList(int position);
void menu();
int listSize = 0;
int main()
{
	do
	{
		menu();
	} while (true);

	system("pause");
	return 0;
}
void insertBack(int value)
{
	list* tmp = new list();
	tmp->value = value;
	if (last == NULL)
	{
		head = tmp;
		last = tmp;
		listSize++;
		cout << setw(5) << value << " Added To The List " << endl;
	}
	else
	{
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
		last = tmp;
		listSize++;
		cout << setw(5) << value << " Added To The List " << endl;
	}
}

void display()
{
	list* tmp = head;
	cout << setw(5) << "----List----" << endl;
	while (tmp != NULL)
	{
		cout << tmp->value << " -> ";
		tmp = tmp->next;
	}
	cout << endl << "------------" << endl;
}

void insertion(int position, int value)
{

	if (position > listSize && position < 0)
	{
		cout << "Length Of list Not Enough " << endl;
	}
	else if (position == listSize)
	{
		insertBack(value);
	}
	else if (position == 0)
	{
		list *tmp = new list;
		tmp->value = value;
		head->prev = tmp;
		tmp->next = head;
		tmp->prev = NULL;
		head = tmp;
		listSize++;
		cout << setw(5) << value << " Added To The List With Position " << position << endl;
	}
	else if (position > 0 && position < listSize)
	{
		list* tmp = new list;
		list* tmphead = head;
		tmp->value = value;
		for (size_t i = 0; i < position; i++)
		{
			tmphead = tmphead->next;
		}
		tmp->next = tmphead;
		tmp->prev = tmphead->prev;
		tmphead->prev->next = tmp;
		tmphead->prev = tmp;
		listSize++;
		cout << setw(5) << value << " Added To The List With Position " << position << endl;
	}
	else
	{
		cout << setw(5) << "Invalid Poistion" << endl;
	}
}

void remove(int value)
{
	list* tmp = head;
	int position = 0;
	if ((last && head) != NULL)
	{
		while (tmp != NULL)
		{
			if (tmp->value == value)
			{
				tmp = tmp->next;
				deleteByPosition(position);
				position--;
				cout << setw(5) << value << " Deleted From List" << endl;
			}
			else
			{
				tmp = tmp->next;
			}

			position++;
		}
	}
}
void deleteByPosition(int position)
{
	list* tmp = head;
	for (int i = 0; i < position&& tmp != NULL; i++)
	{
		tmp = tmp->next;
	}
	if (position == 0)
	{
		deleteFirst();
	}
	else if (tmp == last)
	{
		deleteLast();
	}
	else if (tmp != NULL)
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		delete(tmp);
		listSize--;
	}
}
void deleteFirst()
{
	if (listSize==1)
	{
		head = NULL;
		last = NULL;
		cout << setw(5)<<setfill('*') << "Stack is Empty" << endl;
	}
	else
	{
		list* tmp = head;
		head = head->next;
		head->prev = NULL;
		delete(tmp);
		cout << setw(5) << "First List Deleted" << endl;
		listSize--;
	}
	
}
void deleteLast()
{
	list* tmp = last;
	last = last->prev;
	last->next = NULL;
	delete(tmp);
	cout << setw(5) << "Last List Deleted" << endl;
	listSize--;
}
void listReverse()
{
	list * tmp = last;
	while (tmp != NULL)
	{
		cout << tmp->value << " -> ";
		tmp = tmp->prev;
	}
	cout << endl;
}
void divideList(int position)
{
	if (position == 0 || position == listSize)
	{
		cout << "Invalid Position" << endl;
	}
	else if (position > 0 && position < listSize)
	{
		int count = 0;
		list* tmp = head;
		cout << "1. First List : ";
		while (tmp != NULL)
		{
			if (count > position)
			{
				cout << tmp->value << " -> ";
			}
			else if (count < position)
			{
				cout << tmp->value << " -> ";
			}
			else if (count == position)
			{
				cout << endl << "2. Second List : " << tmp->value << " -> ";
			}
			tmp = tmp->next;
			count++;
		}
		int choice = 0;
		cout << endl<<"Please Select First or Second List : ";
		cin >> choice;
		int state1 = listSize - position;
		if (choice==2)
		{
			for (int i = 0; i < position; i++)
			{
				deleteByPosition(0);
			}
		}
		else
		{
			for (int i = 0; i <= state1; i++)
			{
				deleteByPosition(position);
			}
		}
	}
	cout << endl;
}

void menu()
{
	int choice, value, position;
	cout << setw(10) << "----Menu----" << endl
		<< "1. Insert" << endl
		<< "2. Insertion" << endl
		<< "3. Delete" << endl
		<< "4. Divide By Position" << endl
		<< "5. List" << endl
		<< "6. Count" << endl
		<< "7. Random 10 Number to Add The list" << endl
		<< "Please Choice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Please an Integer Number : ";
		cin >> value;
		insertBack(value);
		break;
	case 2:
		cout << "Please an Integer Number : ";
		cin >> value;
		cout << "Please Enter Position : ";
		cin >> position;
		insertion(position, value);
		break;
	case 3:
		cout << "Please Enter The Number to Delete : ";
		cin >> value;
		remove(value);
		break;
	case 4:
		cout << "Please Enter Position : ";
		cin >> value;
		divideList(value);
		break;
	case 5:
		display();
		listReverse();
		break;
	case 6:
		cout << endl << listSize << endl;
		break;
	case 7:
		srand(time(NULL));
		for (int i = 0; i < 10; i++)
		{
			insertBack(rand() % 100);
		}
		display();
		break;
	default:
		break;
	}
}
