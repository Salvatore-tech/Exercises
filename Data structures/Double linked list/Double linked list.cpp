/* Double linked list.cpp : 

*/

#include <iostream>
using namespace std;

class Node 
{
	char data;
	Node* prev;
	Node* next;
	friend class Letter;
};

class Letter
{
	Node* head;
	Node* tail;
public:
	Letter() { head = tail = nullptr; }
	void pushFront(const char& data);
	void removeFront();
	void removeBack();
	void visit();
};

void Letter::pushFront(const char& data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->prev = newNode->next = nullptr;
	if (head == nullptr)
	{
		head = tail = newNode;
		tail->prev = tail;
	}
	else
	{
		newNode->next = head;
		head->next = head;
		head = newNode;
	}

}





void Letter::visit()
{
	Node* app;
	for (app = head; app != tail; app = app->next)
		cout << app->data << endl;
}



int main()
{
	Letter l;
	l.pushFront('c');
	l.pushFront('b');
	l.pushFront('a');
	l.visit();
}
