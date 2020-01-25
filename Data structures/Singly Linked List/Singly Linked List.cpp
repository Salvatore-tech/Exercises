// Singly Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
using namespace std;

    

class Node
{
    string nome;
    int cfu;
    float media;
    int n_esami;
    Node* next;
    friend class Studente;
};

class Studente 
{
    Node* head;
public:
    Studente() { head = nullptr; };
    void pushFront(const string& nome, int cfu, int n_esami, float media);
    void pushBack(const string& nome, int cfu, int n_esami, float media);
    void removeBack();
    void removeFront();
    void print();
    bool empty() const;
};

bool Studente::empty() const
{
    return head == nullptr;
}
void Studente::pushFront(const string& nome, int cfu, int n_esami, float media)
{
    Node* newNode = new Node;
    newNode->nome = nome;
    newNode->cfu = cfu;
    newNode->n_esami = n_esami;
    newNode->media = media;
    newNode->next = head;
    head = newNode;

}

void Studente::pushBack(const string& nome, int cfu, int n_esami, float media)
{
    Node* newNode = new Node;
    Node* app;
    newNode->nome = nome;
    newNode->cfu = cfu;
    newNode->n_esami = n_esami;
    newNode->media = media;
    newNode->next = nullptr;
    for (app = head; app->next != nullptr; app = app->next);
    app->next = newNode;

}


void Studente::removeFront() 
{
    if (!empty())
    {
        Node* app = head;
        head = app->next;
        delete app;
    }
}

void Studente::removeBack()
{
    Node* app;
    for (app = head; app->next->next != nullptr; app = app->next);
    app->next = nullptr;
}


void Studente::print()
{
    for (Node* app = head; app!=nullptr; app = app->next)
        cout << app->nome << "\t" << app->n_esami << "\t" << app->cfu << "\t" << app->media << endl;
}
int main()
{
    Studente s;
    for (int i = 0; i < 5; i++)
      s.pushFront(string("Giuseppe"), 10 + i, i, 19.20 + i);

    s.print();

    for (int i = 0; i < 5; i++)
        s.pushBack(string("Salvatore"), 10 + i, i, 19.20 + i);
    
    s.print();
    s.removeBack();
    cout << "\nRemoving an element from the back of the list" << endl;
    s.print();
} 

