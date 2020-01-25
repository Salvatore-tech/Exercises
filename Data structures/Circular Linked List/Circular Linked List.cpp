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
	void addFront(const char& data); // Inserisci un elemento dopo quello puntato dal cursore
	void remove(); // Rimuove il nodo subito dopo il cursore, cursor->next (MAYBE?)
	void visit();

	bool isEmpty() { return head == nullptr; }
	const char front(){return head->data;} // Ritorna il valore a cui punta il cursore (MAYBE?)
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
		tail->next = head;
	}
}

void CircularList::visit()
{
	Node* app;
	for (app = head; app != tail->next; app = app->next)
		cout << app->data << endl;
}




int main()
{
	CircularList c;
	c.addFront('a');
	c.addFront('b');
	c.addFront('e');
	c.visit();
	c.remove();
	c.visit();


}

