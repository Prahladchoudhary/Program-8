#include <iostream>
using namespace std;

struct Node
{
	Node(){};
	Node( string n, int a )
	{
		name = n;
		age = a;
		next = NULL;
	}
	string name;
	int age;
	Node *next;
};

class List
{
	Node *first;

	public:

	List()
	{
		first = NULL;
	}

	void Add(string name, int age) 
	{
		Node *newNode = new Node(name, age);
		Node *curNode = first;


		if( curNode == NULL )
		{
			first = newNode;
			return;
		}

		while(curNode->next != NULL)
		{
			curNode = curNode->next;
		}
		curNode->next = newNode;
	}

	void Change(string name) 
	{
		Node *curNode = first;
		bool found = false;

		if( curNode == NULL )
			return;

		if( curNode->name == name )
			found = true;

		while(curNode->next != NULL || found != true)
		{
			curNode = curNode->next;
			if( curNode->name == name )
				found = true;
		}

		if( found == false )
			return;

		cout << "What would you like " << curNode->name << "'s new age to be? (currently " << curNode->age << ")" << endl;
		cin >> curNode->age;
		cout << endl;

	}

	void Print() 
	{
		Node *curNode = first;

		if( curNode == NULL )
			return;
		cout << curNode->name << " " << curNode->age << endl;
		while(curNode->next != NULL)
		{
			curNode = curNode->next;
			cout << curNode->name << " " << curNode->age << endl;
		}
		cout << endl;
	}
};


int main()
{
	List people;
	people.Add("Prahlad", 20);
	people.Add("SK", 18);
	people.Print();
	people.Change("JP");
	people.Print();
    return 0;
}