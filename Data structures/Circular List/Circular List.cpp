#include <iostream>
using namespace std;

class Node
{
	char data;
	Node* next;
	friend class CircularList;
};

class CircularList
{
	Node* head;
	Node* tail;
public:
	CircularList() : head{ nullptr }, tail{ nullptr }{};
	void addFront(const char& data); 
	void addBack(const char& data);

	void visit();

	bool isEmpty() { return head == nullptr; }
	const char front() { return head->data; } // Ritorna il valore a cui punta il cursore (MAYBE?)
	const char back() { return tail->data; } // Ritorna il valore del nodo appena dopo il cursore
};

void CircularList::addFront(const char& data) // 
{
	Node* nuovoNodo = new Node;
	nuovoNodo->data = data;
	if (head == nullptr)
	{
		head = tail = nuovoNodo;
	}
	else
	{
		nuovoNodo->next = head;
		head = nuovoNodo;
		tail->next = head;
	}
}

void CircularList::addBack(const char& data)
{
	Node* nuovoNodo = new Node;
	nuovoNodo->data = data;
	nuovoNodo->next = nullptr;
	if (head == nullptr)
	{
		head = tail = nuovoNodo;
	}
	else
	{
		nuovoNodo->next = head;
		tail->next = nuovoNodo;
		tail = nuovoNodo;

		
	}
}


void CircularList::visit()
{
	Node* app;
	for (app = head->next; app->data != head->data; app = app->next)
		cout << app->data << endl;
}




int main()
{
	CircularList c;
	c.addFront('a');
	c.addFront('b');
	c.addFront('e');
	c.addBack('z');
	c.visit();




}

