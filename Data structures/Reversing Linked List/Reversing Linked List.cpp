/* Reversing Linked List.cpp 
Reverse a linked list class using a stack

*/

#include <iostream>

using namespace std;

class Node 
{
    int data;
    Node* next;
    friend class LinkedList;
    friend class Stack;
};

class LinkedList
{
    Node* head;
public:
    LinkedList() :head{ nullptr } {};
    Node* getHead() { return head; }
    void pushBack(const int& data);
    void revert(const int element, Node* app);
    void visita();
    friend class Stack;
};

class Stack
{
     int top;
     int capacity;
     int* array;
public:
    Stack(int capacity) {
        top = -1; this->capacity = capacity;
        array = new int[capacity];
    }
    void push(LinkedList& lista);
    int pop();
    bool isEmpty() { return top == -1; }
    friend class LinkedList;
};

void Stack::push(LinkedList& lista)
{
    Node* app;
    for (app = lista.head; app != nullptr; app = app->next)
        array[++top] = app->data;
}
int Stack::pop()
{
    return array[top--];
}


void LinkedList::pushBack(const int& data)
{
    Node* nuovoNodo = new Node;
    nuovoNodo->data = data;
    nuovoNodo->next = nullptr;
    Node* app;
    if (head == nullptr)
        head = nuovoNodo;
    else
    {
        for (app = head; app->next != nullptr; app = app->next);
        app->next = nuovoNodo;
    }

}
void LinkedList::revert(const int element, Node* app)
{ 
    app->data = element;
    app = app->next;

}



void LinkedList::visita()
{
    Node* app;
    for (app = head; app != nullptr; app = app->next)
        cout << app->data << endl;
}

int main()
{
    LinkedList lista;
    Node* app;
    Stack stack(20);
    lista.pushBack(1);
    lista.pushBack(2);
    lista.pushBack(3);
    lista.pushBack(4);
    app = lista.getHead();
    stack.push(lista);
    lista.visita();
    while (!stack.isEmpty())
    {
        lista.revert(stack.pop(), app);
    }
    lista.visita();

}

